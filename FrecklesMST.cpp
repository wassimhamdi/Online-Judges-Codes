#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>   
using namespace std;


#define pb push_back
#define mp make_pair


int n, m;
vector<vector<pair<int, double > > >adj;
const int MX = 109, oo = 1<<28;
double dist[MX];
int vis[MX];
vector<pair<int, int> > edges;
int parrent[MX];
double MST(int s) {

	fill(dist, dist+n+2, oo);
	dist[s]=0;
	memset(vis, 0, sizeof vis);
	priority_queue<pair<double, int >, vector<pair<double, int> >, greater<pair<double, int > > >q;
	q.push(mp(0, s));
	double ret = 0;
	while(!q.empty()) {

		pair<double, int >cur = q.top();
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


double xs[MX], ys[MX];
int main() {

	int t;
	cin>>t;
	bool flg = false;
	while(t--) {
		if(flg)
			printf("\n");
		flg = true;

		cin>>n;
		adj = vector<vector<pair<int, double > > >(n);
		for (int i = 0; i < n; ++i)
			cin>>xs[i]>>ys[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(i == j)
					continue;
				// edges.pb(edge(i, j, hypot(xs[i]-xs[j], ys[i]-ys[j])));
				adj[i].pb(mp(j, hypot(xs[i]-xs[j], ys[i]-ys[j])));
			}
		}
		double ans = MST(0);
		printf("%.2lf\n", ans);
	}
	return 0;
}







