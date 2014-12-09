#include <iostream>
#include <map>

using namespace std;

int main()
{
    string tab[7];
    int price;
    string mark[7];
    string s;
    map <string,int> m;
    map <string,int> index;
    map <string,int> name;
    int l=1;
    for(int i=0;i<6;++i){
        cin >> tab[i];
        cin >> mark[i];
        cin >> price;

        if(!index[mark[i]]){
            index[mark[i]]=price;
        }
        else
            index[mark[i]]=min(index[mark[i]],price);

        m[mark[i]]++;

    }
    int mx=1000002;
    int mx2=0;
    for(int i=0;i<6;++i){
        if(m[mark[i]]>mx2){
            mx2=m[mark[i]];
            mx=index[mark[i]];
            s=mark[i];
        }
        if(m[mark[i]]==mx2){
            if(index[mark[i]]<mx){
                mx2=m[mark[i]];
                mx=index[mark[i]];
                s=mark[i];
            }
        }
    }
    cout << s <<endl;

    return 0;
}
