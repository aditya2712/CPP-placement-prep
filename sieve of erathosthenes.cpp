//algorithm to find all primes smaller than n
//n should be smaller then 1 million(10^6)

#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long n;
    cin>>n;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    long long p,i;
    for(p=2;p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            for(i=p*p;i<=n;i+=p)
            {
                prime[i]=false;
            }
        }
    }
    cout<<endl;
    for(i=2;i<=n;i++)
    {
        if(prime[i]==true)
            cout<<i<<" ";
    }
}
