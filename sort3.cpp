/*
ID: kiruayo1
PROG: sort3
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;


#define pb push_back
#define mp make_pair


int main(){
    ifstream f1("sort3.in");
    ofstream f2("sort3.out");

    int N,x=0,y=0,z,tab[1009],resultat=0;
    f1>>N;

    for(int i=1;i<=N;++i){
        f1 >> tab[i];
        if(tab[i]==1){
            x++;
        }
        if(tab[i]==2){
            y++;
        }
    }

    z=N-x-y;
    int j=1;
    int k=1;
    for(int i=1;i<=x;++i){
        if(tab[i]==2){
            while(j<=y){

                if(tab[j+x]==1){
                    resultat++;
                    tab[i]=1;
                    tab[j+x]=2;
                    break;
                }
                ++j;
            }
        }
        if(tab[i]==3){
            while(k<=z){

                if(tab[x+y+k]==1){
                    resultat++;
                    tab[i]=1;
                    tab[x+y+k]=3;

                    break;
                }
                ++k;
            }
        }
    }
    j=1;
    for(int i=x+1;i<=x+y;++i){
        if(tab[i]==3){
            while(j<=z){

                if(tab[j+x+y]==2){
                    resultat++;
                    tab[i]=2;
                    tab[j+x+y]=3;
                    break;
                }
                ++j;
            }
        }
    }

    for(int i=1;i<=x;++i){
        if(tab[i]!=1){
            resultat=resultat+2;

        }
    }

    f2<<resultat<<endl;

    f1.close();
    f2.close();
    return 0;
}
