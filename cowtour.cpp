/*
ID: kiruayo1
PROG: cowtour
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include<iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;
int n;
double graph[160][160];
pair <int,int> tab[160];
int matrix[160][160],tab1[160],tab2[160];

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

double maxi(int i, disjointSet set){
    double max=0;
    for(int j=0;j<n;++j){
        if(set.find(i)==set.find(j) && graph[i][j]>max){
            max=graph[i][j];
        }
    }
    return max;
}

void warshal(){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

int main(){
    ifstream f1("cowtour.in");
    ofstream f2("cowtour.out");

    f1>>n;
    disjointSet set=disjointSet(n);
    for(int i=0;i<n;++i){
        int a,b;
        f1>>a>>b;
        tab[i]=make_pair(a,b);
    }
    char w;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            f1>>w;
            if(w=='\n'){
                f1>>w;
            }
            if(w=='0'){
                graph[i][j]=1<<28;
            }
            else{
                set.merge(i,j);
                graph[i][j]=sqrt(pow(tab[i].first-tab[j].first,2)+pow(tab[i].second-tab[j].second,2));
            }
        }
    }


    for(int i=0;i<n;++i){
        graph[i][i]=0;
    }
    double max1=0;

    warshal();

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(graph[i][j]!=1<<28 && graph[i][j]>max1){
                max1=graph[i][j];
            }
        }
    }

    double diamin=1<<28;

    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(set.find(i)!=set.find(j)){
                double max2=maxi(i,set),max3=maxi(j,set);
                if(max2+max3+sqrt(pow(tab[i].first-tab[j].first,2)+pow(tab[i].second-tab[j].second,2))<diamin){
                    diamin=max2+max3+sqrt(pow(tab[i].first-tab[j].first,2)+pow(tab[i].second-tab[j].second,2));
                }
            }
        }
    }


    f2<<fixed;
    if(diamin>max1){
        f2<<setprecision(6)<<diamin<<endl;
    }
    else{
        f2<<setprecision(6)<<max1<<endl;
    }
    return 0;
}
/*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            f2 << graph[i][j]<<"\t";
        }
        f2<<endl;
    }*/
/*
8
10 10
15 10
20 10
15 15
20 15
30 15
25 10
30 10
01000000
10111000
01001000
01001000
01110000
00000010
00000101
00000010
*/
