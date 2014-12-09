#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


#define pb push_back
#define mp make_pair

vector<vector<pair<int, int > > > adj;
int n, m;
const int MX = 100009;
const int oo = 1<<28;
int dist[MX], vis[MX];
int dijkstra(int s, int d) {
	fill(dist, dist+n+2, oo);
	memset(vis, 0, sizeof vis);
	dist[s] = 0;
	// vis[s] = 1;
	for (int i = 0; i < n; ++i)
	{
		int mnDist = oo, midx=-1;
		for (int j = 0; j < n; ++j) {
			// cerr<<curTo<<" "<<vis[curTo]<<" "<< dist[curTo]<< " " << mnDist<<endl;
			if(!vis[j] && dist[j] < mnDist)
				mnDist = dist[j], midx = j;
		}
		// cerr<<"Midx "<<midx<< " "<< mnDist<< endl;
		if(midx == -1)
			continue;
		vis[midx] = 1;
		for (int j = 0; j < (int)adj[midx].size(); ++j)
		{
			int curTo = adj[midx][j].first;
			dist[curTo] = min(dist[curTo], dist[midx] + adj[midx][j].second);
		}
	}
	return dist[d];

}
int main() {

	int t;scanf("%d", &t);
	while(t--) {
		int s, d;
		scanf("%d%d%d%d", &n, &m, &s, &d);
		--s, --d;
		adj = vector<vector<pair<int, int > > >(n);
		for (int i = 0; i < m; ++i)
		{
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			--from, --to;
			adj[from].pb(mp(to, cost));
			adj[to].pb(mp(from, cost));
		}
		int ans = dijkstra(s, d);
		if(ans>=oo)
			printf("NONE\n");
		else printf("%d\n", ans);

	}
	return 0;
}