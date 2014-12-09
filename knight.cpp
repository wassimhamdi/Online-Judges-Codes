#include<iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

const int MX = 100;//set here maximum no of nodes
int graph[MX][MX];
const int oo = (int)1e9;

void warshal() {

	for (int k = 0; k < 64; ++k)
		for (int i = 0; i < 64; ++i)
			for (int j = 0; j < 64; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
void constructGraph(){

	for (int i = 0; i < 64 ;++i) {
		fill(graph[i], graph[i]+64+2, oo);
		graph[i][i] = 0;
	}

	for (int i = 0; i < 8; ++i)
	{
	    for (int j = 0; j <8; ++j){

            if (((i+1)>=0)&&((i+1)<=7)&&((j-2)<=7)&& ((j-2)>=0)){graph[8*i+j][8*(i+1)+j-2]=1;}

            if (((i-1)>=0)&&((i-1)<=7)&&((j-2)<=7)&& ((j-2)>=0)){graph[8*i+j][8*(i-1)+j-2]=1;}

            if (((i+1)>=0)&&((i+1)<=7)&&((j+2)<=7)&& ((j+2)>=0)){graph[8*i+j][8*(i+1)+j+2]=1;}

            if (((i-1)>=0)&&((i-1)<=7)&&((j+2)<=7)&& ((j+2)>=0)){graph[8*i+j][8*(i-1)+j+2]=1;}

            if (((i-2)>=0)&&((i-2)<=7)&&((j+1)<=7)&& ((j+1)>=0)){graph[8*i+j][8*(i-2)+j+1]=1;}

            if (((i-2)>=0)&&((i-2)<=7)&&((j-1)<=7)&& ((j-1)>=0)){graph[8*i+j][8*(i-2)+j-1]=1;}

            if (((i+2)>=0)&&((i+2)<=7)&&((j+1)<=7)&& ((j+1)>=0)){graph[8*i+j][8*(i+2)+j+1]=1;}

            if (((i+2)>=0)&&((i+2)<=7)&&((j-1)<=7)&& ((j-1)>=0)){graph[8*i+j][8*(i+2)+j-1]=1;}

            }
}
}


int main() {

    constructGraph();
    warshal();
    char ch1[3];
    string ch2;
    while(scanf("%s",ch1)!=EOF){
    cin>>ch2;
   int s,d;
   s=(ch1[0]-'a')+((int )ch1[1]-'0'-1)*8;
   d=(ch2[0]-'a')+((int )ch2[1]-'0'-1)*8;
/*for (int i=0;i<64;++i){
    for (int j=0;j<64;++j){

        cout <<graph[i][j];

    }
    cout<<endl;}*/


cout<<"To get from "<<ch1<<" to "<<ch2<< " takes "<<graph[s][d]<< " knight moves."<<endl;}



	return 0;
}
