#include<bits/stdc++.h>
using namespace std;
void show(int a[]);
void show(int a[])
{

    int i;
    for(i=0;i<10;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int a[10]={1,4,3,5,6,7,8,2,9,0};
    show(a);
    cout<<endl;
    sort(a,a+10);
    show(a);
}
