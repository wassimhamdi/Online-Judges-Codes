/*
ID: kiruayo1
PROG: fracdec
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int tab[100009];

int main(){
    ifstream f1("fracdec.in");
    ofstream f2("fracdec.out");

    int N,D;
    f1>>N>>D;

    f2<<N/D<<".";

    string c="";
    stringstream cc;
    cc<<N/D<<".";
    cc>>c;


    for(int i=0;i<=100000;++i){
        tab[i]=-1;
    }


    int r=N%D,k=0;
    int i=0;

    if(r==0){
        f2<<0<<endl;
        return 0;
    }

    else{
        string s="";
        stringstream ss;

        while(tab[r]==-1){
            tab[r]=i;
            ss << r*10/D;
            ++i;
            r=(r*10)%D;
        }

        ss>>s;

        if(r==0){
            f2<<s.substr(0,s.length()-1)<<endl;
            return 0;
        }

        char w;
        int l=c.length(),j=0;

        while(j<s.length()){
            if(j==tab[r]){
                ++l;
                f2<<"(";
            }
            f2<<s[j];
            ++l;
            ++j;
            if(l%76==0){
                f2<<endl;
            }
        }
        f2<<")"<<endl;

        return 0;
    }
}
