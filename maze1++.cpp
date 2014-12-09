/*
ID: kiruayo1
PROG: maze1
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
int W,H;
char tab[210][80];
int tab3[101][40];

void maze1 (int i, int j){
    if(i!=H && tab[2*i+1][2*j]==' ' && tab3[i][j]+1<tab3[i+1][j]){
        tab3[i+1][j]=tab3[i][j]+1;
        maze1(i+1,j);
    }
    if(i!=1 && tab[2*i-1][2*j]==' ' && tab3[i-1][j]>tab3[i][j]+1){
        tab3[i-1][j]=tab3[i][j]+1;
        maze1(i-1,j);
    }
    if(j!=W && tab[2*i][2*j+1]==' ' && tab3[i][j+1]>tab3[i][j]+1){
        tab3[i][j+1]=tab3[i][j]+1;
        maze1(i,j+1);
    }
    if(j!=1 && tab[2*i][2*j-1]==' ' && tab3[i][j-1]>tab3[i][j]+1){
        tab3[i][j-1]=tab3[i][j]+1;
        maze1(i,j-1);
    }
}

int main(){
    ifstream f1("maze1.in");
    ofstream f2("maze1.out");

    int tab2[4];
    f1>>W>>H;
    int c=0;

    char w;
    for(int i=1;i<=2*H+1;++i){
        for(int j=1;j<=2*W+1;++j){
            w=f1.get();
            if(w=='\n'){
                w=f1.get();
            }
            tab[i][j]=w;
            if(i==1 && tab[i][j]==' '){
                tab2[c]=1;
                tab2[c+1]=j/2;
                c+=2;
            }
            if(i==2*H+1 && tab[i][j]==' '){
                tab2[c]=H;
                tab2[c+1]=j/2;
                c+=2;
            }
            if(j==1 && tab[i][j]==' '){
                tab2[c]=i/2;
                tab2[c+1]=1;
                c+=2;
            }
            if(j==2*W+1 && tab[i][j]==' '){
                tab2[c]=i/2;
                tab2[c+1]=W;
                c+=2;
            }
        }
    }

    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            tab3[i][j]=1<<28;
        }
    }

    tab3[tab2[0]][tab2[1]]=0;
    tab3[tab2[2]][tab2[3]]=0;

    maze1(tab2[0],tab2[1]);
    maze1(tab2[2],tab2[3]);

    int max=0;
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            if(tab3[i][j]>max){
                max=tab3[i][j];
            }
        }
    }

    f2<<max+1<<endl;

    return 0;
}
