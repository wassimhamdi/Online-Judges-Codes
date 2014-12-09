/*
ID: kiruayo1
PROG: comehome
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int tab[65][65];
int tab2[30];

void warshal(){
    for(int k=1;k<=52;++k){
        for(int i=1;i<=52;++i){
            for(int j=1;j<=52;++j){
                tab[i][j]=min(tab[i][j],tab[i][k]+tab[k][j]);
            }
        }
    }
}

int main(){
    ifstream f1("comehome.in");
    ofstream f2("comehome.out");

    int n;
    f1>>n;

    for(int i=0;i<60;++i){
        for(int j=0;j<60;++j){
            tab[i][j]=1<<28;
        }
        tab2[i]=0;
    }
    for(int i=0;i<30;++i){
        tab[i][i]=0;
    }

    for(int i=0;i<n;++i){
        char x,y;
        int cost;
        f1>>x>>y>>cost;
        if(x>='a' && y>='a'){
            tab[(int)(y-'a'+27)][(int)(x-'a'+27)]=min(cost,tab[(int)(y-'a'+27)][(int)(x-'a'+27)]);
            tab[(int)(x-'a'+27)][(int)(y-'a'+27)]=min(tab[(int)(x-'a'+27)][(int)(y-'a'+27)],cost);
        }
        else if(x>='a'){
            tab2[(int)(y-'A'+1)]=1;
            tab[(int)(y-'A'+1)][(int)(x-'a'+27)]=min(cost,tab[(int)(y-'A'+1)][(int)(x-'a'+27)]);
            tab[(int)(x-'a'+27)][(int)(y-'A'+1)]=min(cost,tab[(int)(x-'a'+27)][(int)(y-'A'+1)]);
        }
        else if(y>='a'){
            tab2[(int)(x-'A'+1)]=1;
            tab[(int)(y-'a'+27)][(int)(x-'A'+1)]=min(cost,tab[(int)(y-'a'+27)][(int)(x-'A'+1)]);
            tab[(int)(x-'A'+1)][(int)(y-'a'+27)]=min(cost,tab[(int)(x-'A'+1)][(int)(y-'a'+27)]);
        }
        else{
            tab2[(int)(y-'A'+1)]=1;
            tab2[(int)(x-'A'+1)]=1;
            tab[(int)(y-'A'+1)][(int)(x-'A'+1)]=min(cost,tab[(int)(y-'A'+1)][(int)(x-'A'+1)]);
            tab[(int)(x-'A'+1)][(int)(y-'A'+1)]=min(cost,tab[(int)(x-'A'+1)][(int)(y-'A'+1)]);
        }
    }

    tab2[26]=0;
    warshal();
    char min1;
    int min2=1<<28;

    for(int i=1;i<=25;++i){
        if(tab2[i] && tab[i][26]<min2){
            min1='A'-1+i;
            min2=tab[i][26];
        }
    }
    f2<<min1<<" "<<min2<<endl;
    return 0;
}
/*
4
d Z 10
b d 2
A b 4
C d 5
*/
