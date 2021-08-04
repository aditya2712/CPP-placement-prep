#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={6, 7 ,8};
    int *p=a;
    for(int i=0;i<3;i++)
    {
        cout<<*(p+i)<<" ";
    }

}
