/*
ID: hamdi.w1
PROG: holstein
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

set <pair <int,string> > solutions;
int tab1[30],V,G;
int tab2[20][30],tab3[30],tab4[20];

void eatG (int j){
    if(j==0){
        return;
    }
    for(int i=1;i<=V;++i){
        tab3[i]=tab3[i]+tab2[j][i];
    }
    return;
}

void uneatG (int j){
    if(j==0){
        return;
    }
    for(int i=1;i<=V;++i){
        tab3[i]=tab3[i]-tab2[j][i];
    }
    return;
}

bool satisfied(void){
    for(int i=1;i<=V;++i){
        if(tab1[i]>tab3[i]){
            return false;
        }
    }
    return true;
}



int main(){
    ifstream f1("holstein.in");
    ofstream f2("holstein.out");

    f1>>V;
    string base="123456789:;<=>?";
    for(int i=1;i<=V;++i){
        f1>>tab1[i];
        tab3[i]=0;
    }

    f1>>G;

    for(int i=1;i<=G;++i){
        for(int j=1;j<=V;++j){
            f1>>tab2[i][j];
        }
    }

    for(int k1=0;k1<=1;k1++){
        for(int k1=0;k1<=1;k1++){
        for(int k2=0;k2<=1;k2++){
        for(int k3=0;k3<=1;k3++){
        for(int k4=0;k4<=1;k4++){
        for(int k5=0;k5<=1;k5++){
        for(int k6=0;k6<=1;k6++){
        for(int k7=0;k7<=1;k7++){
        for(int k8=0;k8<=1;k8++){
        for(int k9=0;k9<=1;k9++){
        for(int k10=0;k10<=1;k10++){
        for(int k11=0;k11<=1;k11++){
        for(int k12=0;k12<=1;k12++){
        for(int k13=0;k13<=1;k13++){
        for(int k14=0;k14<=1;k14++){
        for(int k15=0;k15<=1;k15++){
            tab4[15]=k1;
            tab4[14]=k2;
            tab4[13]=k3;
            tab4[12]=k4;
            tab4[11]=k5;
            tab4[10]=k6;
            tab4[9]=k7;
            tab4[8]=k8;
            tab4[7]=k9;
            tab4[6]=k10;
            tab4[5]=k11;
            tab4[4]=k12;
            tab4[3]=k13;
            tab4[2]=k14;
            tab4[1]=k15;



            for(int i=1;i<=G;++i){
                if(tab4[i]){
                    eatG(i);
                }
            }
            if(satisfied()){
                string ss="";
                for(int i=1;i<=G;++i){
                    if(tab4[i]){
                        ss=ss+(char)('0'+i);
                    }
                }
                solutions.insert(mp(ss.length(),ss));
            }

            for(int i=1;i<=G;++i){
                if(tab4[i]){
                    uneatG(i);
                }
            }

    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }

    string sss=(*solutions.begin()).second;

    f2 << sss.length();

    for(int i=0;i<sss.length();++i){
        f2 << " " << sss[i]-'0';
    }

    f2 << endl;

    f1.close();
    f2.close();
    return 0;

}


