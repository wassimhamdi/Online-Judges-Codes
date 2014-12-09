/*
ID: kiruayo1
PROG: nocows
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int N,K;
int s[100][200];

int main(){
    ifstream f1("nocows.in");
    ofstream f2("nocows.out");

    f1>>N>>K;

    for(int i=0;i<=99;++i){
        fill_n(s[i],200,0);
    }

    for(int j=1;j<=K;++j)
    s[j][1]=1;

    s[2][3]=1;

    for(int j=3; j<=K;++j){
        for(int i=3; i<=N; i=i+2){
            for(int k=1;k<=i-2;k=k+2){
                s[j][i]=(s[j][i]+s[j-1][k]*s[j-1][i-k-1])%9901;
            }
        }
    }
    f2<< (s[K][N]-s[K-1][N]+9901)%9901<< endl;
    return 0;
}
