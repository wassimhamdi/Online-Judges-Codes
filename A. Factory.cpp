#include <iostream>

using namespace std;

int main()
{
    int a,m,q;
    cin >> a >> m;
    q=a%m;
    while(q < m){
        q=q*2;
        if(q%m==0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
