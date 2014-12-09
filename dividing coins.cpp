#include < cstdio >
#include < iostream >
#include < algorithm >

int main(){
    int t,n,tab[101];
    int dp[50008]
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>tab[i];
       for ( int j = 0; j < o; j++ ) {
            for ( int i = 502; i >= 0; i-- ) {
                if ( weight [j] <= i && dp [i] < dp [i - weight [j]] + val [j] )
                    dp [i] = dp [i - weight [j]] + val [j];

            }

        }
    }
return 0;
}
