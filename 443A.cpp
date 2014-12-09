#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    set < char > ss;
    for(int i=0;i<(int)s.size();++i){
        if(s[i]>='a' && s[i]<='z')
            ss.insert(s[i]);
    }
    cout<<ss.size()<<endl;
    return 0;
}
