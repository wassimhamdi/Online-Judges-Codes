#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
vector<vector<pair<int, int > > > adj;
const int MX = 100009;
int dist[MX];
int n;
const int oo = 1<<28;
int dijkstra(int s, int d) {
	fill(dist, dist+n, oo);
	dist[s]=0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > >q;
	q.push(mp(0, s));
	while(!q.empty()) {
		pair<int, int >cur = q.top();
		q.pop();
		if(cur.first != dist[cur.second])
			continue;
		if(cur.second == d)
			return cur.first;
		int csrc = dist[cur.second];
		
		for (int i = 0; i < (int)adj[cur.second].size(); ++i)
		{
			int &cdst = dist[adj[cur.second][i].first];
			int ecst = adj[cur.second][i].second;

			if(csrc + ecst < cdst )
				cdst = csrc + ecst, q.push(mp(cdst, adj[cur.second][i].first));
		}
	}
	return -1;
}
int main() {

	int m, s, d, t;
	scanf("%d", &t);
	while(t-- ) {
		scanf("%d%d%d%d", &n, &m, &s, &d);
		--s, --d;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < m; ++i)
		{
			int from, to, tim;
			scanf("%d%d%d", &from, &to, &tim);
			--from, --to;
			adj[from].pb(mp(to, tim));
			adj[to].pb(mp(from, tim));

		}
		int r = dijkstra(s, d);
		if(r == -1) 
			printf("NONE\n");
		else printf("%d\n", r);
		
	}
	return 0;
}