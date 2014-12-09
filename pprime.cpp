/*
ID: kiruayo1
PROG: pprime
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
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

    int k,a,b;
    ifstream f1("pprime.in");
    ofstream f2("pprime.out");

    f1 >> a >> b;

    if(a==5){
        f2 << 5 << endl;
    }
    if(a<=7 && b>=7){
        f2 << 7 << endl;
    }

    for(int d1=0;d1<10;++d1){
        k=d1+10*d1;
        if(k<=b && k>=a && isprime(k)){
            f2<<k<<endl;
        }
    }

    for(int d1=1;d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            k=100*d1+10*d2+d1;
            if(k<=b && k>=a && isprime(k)){
                f2<<k<<endl;
            }
        }
    }

    for(int d1=1; d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            k=1000*d1+100*d2+10*d2+d1;
            if(k<=b && k>=a && isprime(k)){
                f2<<k<<endl;
            }
        }
    }

    for(int d1=1; d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            for(int d3=0;d3<10;++d3){
                k=10000*d1+1000*d2+100*d3+10*d2+d1;
                if(k<=b && k>=a && isprime(k)){
                    f2<<k<<endl;
                }
            }
        }
    }

    for(int d1=1; d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            for(int d3=0;d3<10;++d3){
                k=100000*d1+10000*d2+1000*d3+100*d3+10*d2+d1;
                     if(k<=b && k>=a && isprime(k)){
                        f2<<k<<endl;
                    }
            }
        }
    }

    for(int d1=1; d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            for(int d3=0;d3<10;++d3){
                for(int d4=0;d4<10;++d4){
                    k=1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1;
                    if(k<=b && k>=a && isprime(k)){
                        f2<<k<<endl;
                    }
                }
            }
        }
    }

    for(int d1=1; d1<10;++d1){
        for(int d2=0;d2<10;++d2){
            for(int d3=0;d3<10;++d3){
                for(int d4=0;d4<10;++d4){
                    k=10000000*d1+1000000*d2+100000*d3+10000*d4+1000*d4+100*d3+10*d2+d1;
                    if(k<=b && k>=a && isprime(k)){
                        f2<<k<<endl;
                    }
                }
            }
        }
    }


    return 0;
}
