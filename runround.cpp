/*
ID: kiruayo1
PROG: runround
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;


#define pb push_back
#define mp make_pair

int tab[20],tab3[20],tab4[20],i=0;
int tab2[10];

bool test1(){
    int c=0;
    bool okay=true,okay2=true;
    int j=0;
    while(j<i){
        tab2[tab[j]]++;
        ++j;
    }
    if(tab2[0]>=1){
        return false;
    }
    for(int e=1;e<10;++e){
        if(tab2[e]>1){
            return false;
        }
    }
    return true;
}

bool property(){
    int j=0,c=0;

    while(c<i){
        if(tab[j]==tab[(tab[j]+j)%i] || tab4[(tab[j]+j)%i]==1){
            return false;
        }
        j=(j+tab[j])%i;
        tab4[j]=1;
        c++;
    }
    return true;
}


int main(){
    ifstream f1("runround.in");
    ofstream f2("runround.out");

    unsigned long N;
    f1>>N;
    unsigned long k=N+1;

    while(1){
        unsigned long k2=k;
        i=0;
        for(int j=0;j<10;++j){
            tab2[j]=0;
            tab4[j]=0;
        }

        do{
            tab3[i]=k2%10;
            ++i;
            k2=k2/10;
        }while(k2!=0);

        for(int e=i-1;e>=0;--e){
            tab[e]=tab3[i-1-e];
        }


        if(test1() && property()){
            f2<<k<<endl;
            return 0;
        }

        k++;
    }
    f1.close();
    f2.close();
    return 0;
}
