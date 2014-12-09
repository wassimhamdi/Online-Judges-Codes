#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair

struct disjointSet{

	vector<int> par, rank;
	int nComp;
	disjointSet(int n) {
		par = vector<int >(n);
		rank = vector<int >(n, 0);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i;
		}
		nComp = n;
	}


	int find(int id) {
		if(id == par[id])
			return id;
		return par[id] = find(par[id]);
	}


	bool merge(int id1, int id2) {
		int p1 = find(id1);
		int p2 = find(id2);
		if(p1==p2) {
			return false;
		}
		if(rank[p1] > rank[p2]) {
			par[p2]=p1;
		}
		else if(rank[p1] < rank[p2]) {
			par[p1] = p2;
		}
		else {
			par[p1] = p2;
			rank[p2]++;
		}
		nComp--;
		return true;
	}
};


struct edge
{
	int from, to;
	edge(int _from, int _to) {
		from = _from;
		to = _to;
	}
	};


vector<edge> mst;
vector<edge> edges;
int freq[30009];
int main() {

	int n,m,A,B,t,tc,i,k,j,flag;
	cin>>t;
	for (tc=0;tc<t;tc++){
    edges.clear();
    mst.clear();

    memset(freq,0,sizeof(freq));
	cin>>n;
	cin>>m;

for (i=0;i<m;i++){
cin>>A;
cin>>B;
edges.pb(edge(A, B));
}

disjointSet sets(max(m,n));
	for(int i = 0; i<m; i++){
		if(sets.merge(edges[i].from, edges[i].to)) {
			mst.pb(edges[i]);
		}
	}


for (i=0;i<n;i++){
freq[sets.find(i)]+=1;}

k=0;
for (i=0;i<n;i++){
if(freq[i]>k){k=freq[i];}}

printf("%d\n",k);
	}
	return 0;
}
