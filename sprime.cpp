/*
ID: kiruayo1
PROG: sprime
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include<deque>
using namespace std;

bool isprime(int n){
    if(n%2==0){
        return false;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    int N;
    ifstream f1("sprime.in");
    ofstream f2("sprime.out");

    f1 >> N;
    deque <int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    int k,k2;
    k=2;
    for(int i=1;i<N-1;++i){
        while(k%(int)(pow(10,i+1))==k){
            for(int j=1;j<10;j=j+2){
                k2=k*10+j;
                if(isprime(k2)){
                    v.push_back(k2);
                }
            }
            v.pop_front();
            k=v.front();
        }
    }
    for(deque<int>::iterator it=v.begin() ; it!=v.end();++it){
        f2<<*it<<endl;
    }

    return 0;
}
