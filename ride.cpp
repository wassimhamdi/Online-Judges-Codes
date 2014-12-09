/*
ID: mbk_liv1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int i=1,j=1;
    for (string::iterator it=a.begin(); it!=a.end(); ++it){
		i*= *it - 'A' + 1;
    }
	i%=47;
    for (string::iterator it=b.begin(); it!=b.end(); ++it){
		j*= *it - 'A' + 1;
    }
	j%=47;
    fout << ((i==j)?"GO":"STAY") << endl;
    return 0;
}