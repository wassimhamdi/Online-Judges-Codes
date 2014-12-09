#include <iomanip>
#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int tab[300009];
    for(int i=n+1;i<=2*n;++i){
        cin>>tab[i];
    }
    for(int i=1;i<=n;++i){
        tab[i]=-tab[i+n];
        tab[i+2*n]=tab[i];
    }
    long somme=0;
    for(int i=1;i<=n;++i){
        somme+=tab[i];
    }
    long max=somme,i=1;
    for(int j=n+1;j<=3*n-1;++j){
        //cout<<somme<<" "<<max<<endl;
        somme=somme-tab[i]+tab[j];
        ++i;
        if(somme>max){
            max=somme;
        }
    }
    cout<<max<<endl;
    return 0;
}
