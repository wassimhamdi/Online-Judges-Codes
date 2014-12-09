/*
ID: kiruayo1
PROG: subset
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include<cmath>

using namespace std;

long dp[50][1000];
int N,k;

unsigned long recursif(int i, int somme){
    if(dp[i][somme]!=-1){
        return dp[i][somme];
    }
    if(somme==k){

        return dp[i][somme]=1;
    }

    else if(somme>k){

        return dp[i][somme]=0;
    }

    long a=0;

    for(int j=i+1;j<=N;++j){
        a=a+recursif(j,somme+j);
    }


    return dp[i][somme]=a;
}

int main(){
    ifstream f1("subset.in");
    ofstream f2("subset.out");


    f1>>N;

    k=N*(N+1)/2;

    if((k%2)!=0){
        f2<<0<<endl;
        f1.close();
        f2.close();
        return 0;
    }

    k=k/2;

    for(int i=0;i<=45;++i){
        for(int j=0;j<=1000;++j){
            dp[i][j]=-1;
        }
    }

    unsigned long compteur=recursif(0,0);
    f2<<compteur/2<<endl;

    f1.close();
    f2.close();
    return 0;
}

