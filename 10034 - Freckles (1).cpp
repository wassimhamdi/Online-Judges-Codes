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

	int t, n;
	cin>>t;
	bool flg = false;
	while(t--) {
		if(flg)
			printf("\n");
		flg = true;
		edges.clear();
		mst.clear();
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>xs[i]>>ys[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(i == j)
					continue;
				edges.pb(edge(i, j, hypot(xs[i]-xs[j], ys[i]-ys[j])));
			}
		}
		double ans = kruskal(n);
		printf("%.2lf\n", ans);
	}
	return 0;
}