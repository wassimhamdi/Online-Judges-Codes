/*
ID: kiruayo1
PROG: frac1
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
    ifstream f1("frac1.in");
    ofstream f2("frac1.out");
    int N;
    f1 >> N;

    set < pair<double,pair<int,int> > >solutions;

    for(int i=1;i<N;++i){
        for(int j=i+1;j<=N;++j){
            solutions.insert(mp((double)i/j,mp(i,j)));
        }
    }
    double k=0;
    f2<<"0/1"<<endl;
    for(set< pair<double,pair<int,int> > >::iterator it=solutions.begin() ; it!=solutions.end();++it){ //begin(v) et end(v) dans c++11
        if((*it).first!=k){
            f2<<(*it).second.first <<"/" << (*it).second.second <<endl;
        }
        k=(*it).first;
    }
    f2<<"1/1"<<endl;


    f1.close();
    f2.close();
    return 0;
}
