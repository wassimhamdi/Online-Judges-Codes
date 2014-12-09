#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
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

typedef pair<float ,pair<float,float> > ring;



#define X second.first
#define Y second.second
#define R first

main(){
    while(1){
        int nbr;
        cin >> nbr;
        if(nbr==-1){
            break;
        }
        disjointSet ds(nbr);
        vector<ring> rings;
        for(int i=0;i<nbr;++i){
            float r,x,y;
            cin >> x >> y >> r;
            rings.pb(mp(r,mp(x,y)));
        }
        for(int i=0;i<nbr;++i){
            for(int j=i+1;j<nbr;++j){
                float dr=sqrt( (rings[i].X-rings[j].X)*(rings[i].X-rings[j].X) + (rings[i].Y-rings[j].Y)* (rings[i].Y-rings[j].Y) );
                //cout << dr << " " << (rings[i].R+rings[j].R) << endl;
                if(rings[i].X==rings[j].X && rings[i].Y==rings[j].Y && rings[i].R==rings[j].R){
                    ds.merge(i,j);
                    continue;
                }
                if( dr<rings[i].R){
                    if((dr+rings[j].R)<=rings[i].R){
                        continue;
                    }
                }
                if(dr<rings[j].R){
                    if((dr+rings[i].R)<=rings[j].R){
                        continue;
                    }
                }
                if( (dr < (rings[i].R+rings[j].R))  ){
                    ds.merge(i,j);
                }
            }
        }
        vector<int> t(nbr);
        int mx=0;
        for(int i=0;i<nbr;++i){
            mx=max(mx,++t[ds.find(i)]);
        }
        //cout << ds.nComp << endl;
        cout <<"The largest component contains "<<mx<<" ring"<<((mx!=1)?"s":"")<<"."<<endl;
    }
    return 0;
}
