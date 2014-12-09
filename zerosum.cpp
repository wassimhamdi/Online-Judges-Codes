/*
ID: kiruayo1
PROG: zerosum
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
using namespace std;
int N,tab[10],tab2[30],tab3[10];
set <string> solutions;

bool test(){
    string s="";
    int i=1;
    while(i<=N){
        if(tab[i-1]==0){
            s=s+" + ";
            s=s+(char)(i+'0');
        }
        else if(tab[i-1]==1){
            s=s+" - ";
            s=s+(char)(i+'0');
        }
        else{
            s=s+(char)(i+'0');
        }
        ++i;
    }
    int c=1,sum=0;
    istringstream f(s);
    char ch=' ';
    while(c%10!=N){
        f >> ch >> c;
        if(ch=='+'){
            sum=sum+c;
        }
        else{
            sum=sum-c;
        }
    }
    return (sum==0);
}

int main(){
    ifstream f1("zerosum.in");
    ofstream f2("zerosum.out");
    string car="+- ";
    f1>>N;
    tab[0]=0;
    for(tab[1]=0;tab[1]<=2;tab[1]++){
    for(tab[2]=0;tab[2]<=2;tab[2]++){
    for(tab[3]=0;tab[3]<=2;tab[3]++){
    for(tab[4]=0;tab[4]<=2;tab[4]++){
    for(tab[5]=0;tab[5]<=2;tab[5]++){
    for(tab[6]=0;tab[6]<=2;tab[6]++){
    for(tab[7]=0;tab[7]<=2;tab[7]++){
    for(tab[8]=0;tab[8]<=2;tab[8]++){
            if(test()){
                string ss="";
                for(int i=1;i<N;++i){
                    ss=ss+(char)(i+'0');
                    ss=ss+car[tab[i]];
                }
                ss=ss+(char)(N+'0');
                solutions.insert(ss);
            }
    }
    }
    }
    }
    }
    }
    }
    }


    for (set<string>::iterator it = solutions.begin();it!=solutions.end();++it){
			f2<<*it<<endl;
    }
    return 0;
}
