#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define mp make_pair
#define pb push_back

#define forl(idx,lim) for(int idx = 0 ; idx < (lim) ; ++ idx )

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;

const int oo=(int)1e9;
const int noo=(int)-1e9;
const ll ooll=(ll)1e18;
const ll nooll=(ll)-1e18;

char m[10][11];

int xx[4]={1,1,-1,-1};
int yy[4]={1,-1,1,-1};

int mx=0;

void f(int x,int y,int nb){
    mx=max(mx,nb);
    //cout << x << " " << y << " "
    for(int i=0;i<4;++i){
        int nx=x+xx[i];
        int ny=y+yy[i];
        // W B # .
        if(nx>=0 && nx<10 && ny>=0 && ny<10){
            //cout << m[nx][ny] << " ";
            if(m[nx][ny]!='B'){
                continue;
            }
            int nnx=nx+xx[i];
            int nny=ny+yy[i];
            if(nnx>=0 && nny>=0 && nnx<10 && nny<10){
                if(m[nnx][nny]=='#'){
                    //cout << x << " " << y << " " << nnx << " " << nny << endl ;
                    m[nx][ny]='#';
                    f(nnx,nny,nb+1);
                    m[nx][ny]='B';
                }
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int TC;
    scanf("%i",&TC);
    while(TC--){
        int wi=-1,wj=-1;
        for(int i=0;i<10;++i){
            scanf("%s",m[i]);
        }
        //memset(v,0,sizeof(v));
        mx=0;
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                if(m[i][j]=='W'){
                    f(i,j,0);
                }
            }
        }
        printf("%i\n",mx);
    }

    return 0;
}
