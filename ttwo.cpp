/*
ID: kiruayo1
PROG: ttwo
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

char tab[15][15];
int tab2[15][15][15][15][5][5];

int main(){
    ifstream f1("ttwo.in");
    ofstream f2("ttwo.out");

    int Cdirection=1, Fdirection=1,Cpos[2],Fpos[2];

    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            f1>>tab[i][j];
            if(tab[i][j]=='C'){
                Cpos[0]=i;
                Cpos[1]=j;
                tab[i][j]='.';
            }
            if(tab[i][j]=='F'){
                Fpos[0]=i;
                Fpos[1]=j;
                tab[i][j]='.';
            }
        }
    }

    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<10;++k){
                for(int l=0;l<10;++l){
                    for(int r1=1;r1<5;++r1){
                        for(int r2=0;r2<5;++r2){
                            tab2[i][j][k][l][r1][r2]=0;
                        }
                    }
                }
            }
        }
    }
    int i=1;
    while(!tab2[Cpos[0]][Cpos[1]][Fpos[0]][Fpos[1]][Cdirection][Fdirection]){
        tab2[Cpos[0]][Cpos[1]][Fpos[0]][Fpos[1]][Cdirection][Fdirection]=1;
        switch(Cdirection){
            case 1:
                if(Cpos[0]==0 || tab[Cpos[0]-1][Cpos[1]]=='*'){
                    Cdirection++;
                }
                else{
                    Cpos[0]--;
                }
                break;
            case 2:
                if(Cpos[1]==9 || tab[Cpos[0]][Cpos[1]+1]=='*'){
                    Cdirection++;
                }
                else{
                    Cpos[1]++;
                }
                break;
            case 3:
                if(Cpos[0]==9 || tab[Cpos[0]+1][Cpos[1]]=='*'){
                    Cdirection++;
                }
                else{
                    Cpos[0]++;
                }
                break;
            case 4:
                if(Cpos[1]==0 || tab[Cpos[0]][Cpos[1]-1]=='*'){
                    Cdirection=1;
                }
                else{
                    Cpos[1]--;
                }
                break;
        }

        switch(Fdirection){
            case 1:
                if(Fpos[0]==0 || tab[Fpos[0]-1][Fpos[1]]=='*'){
                    Fdirection++;
                }
                else{
                    Fpos[0]--;
                }
                break;
            case 2:
                if(Fpos[1]==9 || tab[Fpos[0]][Fpos[1]+1]=='*'){
                    Fdirection++;
                }
                else{
                    Fpos[1]++;
                }
                break;
            case 3:
                if(Fpos[0]==9 || tab[Fpos[0]+1][Fpos[1]]=='*'){
                    Fdirection++;
                }
                else{
                    Fpos[0]++;
                }
                break;
            case 4:
                if(Fpos[1]==0 || tab[Fpos[0]][Fpos[1]-1]=='*'){
                    Fdirection=1;
                }
                else{
                    Fpos[1]--;
                }
                break;
        }


        if(Cpos[0]==Fpos[0] && Cpos[1]==Fpos[1]){
            f2<<i<<endl;
            return 0;
        }

        ++i;

    }

    f2<<0<<endl;
    return 0;
}


/*
.****...*.
..*......*
*.........
..........
*........*
*.**.*..**
F..*......
***....*.*
.C.......*
.......*.*
*/
