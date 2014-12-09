#include <bits/stdc++.h>
using namespace std;

    int dp[10][10][10];
    int poww[10];
    int newcom[10];
    int n,result;

  int solve(int p,int c,int d){
    int power=poww[p];
    int coming=c+newcom[p];
    if(p==n-1)
        return power*coming;
    if(dp[p][c][d]!=-1)
        return dp[p][c][d];
    result=0;
    int md=min(d,coming);
    for(int i=0;i<md;++i){
    result=max(result,solve(p+1,i,d-i)+(coming-i)*power);
    }
    dp[p][c][d] = result;
    return result;

  }
int main ()
{
    for(int i=0;i<5;++i){
        poww[i]=i;
        newcom[i]=i;
    }
    int d=10;
    cout << solve(0,0,d) << endl;
}
