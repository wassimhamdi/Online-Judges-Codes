/*
ID: kiruayo1
PROG: concom
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

const int MX = 109;//set here maximum no of nodes

int graph[MX][MX];
int tab[109][109];

int n;

void own(int l, int r){
    for(int i=1;i<=100;++i){
        if(l!=i && r!=i && l!=r && !tab[l][i]){
            graph[l][i]=graph[l][i]+graph[r][i];
            if(graph[l][i]>50){
                tab[l][i]=1;
                own(l,i);
            }
        }
    }
}

int main(){
    ifstream f1("concom.in");
    ofstream f2("concom.out");

    f1>>n;

    for (int i = 0; i < 102; ++i) {
		fill(tab[i], tab[i]+102, 0);
		fill(graph[i], graph[i]+102, 0);
	}

    for (int i = 0; i < n; ++i)
	{
		int x, y, c;
		f1 >>x>>y>>c;
		if(c>50){
            tab[x][y]=1;
		}
		graph[x][y]=c;
	}

    for (int k = 1; k <= 100; ++k){
		for (int i = 1; i <= 100; ++i){
            if(k!=i && tab[k][i]){
                own(k,i);
            }
        }
    }



    for(int i=1;i<=100;++i){
        for(int j=1;j<=100;++j){
            if(i!=j && tab[i][j]){
                f2<<i<<" "<<j<<endl;
            }
        }
    }

    return 0;
}
