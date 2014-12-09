/*
ID: kiruayo1
PROG: castle
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


int tab[59][59];
int tab2[50*50+9];


struct disjointSet{

	vector<int > par, rank;
	int nComp;
	disjointSet(int n) {
		par = vector<int > (n);
		rank = vector<int > (n, 0);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i;
		}
		nComp = n;
	}

	int find(int id) {
		if(id == par[id])
			return id;
		return par[id] = find(par[id]);
	}

	bool merge(int id1, int id2) {
		int p1 = find(id1);
		int p2 = find(id2);
		if(p1==p2) {
			return false;
		}
		if(rank[p1] > rank[p2]) {
			par[p2]=p1;
		}
		else if(rank[p1] < rank[p2]) {
			par[p1] = p2;
		}
		else {
			par[p1] = p2;
			rank[p2]++;
		}
		nComp--;
		return true;
	}
};


int main(){
    ifstream f1("castle.in");
    ofstream f2("castle.out");
    int N,M;
    f1>>M>>N;

    disjointSet set(N*M);


    /*set.merge(M*i+j,M*(i)+j+1); //merge east
    set.merge(M*i+j,M*(1+i)+(j)); //merge south
    set.merge(i*M+j,(j-1)*M+i); //merge west
    set.merge(M*i+j,(i-1)*M+(j)); //merge north*/

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            f1 >> tab[i][j];
            switch(tab[i][j]){
                case 0:
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(i*M+j,(i-1)*M+j); //merge west
                set.merge(M*i+j,(i)*M+(j-1)); //merge north
                break;

                case 1: //wall west
                set.merge(M*i+j,M*(i)+1+j); //merge east
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 2: //wall north
                set.merge(M*i+j,M*(i)+1+j); //merge east
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 3: //wall west & north
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(M*i+j,M*(i+1)+(j)); //merge south
                break;
                case 4: //wall east
                set.merge(M*i+j,M*(i+1)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 5: //wall east & west
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 6: //wall east & north
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 7: //wall east & north & west
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                break;
                case 8: //wall south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                set.merge(M*i+j,M*(i)+j+1); //merge east

                break;
                case 9: //wall south & west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                set.merge(M*i+j,M*(i)+j+1); //merge east
                break;
                case 10: //wall south & north
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 11: //wall south & north & west
                set.merge(M*i+j,M*(i)+j+1); //merge east
                break;
                case 12: //wall south & east
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                break;
                case 13: //wall south east west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                break;
                case 14: //wall south east north
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 15:
                break;

            }
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            switch(tab[i][j]){
                case 0:
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(M*i+j,M*(i)+(j-1)); //merge south
                set.merge(i*M+j,(i-1)*M+j); //merge west
                set.merge(M*i+j,(i+1)*M+(j)); //merge north
                break;

                case 1: //wall west
                set.merge(M*i+j,M*(i)+1+j); //merge east
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 2: //wall north
                set.merge(M*i+j,M*(i)+1+j); //merge east
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 3: //wall west & north
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(M*i+j,M*(i+1)+(j)); //merge south
                break;
                case 4: //wall east
                set.merge(M*i+j,M*(i+1)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 5: //wall east & west
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(M*i+j,(i-1)*M+(j)); //merge north
                break;
                case 6: //wall east & north
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 7: //wall east & north & west
                set.merge(M*i+j,M*(1+i)+(j)); //merge south
                break;
                case 8: //wall south
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                set.merge(M*i+j,M*(i)+j+1); //merge east

                break;
                case 9: //wall south & west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                set.merge(M*i+j,M*(i)+j+1); //merge east
                break;
                case 10: //wall south & north
                set.merge(M*i+j,M*(i)+j+1); //merge east
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 11: //wall south & north & west
                set.merge(M*i+j,M*(i)+j+1); //merge east
                break;
                case 12: //wall south & east
                set.merge(i*M+j,(i)*M+j-1); //merge west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                break;
                case 13: //wall south east west
                set.merge(M*i+j,(i-1)*M+(j)); //merge north*/
                break;
                case 14: //wall south east north
                set.merge(i*M+j,(i)*M+j-1); //merge west
                break;
                case 15:
                break;

            }
        }
    }

    fill_n(tab2,N*M,0);

    int largest=0;

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            tab2[set.par[i*M+j]]++;
            if(tab2[set.par[i*M+j]]>largest){
                largest=tab2[set.par[M*i+j]];
            }
        }
    }
    int largest2=largest,x,y;
    char z;
    for(int j=0;j<M;++j){
        for(int i=N-1;i>=0;--i){
            if(i!=0 && set.par[i*M+j]!=set.par[(i-1)*M+(j)] && largest2<tab2[set.par[i*M+j]]+tab2[set.par[(i-1)*M+(j)]]){
                largest2=tab2[set.par[i*M+j]]+tab2[set.par[(i-1)*M+(j)]];
                x=i+1;
                y=j+1;
                z='N';
            }
            if(j!=M-1 && set.par[i*M+j]!=set.par[(i)*M+(j+1)] && largest2<tab2[set.par[i*M+j]]+tab2[set.par[(i)*M+(j+1)]]){
                largest2=tab2[set.par[i*M+j]]+tab2[set.par[(i)*M+j+1]];
                x=i+1;
                y=j+1;
                z='E';
            }
        }
    }

    /*for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
        f2 << set.par[i*M+j] << "\t";
    }
    }
    f2<<endl;*/
    f2 << set.nComp << endl;
    //f2 << tab2[set.rank[11]]<<" "<<largest << endl;
    f2 << largest << endl;
    f2 << largest2 << endl;
    f2 << x << " " << y <<" " << z << endl;

    f1.close();
    f2.close();
    return 0;
}
