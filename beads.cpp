/*
ID: hamdi.w1
PROG: beads
LANG: C
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	unsigned short N;
	fin >> N;
    string str;
    fin >> str;
	str += str;
	int max = 0;
	for (int i = 0; i < 2 * N; i++) {
		int m1 = 0;
		char a = 'w';
		bool first = true;
		for (int k = i; k < 2 * N; k++) {
			if (a == str[k] || str[k] == 'w') {
				m1++;
				if (str[k] != 'w') {
					first = false;
					a = str[k];
				}
			} else if (str[k] != 'w') {
				if (first) {
					first = false;
					m1++;
					a = str[k];
				} else {
					break;
				}
			}
		}
		a = 'w';
		first = true;
		int m2 = 0;
		for (int k = i - 1; k >= 0; k--) {
			if (a == str[k] || str[k] == 'w') {
				m2++;
				if (str[k] != 'w') {
					first = false;
					a = str[k];
				}
			}
			else if (str[k] != 'w') {
				if (first) {
					first = false;
					m2++;
					a = str[k];
				}
				else
					break;
			}
		}
		if (m1 + m2 > max) {
			max = m1 + m2;
		}
		if (m1 + m2 >= N) {
			max = N;
			break;
		}
	}
    fout << max << endl;
    return 0;
}
