#include<bits/stdc++.h>
using namespace std;

int issquare(int n)
{
    int a[n+1+1],l=0,r=n+1,mid=l+(r-l)/2;
    while(l<=r)
    {
        if((mid*mid==n))
            return mid;
        if(mid*mid>n)
            r=mid-1;
        else
            l=mid+1;
        mid=l+(r-l)/2;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    cout<<issquare(n);
}
