/*
ID: kiruayo1
PROG: preface
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

int tab[10];

void convert (int i){
    int j=i;
    if(j-1000>=0){
        tab[7]++;
        convert(j-1000);
    }
    /*else if(j-950>=0){
        tab[7]++;
        tab[4]++;
        convert(j-950);
    }*/
    else if(j-900>=0){
        tab[7]++;
        tab[5]++;
        convert(j-900);
    }
    else if(j-500>=0){
        tab[6]++;
        convert(j-500);
    }
    /*else if(j-450>=0){
        tab[6]++;
        tab[4]++;
        convert(j-450);
    }*/
    else if(j-400>=0){
        tab[6]++;
        tab[5]++;
        convert(j-400);
    }
    else if(j-100>=0){
        tab[5]++;
        convert(j-100);
    }
    /*else if(j-95>=0){
        tab[5]++;
        tab[2]++;
        convert(j-95);
    }*/
    else if(j-90>=0){
        tab[5]++;
        tab[3]++;
        convert(j-90);
    }
    else if(j-50>=0){
        tab[4]++;
        convert(j-50);
    }
    /*else if(j-49>=0){
        tab[4]++;
        tab[1]++;
        convert(j-49);
    }*/
    /*else if(j-45>=0){
        tab[4]++;
        tab[2]++;
        convert(j-45);
    }*/
    else if(j-40>=0){
        tab[4]++;
        tab[3]++;
        convert(j-40);
    }
    else if(j-10>=0){
        tab[3]++;
        convert(j-10);
    }
    else if(j-9>=0){
        tab[3]++;
        tab[1]++;
        convert(j-9);
    }
    else if(j-5>=0){
        tab[2]++;
        convert(j-5);
    }
    else if(j-4>=0){
        tab[2]++;
        tab[1]++;
        convert(j-4);
    }
    else if(j-1>=0){
        tab[1]++;
        convert(j-1);
    }
    else{
        return;
    }
}


int main(){
    ifstream f1("preface.in");
    ofstream f2("preface.out");
    tab[1]=0;
    tab[2]=0;
    tab[3]=0;
    tab[4]=0;
    tab[5]=0;
    tab[6]=0;
    tab[7]=0;
    //string romain[]={"I","IV","V","IX","X","XL","VL","IL","L","XC","VC","C","CD","LD","D","CM","LM","M"};
    //1,4,5,9,10,40,45,49,50,90,95,100,400,450,500,900,950,1000
    //I=1 V=5 X=10 L=50 C=100 D=500 M=1000
    // no XD IC IM
    int N;
    f1>>N;

    for(int i=1;i<=N;++i){
        convert(i);
    }

    if(tab[1]!=0){
        f2<<"I "<<tab[1]<<endl;
    }

    if(tab[2]!=0){
        f2<<"V "<<tab[2]<<endl;
    }

    if(tab[3]!=0){
        f2<<"X "<<tab[3]<<endl;
    }

    if(tab[4]!=0){
        f2<<"L "<<tab[4]<<endl;
    }

    if(tab[5]!=0){
        f2<<"C "<<tab[5]<<endl;
    }

    if(tab[6]!=0){
        f2<<"D "<<tab[6]<<endl;
    }

    if(tab[7]!=0){
        f2<<"M "<<tab[7]<<endl;
    }

    f1.close();
    f2.close();
    return 0;
}
