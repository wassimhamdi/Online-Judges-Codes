/*
ID: kiruayo1
PROG: prefix
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <cmath>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

string tab[209];
int s[200009];
int s2[200009];
string sss="";
int N;


int main(){
    ifstream f1("prefix.in");
    ofstream f2("prefix.out");

    char w=' ';
    N=0;
    tab[0]="";

    while(tab[N]!="."){
        ++N;
        f1 >> tab[N];
    }

    char str[80];
    while(!f1.eof()){
      f1.getline(str,80);
      sss=sss+str;
    }


    s[0]=1;
    int l=sss.length();

    fill_n(s+1,l,0);


    int i=0;
    int max=0;
    while(i<=l){
        if(s[i]==1){
            max=i;
            for(int j=1;j<N;++j){

                if(/*sss.substr(0,i)+tab[j]==sss.substr(0,i+tab[j].length()*/tab[j]==sss.substr(i,tab[j].length())){
                    s[i+tab[j].length()]=1;
                }
            }
        }
        ++i;
    }
    f2<<max<<endl;
    return 0;
}

/*
AH AS AZ BW CD CK CN CU CZ DB DH EC ED EN FJ GA GK GM GS GT
HA HN HZ IN IR JB JD JM JZ KG KI LO LQ LU LW LY MJ MT MV ND
NM NS OB OI OK OM PG PO PQ PZ QE QP RG RK RN RP RQ RR RS RU
SA SF SJ SN TK TR TU TY UA UO US UW UX VH VL VO WF WH WL WS
WZ XU XW XY YA YI YN YT ZF ZH ZJ ZL ZR ZX
.
ASCDCKCUEDFJGKGMHAIRJMKILQLWLYMJMTMVNSOIOKOMPOPQQPRGRNRPSJTU
TYWSWZXWYIYTAHAZBWCDCNCUDHECENGAGMGSGTHAHNKGLQLULWNMOBOIOKOM
PGPOPQPZRGRKRNRPRRSATRTUUWVLVOWFWLWSXUXYYAYIYNYTZFZJZRZXBWCK
CUFJGAGSHAHNIRJBJMKILQLUNDNMNSOKOMPQQERGRQRRRSSASFSJSNTUTYUA
UOUWVLWHXUXWXYYAYTZFZJZLZRZXASBWCDCNDBECEDFJGSHAHNHZINJMKGKI
LQMJNMNSOKOMPQQPRRRSSFSJSNTRTUTYUAUWUXVLVOWLWSWZXYYNYTZFZHZR
ZXAHASAZCDCKCNDBECENGMGSHAHZIRJDKGKILOLYOBOKPGPQQPRRSNTRTYUO
USUXVHVLVOWFWLWSXYYNZJZXZZAHAZBWCDCKCNDB
*/
