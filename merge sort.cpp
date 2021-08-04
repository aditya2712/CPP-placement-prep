#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int l, int r);
void mrge(int a[],int l,int m,int r);

void mergesort(int a[],int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        mrge(a,l,m,r);
    }
}

void mrge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1,n2=r-m;
    int lft[n1],rt[n2];
    for(i=0;i<n1;i++)
    {
        lft[i]=a[l+i];
    }
    for(i=0;i<n2;i++)
    {
        rt[i]=a[m+1+i];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2   )
    {
        if(lft[i]<rt[j])
        {
            a[k++]=lft[i++];
        }
        else
        {
            a[k++]=rt[j++];
        }
    }
    while(i<n1)
        a[k++]=lft[i++];
    while(j<n2)
        a[k++]=rt[j++];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
