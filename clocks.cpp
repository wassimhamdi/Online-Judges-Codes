/*
ID: kiruayo1
PROG: clocks
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include<algorithm>
using namespace std;

int a,b,c,d,e,f,g,h,i;
set<int> solutions;

int main(){
    ifstream f1("clocks.in");
    ofstream f2("clocks.out");

    f1>>a>>b>>c>>d>>e>>f>>g>>h>>i;

    dfs(a,b,c,d,e,f,g,h,i);



    return 0;
}
