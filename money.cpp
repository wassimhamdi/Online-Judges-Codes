/*
ID: kiruayo1
PROG: money
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include<cmath>

using namespace std;

int N,V,tab[25];
unsigned long long dp[30][10009];

unsigned long long money(int i,int somme){
    if(somme>N){
        return 0;
    }
    if(somme==N){
        return 1;
    }
    if(dp[i][somme]!=-1){
        return dp[i][somme];
    }
    unsigned long long a=0;
    for(int j=i;j<V;++j){
        a=a+money(j,somme+tab[j]);
    }
    return dp[i][somme]=a;
}

int main(){
    ifstream f1("money.in");
    ofstream f2("money.out");

    f1>>V>>N;

    for(int i=0;i<V;++i){
        f1>>tab[i];
        for(int j=0;j<=N;++j){
            dp[i][j]=-1;
        }
    }

    f2<<money(0,0)<<endl;

    f1.close();
    f2.close();
    return 0;
}
