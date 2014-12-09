/*
ID: kiruayo1
PROG: lamps
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

vector <int> ON,OFF;
set <string> solutions;
int N,C,tab[110],compteur=0;
int tab2[3][3][3][3];

void button1(){
    for(int i=1;i<=N;++i){
        tab[i]=(!tab[i]);
    }
}

void button2(){
    for(int i=1;i<=N;i=i+2){
        tab[i]=(!tab[i]);
    }
}

void button3(){
    for(int i=2;i<=N;i=i+2){
        tab[i]=(!tab[i]);
    }
}

void button4(){
    for(int i=1;i<=N;i=i+3){
        tab[i]=(!tab[i]);
    }
}

bool valide(){
    for(int i=0;i<ON.size();++i){
        if(!tab[ON[i]]){
            return false;
        }
    }

    for(int i=0;i<OFF.size();++i){
        if(tab[OFF[i]]){
            return false;
        }
    }

    return true;
}

void recurs (int n1,int n2,int n3,int n4, ofstream &out){

    if(n1>C || n2>C || n3>C || n4>C || n1<0 || n2<0 || n3<0 || n4<0 || tab2[n1%2][n2%2][n3%2][n4%2]){
        return;
    }
    tab2[n1%2][n2%2][n3%2][n4%2]=1;
    if(n1%2==1){
        button1();
    }
    if(n2%2==1){
        button2();
    }
    if(n3%2==1){
        button3();
    }
    if(n4%2==1){
        button4();
    }
    if(valide()){
        string ss="";
        for(int i=1;i<=N;++i){
            ss=ss+(char)(tab[i]+'0');
        }
        solutions.insert(ss);
    }

    for(int i=1;i<=N;++i){
        tab[i]=1;
    }

    recurs(n1-1,n2+1,n3,n4,out);
    recurs(n1-1,n2,n3+1,n4,out);
    recurs(n1-1,n2,n3,n4+1,out);
    recurs(n1+1,n2-1,n3,n4,out);
    recurs(n1,n2-1,n3+1,n4,out);
    recurs(n1,n2-1,n3,n4+1,out);
    recurs(n1+1,n2,n3-1,n4,out);
    recurs(n1,n2+1,n3-1,n4,out);
    recurs(n1,n2,n3-1,n4+1,out);
    recurs(n1+1,n2,n3,n4-1,out);
    recurs(n1,n2+1,n3,n4-1,out);
    recurs(n1,n2,n3+1,n4-1,out);
}

int main(){
    ifstream f1("lamps.in");
    ofstream f2("lamps.out");

    for(int i=0;i<=1;++i){
        for(int j=0;j<=1;++j){
            for(int l=0;l<=1;++l){
                for(int f=0;f<=1;++f){
                    tab2[i][j][l][f]=0;
                }
            }
        }
    }

    int k=0;
    f1>>N>>C;

    while(k!=-1){
        f1>>k;
        if(k!=-1){
            ON.pb(k);
        }
    }

    k=0;

    while(k!=-1){
        f1>>k;
        if(k!=-1){
            OFF.pb(k);
        }
    }

    for(int i=1;i<=N;++i){
        tab[i]=1;
    }

    recurs(C,0,0,0,f2);

    if(solutions.size()==0){
        f2<<"IMPOSSIBLE"<<endl;
    }
    else {
        for(set<string>::iterator it=solutions.begin() ; it!=solutions.end();++it){
            f2<<*it<<endl;
        }
    }

    f1.close();
    f2.close();
    return 0;
}
