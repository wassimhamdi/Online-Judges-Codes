#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long double billet[10];

int n=10;

long double recurs(long double v, int j){

        long double reste,quot,ntot,i;

        ntot=0;

//       cout<<v/billet[j]<<endl;
        int a=floor(v/billet[j]);
        cout<<a;
        quot=(double)(a);
    //cout<<"quot="<<quot<<endl;
        for (i=quot; i>=0;i--)
        {
            reste=v-i*billet[j];
            if(reste==0){ntot+=1;}
            else if(j<n-1){ntot=ntot+recurs(reste,j+1);}
        }
        return ntot;
        }





    int main()
    {



        long double v;
        cin>>v;

        billet[0]=100;
billet[1]=50;
billet[2]=20;
billet[3]=10;
billet[4]=5;
billet[5]=2;
billet[6]=1;
billet[7]=0.5;
billet[8]=0.2;
billet[9]=0.1;
billet[10]=0.05;

        cout<<recurs(v,0)<<endl;
        return 0;
    }
