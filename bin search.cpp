#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int n,int look);

int main()
{
    int n;
    cin>>n;
    int a[n],i,look;
    cout<<"\n Input sorted array";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\n number to be searched:";
    cin>>look;
    int ans=binarysearch(a,n,look);
    cout<<endl<<ans+1;
}

binarysearch(int a[],int n,int look)
{

    int s=0,l=n-1,mid=s+(l-s)/2;
    while(l>=s){
    if(look == a[mid])
    {
        return mid;
    }
    if(look>a[mid])
    {
        s=mid+1;
    }
    else
    {
        l=mid-1;
    }
    mid=s+(l-s)/2;
    }
    return -2;
}
