#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define mp make_pair
#define pb push_back

const int MX=1009, oo = 1<<28;
int n,m,ret;
vector<vector<pair<int, int > > > adj;
int dist[MX], vis[MX];
vector< pair<int,int> > edges;
int parent[MX];
	/*	FAUX PAS BESOIN DIJ ARC SUFFIT			int arm(int d){
	
		fill(lng,lng+n+2,oo);
		lng[0]=0;
		memset(vu, 0, sizeof vu);
		priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > >q;
		q.push(mp(0, s));
		while(!q.empty()) {

			pair<int, int >cour = q.top();
			q.pop();
			if(vu[cour.second])
				continue;
			vu[cour.second]=1;
			if(cour.second == n)
				return cour.first;
			for (int i = 0; i < (int)adj[cour.second].size(); ++i)
			{
				if(lng[cour.second] + adj[cour.second][i].second < lng[adj[cour.second][i].first]) {

					lng[adj[cour.second][i].first] = lng[cour.second] + adj[cour.second][i].second;
					q.push(mp(lng[adj[cour.second][i].first], adj[cour.second][i].first));
				}
			}
		}
	return 0;
	}*/
	int MST (int s) {

	fill(dist, dist+n+2, oo);
	dist[s]=0;
	memset(vis, 0, sizeof vis);
	priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > >q;
	q.push(mp(0, s));
	ret=0;
	while(!q.empty()) {

		pair<int, int >cur = q.top();
		q.pop();
		if(vis[cur.second])
			continue;
		ret+=cur.first;
		edges.pb(mp(parent[cur.second],cur.second));
		vis[cur.second]=1;
		/*if(cur.second == d)
			return cur.first;*/
		for (int i = 0; i < (int)adj[cur.second].size(); ++i)
		{
			if(/*dist[cur.second] + */adj[cur.second][i].second < dist[adj[cur.second][i].first]) {

				dist[adj[cur.second][i].first] = /*dist[cur.second] +*/ adj[cur.second][i].second; //On cherche la distance min par rapport à l'arbre et non absolu, moins de contraintes
				parent[adj[cur.second][i].first];
				q.push(mp(dist[adj[cur.second][i].first], adj[cur.second][i].first));
			}
		}
	}
	return ret;
}


	int main(){
		int t,p;
		cin>>t;
		while(t--){
		// DON'T FORGET THE PRICE
			cin>>p>>n>>m;
			adj=vector<vector<pair<int,int > > > (n+1);
			int a,b,c;
			for(int i=0;i<m;++i){
				cin>>a;
				cin>>b;
				cin>>c;
				adj[a].pb(mp(b, c));
				adj[b].pb(mp(a, c));
			}
			int dist=MST(1);
			dist*=p;
			cout<<dist<<endl;
		
			
		}
	
	
	return 0;
	}