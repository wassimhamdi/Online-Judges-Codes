Skip to content
Sign up Sign in
Explore
Features
Enterprise
Blog

This repository
 Star 108  Fork 86 marioyc/Online-Judge-Solutions
 branch: master Online-Judge-Solutions / UVA / I / 100 - 3n+1.cpp
 marioyc on 24 Sep 2010 Todo lo que faltaba
0 contributors
Executable File  44 lines (30 sloc)  0.667 kb RawBlameHistory
#include <iostream>
#include <algorithm>

using namespace std;

int memo[1000000];

int f(long long n)
{
    if(n==1) return 1;

    if(n>=1000000)
    {
        if(n%2==0) return 1+f(n/2);
        else return 1+f(3*n+1);
    }

    if(memo[n]!=-1) return memo[n];

    int x;
    if(n%2==0) x=1+f(n/2);
    else x=1+f(3*n+1);
    memo[n]=x;
    return x;

}

int main(){

    int a,b,m;

    memset(memo,-1,sizeof(memo));

    while(cin>>a>>b)
    {
        m=0;
        for(int i=min(a,b);i<=max(a,b);i++) m=max(m,f(i));

        cout<<a<<" "<<b<<" "<<m<<endl;
    }

	return 0;
}
Status API Training Shop Blog About © 2014 GitHub, Inc. Terms Privacy Security Contact
