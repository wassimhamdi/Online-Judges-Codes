#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define N 1000000
using namespace std;

bool graph [30 + 3] [30 + 3];



int main ()
{
    int edges;
    int cases = 0;

    while ( cin >> edges && edges ) {
        for ( int i = 0; i < 33; i++ )
        memset (matrix [i], false, sizeof (matrix [i]));

        map <int, int> index;
        int nodeNumber = 1;

        for ( int i = 0; i < edges; i++ ) {
            int a, b;
            cin >> a >> b;
            if ( !index [a] ) index [a] = nodeNumber++;
            if ( !index [b] ) index [b] = nodeNumber++;

            matrix [index [a]] [index [b]] = matrix [index [b]] [index [a]] = true;
        }

        int queryNode;
        int ttl;
        int dist [30 + 3];

        while ( cin >> queryNode >> ttl ) {
            if ( queryNode == 0 && ttl == 0 ) break;

            memset (dist, -1, sizeof (dist));

            dist [index [queryNode]] = 0;

            queue <int> q;
            q.push (index [queryNode]);

            while ( !q.empty () ) {
                int pop = q.front ();
                q.pop ();

                for ( int i = 1; i < nodeNumber; i++ ) {
                    if ( graph [pop] [i] && dist [i] == -1 ) {
                        dist [i] = dist [pop] + 1;
                        q.push (i);
                    }
                }
            }

            int cnt = 0;

            for ( int i = 1; i < nodeNumber; i++ ) {
                if ( dist [i] == -1 || dist [i] > ttl ) cnt++;
            }

            printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                    ++cases, cnt, queryNode, ttl);
        }
    }

    return 0;
    }
