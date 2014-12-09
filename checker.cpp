/*
ID: kiruayo1
PROG: checker
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include<algorithm>
using namespace std;

bool inrow[15], incolumn[15],leftdiag[35],rightdiag[35],queenplaced[15][15];
int i=0,N;

void placequeen (int row,ofstream &f2){
    if (row==N){
        ++i;
        if(i<4){
            for(int r=0;r<N-1;++r){
                for(int c=0;c<N;++c){
                    if(queenplaced[r][c]){
                        f2 << 1+c << " ";
                    }
                }

            }
            for(int c=0;c<N;++c){
                    if(queenplaced[N-1][c]){
                        f2 << c+1 << endl;
                    }
            }
        }
    return;
    }
    for(int column=0;column<N;++column){
        if(!inrow[row] && !incolumn[column] && !rightdiag[row-column+N] && !leftdiag[column+row]){
            incolumn[column]=1;
            rightdiag[row-column+N]=1;
            leftdiag[column+row]=1;
            queenplaced[row][column]=1;
            inrow[row]=1;

            placequeen(row+1,f2);

            inrow[row]=0;
            incolumn[column]=0;
            rightdiag[row-column+N]=0;
            leftdiag[column+row]=0;
            queenplaced[row][column]=0;
        }
    }

}


int main(){
    ifstream f1("checker.in");
    ofstream f2("checker.out");

    f1>>N;

    fill_n(inrow,14,false);
    fill_n(incolumn,14,false);
    fill_n(rightdiag,30,false);
    fill_n(leftdiag,30,false);

    for(int j=0;j<N;++j){
        fill_n(queenplaced[j],15,false);
    }

    placequeen(0,f2);
    f2 << i << endl;

    return 0;
}
