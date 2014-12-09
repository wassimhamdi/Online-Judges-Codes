
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<int> availableWeight;
    for (int i=0; i<10; ++i)
        if(s[i]=='1')
            availableWeight.insert(i+1);
    int m;
    cin >> m;
    vector<int> v;


    for (set<int>::iterator it1=availableWeight.begin(); it1!=availableWeight.end(); ++it1)
    {
        bool nothingFoundForThisStart=false;
        int s1=*it1;
        int s2=0;
        v.push_back(s1);

        for (int i=0; i<m-1; ++i)
        {

            bool hasFoundWeightToAdd=false;
            for (set<int>::iterator it=availableWeight.begin(); it!=availableWeight.end(); ++it)
            {
                if(i%2==0)//addin weight to the right pan
                {
                    if((*it!=v[v.size()-1]) && (s2+(*it)>s1))
                    {
                        s2+=*it;
                        v.push_back(*it);
                        hasFoundWeightToAdd=true;
                        break;
                    }
                }
                else //adding weight to the left pan
                {
                    if((*it!=v[v.size()-1]) && (s1+(*it)>s2))
                    {
                        s1+=*it;
                        v.push_back(*it);
                        hasFoundWeightToAdd=true;
                        break;
                    }
                }
            }
            if(!hasFoundWeightToAdd) {
                    nothingFoundForThisStart=true;
                    break;
            }
        }

        if(!nothingFoundForThisStart) break;


        v.clear();
    }


    if(availableWeight.empty())
        cout << "NO" << endl;
    else
    {
        if(v.size()!=m)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i=0; i<m-1; ++i)
                cout << v[i] << " ";
            cout << v[m-1] << endl;

        }
    }







    return 0;
}
