/*
ID:ghaziab1
PROG:node
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

set<int > nodes;
vector<pair<int,int> > arcList;
int nc;

int BFS(int node,int TTL)
{
    map<int,bool> vis;
    for (set<int>::iterator it=nodes.begin();it!=nodes.end();++it)
        vis[*it]=false;

    queue<int > q;
    q.push(node);
    vis[node]=true;
    while(!q.empty() && TTL!=0)
    {
        int sz= q.size();
        while(sz--)
        {
            int cur=q.front();
            q.pop();
            for (int i=0;i<arcList.size();++i)
                {
                    if(arcList[i].first==cur && !vis[arcList[i].second])
                        {
                            q.push(arcList[i].second);
                            vis[arcList[i].second]=true;
                        }
                    if(arcList[i].second==cur && !vis[arcList[i].first])
                        {
                            q.push(arcList[i].first);
                            vis[arcList[i].first]=true;
                        }
                }

        }
        TTL--;
    }

    int notvisited=0;
    for(map<int,bool>::iterator it=vis.begin();it!=vis.end();++it )
        if(!(*it).second) notvisited++;

    return notvisited;

}


int main()
{
    int cas=0;
    while(true)
    {


        cin>>nc;
        if(nc==0) break;

        for (int i=0;i<nc;++i)
        {
            int a,b;
            cin >> a >> b;
            arcList.push_back(make_pair(a,b));
            nodes.insert(a);
            nodes.insert(b);
        }

        while(true)
        {
            int startingNode,ttl;
            cin >> startingNode >> ttl;
            if(startingNode==0 && ttl==0) break;



            cas++;
            cout << "Case " << cas << ": " << BFS(startingNode,ttl) << " nodes not reachable from node " << startingNode << " with TTL = " << ttl << "."<<endl;




        }

        arcList.clear();
        nodes.clear();

    }








    return 0;
}
