#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    vector < pair < int , int > > v;
    int x,y,n,v;
    cin>> n >>v;
    for(int i=0;i<n;++i){
        cin>> x >> y ;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        x=v[i].second;

    }
    return 0;
}
