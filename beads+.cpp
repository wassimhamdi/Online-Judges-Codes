/*
ID: kiruayo1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*astuce int�resssante: dupliquer la cha�ne*/
int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    unsigned short N;
    fin >> N;
    string str;
    fin >> str;
    str += str;
    int max = 0;
    for (int i = 0; i < 2 * N; i++){
        int m1 = 0;
        char a='w';
        bool first=true; //teste si premi�re lettre w
        for
    }
    return 0;
}

