/*
ID: kiruayo1
PROG: hamming
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;


#define pb push_back
#define mp make_pair

int N,B,D;
vector <int> vect;
//int max=0;

int hamming(int i,int j){
    int c=0;
    int i2=i;
    int j2=j;
    for(int k=0;k<B;++k){
        if(i2%2 != j2%2){
            c++;
        }
        i2=i2/2;
        j2=j2/2;
    }
    return c;
}

bool test(int j){
    for(int i=0;i<vect.size();++i){
        if(hamming(vect[i],j)<D){
            return false;
        }
    }
    return true;
}

void recursif(int j,int max){
    if(vect.size()==N){
        return;
    }
    else if(j>max){
        int s=vect[vect.size()-1]+1;
        vect.pop_back();
        recursif(s,max);
    }
    else if(test(j)){
        vect.pb(j);
        recursif(j+1,max);
    }
    else{
        recursif(j+1,max);
    }
}

int main(){
    ifstream f1("hamming.in");
    ofstream f2("hamming.out");

    vect.pb(0);

    f1 >> N >> B >> D;

    int N2=N;
    int i=1;
    int max=0;
    for(int r=0;r<B;++r){
        max=max+(int)pow(2,r);
    }

    recursif(1,max);

    for(int k=0;k<N;++k){
        if((k+1)%10==0 || k==N-1){
            f2 << vect[k] << endl;
        }
        else{
            f2 << vect[k] << " ";
        }
    }

    f1.close();
    f2.close();
    return 0;

}

