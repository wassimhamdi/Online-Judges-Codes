#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tab[5][5];
bool check(){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            int x=tab[i][j]+tab[i+1][j]+tab[i+1][j+1]+tab[i][j+1];
            if(x==2 || x==-2 || x==4 || x==-4)
                return true;
        }
    }
    return false;
}
int main(){
string s;
for(int i=0;i<4;++i){
    cin>>s;
    for(int j=0;j<4;++j){
        if(s[j]=='#')
            tab[i][j]=-1;
        else
            tab[i][j]=1;
    }
}
bool verif=check();
if(verif)
    cout << "YES" << endl;
else
    cout << "NO" << endl;
}
