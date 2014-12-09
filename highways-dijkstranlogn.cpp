#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


#define pb push_back
#define mp make_pair

int n, m;
vector<vector<pair<int, int > > >adj;
const int MX = 100009, oo = 1<<28;
int dist[MX], vis[MX];
int dijkstra(int s, int d) {

	fill(dist, dist+n+2, oo);
	dist[s]=0;
	memset(vis, 0, sizeof vis);
	priority_queue<pair<int, int > >q;
	q.push(mp(0, s));
	while(!q.empty()) {

		pair<int, int >cur = q.top();
		q.pop();
		if(vis[cur.second])
			continue;
		vis[cur.second]=1;
		if(cur.second == d)
			return -cur.first;
		for (int i = 0; i < (int)adj[cur.second].size(); ++i)
		{
			if(dist[cur.second] + adj[cur.second][i].second < dist[adj[cur.second][i].first]) {

				dist[adj[cur.second][i].first] = dist[cur.second] + adj[cur.second][i].second;
				q.push(mp(-dist[adj[cur.second][i].first], adj[cur.second][i].first));
			}
		}
	}

	return -1;
}
int main() {

	int t;scanf("%d", &t);
	while(t--)  {
		int s, d;
		scanf("%d%d%d%d", &n, &m, &s, &d);
		adj = vector<vector<pair<int, int > > >(n);
		--s, --d;
		int from, to, cost;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &from, &to, &cost);
			--from, --to;
			adj[from].pb(mp(to, cost));
			adj[to].pb(mp(from, cost));
		}
		int ans = dijkstra(s, d);
		if(ans == -1)
			printf("NONE\n");
		else printf("%d\n", ans);
	}
	return 0;
}