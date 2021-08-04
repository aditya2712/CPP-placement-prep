#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    int i;
    for(i = 0;i< a.size();i++)
    {
        cout<<a[i]<<" ";
    }
  vector<int>::iterator j;
  j=a.begin();

        a.erase(j);
       for(i = 0;i< a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}
