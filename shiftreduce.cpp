#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <deque>


using namespace std;



char reduce(deque<char> v,bool isAnd)
{
    if(isAnd)
    {
        for (int i=0; i<v.size(); ++i)
            if (v[i]=='F')
                return 'F';
        return 'T';
    }
    else
    {
        for (int i=0; i<v.size(); ++i)
            if (v[i]=='T')
                return 'T';
        return 'F';
    }
}

int main()
{

    int k=0;
    while(true)
    {

        string str;
        cin >> str;
        if(str.compare("()")==0) break;

        int l1=0,l2=0;
        for (int i=0;i<str.size();++i)
        {
            if(str[i]=='(')
                l2++;
            if(str[i]==')')
                l2--;
            l1=max(l1,l2);
        }
        int deepestlv=l1;


        stack<char> chaine,st;
        for (int i=str.size()-1; i>=0; --i)
            chaine.push(str[i]);



        int cntParentheseOuvrante;
        if(deepestlv%2==1)
            cntParentheseOuvrante=0;
        else
            cntParentheseOuvrante=1;
        while(!chaine.empty())
        {
            while(chaine.top()!=')')
            {
                if(chaine.top()=='(') cntParentheseOuvrante++;
                st.push(chaine.top());
                chaine.pop();
            }
            st.push(chaine.top());
            chaine.pop();

            deque<char> d;
            while(st.top()!='(')
            {
                d.push_front(st.top());
                st.pop();
            }
            st.pop();

            if(cntParentheseOuvrante%2==1)
                st.push(reduce(d,true));
            else
                st.push(reduce(d,false));

            cntParentheseOuvrante--;
        }
        k++;
        if(st.top()=='F')
            cout << k <<". " <<"false" << endl;
        else
            cout << k <<". " <<"true" << endl;
    }






    return 0;
}
