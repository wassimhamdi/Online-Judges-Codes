#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include<algorithm>
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




int main(){

    pair<int,int> coord[109];

    int n;
    cin >> n;
    disjointSet sets(n);

    for (int i=0;i<n;++i){
        cin >> coord[i].first >> coord[i].second;
    }


    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(coord[i].first==coord[j].first || coord[i].second==coord[j].second){
                sets.merge(i,j);
            }
        }
    }

   /* for (int i=0;i<n;++i){
        cout << sets.par[i]<<endl;
    }*/

    cout<<sets.nComp-1<<endl;


    return 0;
}
