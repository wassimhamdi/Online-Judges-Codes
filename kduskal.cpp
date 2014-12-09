#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
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
	int from, to, cost;
	edge(int _from, int _to, int _cost) {
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
int kruskal(int n) {

	disjointSet sets(n);
	sort(edges.begin(), edges.end());
	int cost = 0;
	for (int i = 0; i < (int)edges.size(); ++i)
	{
		if(sets.merge(edges[i].from, edges[i].to)) {
			cost+=edges[i].cost;
			mst.pb(edges[i]);
		}
	}
	return cost;

}

int main() {

	return 0;
}
