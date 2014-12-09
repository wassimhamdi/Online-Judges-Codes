/*
ID: hamdi.w1
PROG: milk3
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include<algorithm>
using namespace std;

int A,B,C,s[21]={0},flag[21][21]={0};

void dfs(int x,int y, int z){
    if (flag[x][y]){
        return;
    }
    flag[x][y]=1;

    if(x==0){
        s[z]=1;
    }

    if(x+y<=B){
        dfs(0,x+y,z);
    }
    else{
        dfs(x+y-B,B,z);
    }

    if(x+z<=C){
        dfs(0,y,z+x);
    }
    else{
        dfs(x+z-C,y,C);
    }

    if(x+y<=A){
        dfs(x+y,0,z);
    }
    else{
        dfs(A,y+x-A,z);
    }

    if(z+y<=C){
        dfs(x,y,z+y);
    }
    else{
        dfs(x,y+z-C,C);
    }

    if(x+z<=A){
        dfs(x+z,y,0);
    }
    else{
        dfs(A,y,z+x-A);
    }

    if(z+y<=B){
        dfs(x,y+z,0);
    }
    else{
        dfs(x,B,z+y-B);
    }
}


int main(){
    ifstream f1("milk3.in");
    ofstream f2("milk3.out");

    f1>>A>>B>>C;

    dfs(0,0,C);

    for(int i=0;i<C;++i){
        if(s[i]){
            f2 << i << " ";
        }
    }

    f2 << C << endl;
    return 0;
}
