#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[20];
    cin>>str;
    stack<char> s;
    int i,flag=0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            {
                s.push(str[i]);
                continue;
            }
        if(s.empty())
        {
            flag=1;
            break;
        }
        switch(str[i])
        {
            case ']':
                if(s.top()=='{'||s.top()=='(')
                    {
                        flag=1;
                    }
                break;
            case '}':
                if(s.top()=='['||s.top()=='(')
                    {
                        flag=1;
                    }
                break;
            case ')':
                if(s.top()=='['||s.top()=='[')
                    {
                        flag=1;
                    }
                break;
            default :
            s.push(str[i]);
        }
        s.pop();
        if(flag==1)
            break;
    }
    if(s.size()!=0)
        flag=1;
    if(flag==0)
        cout<<"balanced\n";
    else
        cout<<"Not balanced\n";
}
