/*
ID: kiruayo1
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include<algorithm>
using namespace std;

int main(){
    int pas=1,prem=0,N,M;
    bool tab[1250009];
    fill_n(tab,1250000,false);

    ifstream f1("ariprog.in");
    ofstream f2("ariprog.out");

    f1>>N>>M;

    for(int p=0;p<=M;++p){
        for(int q=0;q<=M;++q){
            tab[p*p+q*q]=true;
        }
    }

    int MAX=2*M*M;

    set<pair<int,int> > solutions;
    int j;

    for(prem=0;prem<=MAX;++prem){
        for(pas=1;pas<=MAX && prem+(N-1)*pas<=MAX;++pas){
            j=0;
            while(j<=N-1 && tab[j*pas+prem]){
                ++j;
            }
            if(j==N){
                solutions.insert(make_pair(pas,prem));
            }
        }
    }

    if(!solutions.size()){
        f2<<"NONE"<<endl;
    }
    else{
        for (set<pair<int,int> >::iterator it = solutions.begin();it!=solutions.end();++it){
			f2<< it->second << " " << it->first <<endl;
		}
    }

    return 0;
}
