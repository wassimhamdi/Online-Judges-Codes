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
vector<pair<int, int> > edges;
int parrent[MX];
int MST(int s) {

	fill(dist, dist+n+2, oo);
	dist[s]=0;
	memset(vis, 0, sizeof vis);
	priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > >q;
	q.push(mp(0, s));
	int ret = 0;
	while(!q.empty()) {

		pair<int, int >cur = q.top();
		q.pop();
		if(vis[cur.second])
			continue;
		ret+=cur.first;
		edges.pb(mp(parrent[cur.second], cur.second));
		vis[cur.second]=1;
		for (int i = 0; i < (int)adj[cur.second].size(); ++i)
		{
			if(/*dist[cur.second] + */adj[cur.second][i].second < dist[adj[cur.second][i].first]) {

				dist[adj[cur.second][i].first] = /*dist[cur.second] +*/ adj[cur.second][i].second;
				parrent[ adj[cur.second][i].first] = cur.second;
				q.push(mp(dist[adj[cur.second][i].first], adj[cur.second][i].first));
			}
		}
	}

	return ret;
}