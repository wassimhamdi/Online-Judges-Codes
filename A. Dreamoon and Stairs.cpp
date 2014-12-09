#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int res;
    cin >> n >> m;
    if(n%2==0)
        res=n/2;
    else
        res=n/2+1;
    while(res<n && res%m!=0)
        res+=1;
    if(res%m==0)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
