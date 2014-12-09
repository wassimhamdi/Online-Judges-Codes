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

	vector<int > par, rank;
	int nComp;
	disjointSet(int n) {
		par = vector<int > (n);
		rank = vector<int > (n, 0);
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
	double cost;
	edge(int _from, int _to, double _cost) {
		from = _from;
		to = _to;
		cost = _cost;
	}
	bool operator<(const edge &e) const{
		return e.cost>cost;
	}
};
vector<edge> mst;
vector<edge> edges;
double kruskal(int n) {

	disjointSet sets(n);
	sort(edges.begin(), edges.end());
	double cost = 0;
	for (int i = 0; i < (int)edges.size(); ++i)
	{
		if(sets.merge(edges[i].from, edges[i].to)) {
			cost+=edges[i].cost;
			mst.pb(edges[i]);
		}
	}
	return cost;

}
const int MX = 109;
double xs[MX], ys[MX];
int main() {

	int i,t,n,m,A,B;
	double p,C;
	cin>>t;
	while(t--) {
        cin>>p;
        cin>>n;
        cin>>m;

		edges.clear();
		mst.clear();

		for (i=0;i<m;i++){
    cin>>A;
    cin>>B;
    cin>>C;
    C=p*C;
    edges.pb(edge(A, B, C));
}
//		for (i=0;i<m;i++){
//    printf("edge %d=from %d to %d cost is %d \n",i,edges[i].from,edges[i].to,edges[i].cost);
//}

		double ans = kruskal(n);
		printf("%d\n", (int)ans);


	}
	return 0;
}
