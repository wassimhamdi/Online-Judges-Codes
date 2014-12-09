/*
ID: kiruayo1
PROG: numtri
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n;
    ifstream f1("numtri.in");
    ofstream f2("numtri.out");
    f1 >> n;
    int tab[n+10][n+10];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            f1 >> tab[i][j];
        }
    }
    for(int i=n-1;i--;i>=0){
        for(int j=0;j<=i;j++){
            tab[i][j]=tab[i][j]+max(tab[i+1][j],tab[i+1][j+1]);
        }
    }
    f2 << tab[0][0]<<endl;
    return 0;
}
