#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int mx;
    int mi;
};

struct Pair solve( int a[], int start, int end){
    struct Pair p;

    if(start == end){
        p.mi = a[start];
        p.mx= a[end];
        return p;
    }    

    if(start + 1 == end){
        p.mi = min(a[start], a[end]);
        p.mx = max(a[start], a[end]);
        return p;
    }

    int mid = (end-start)/2;

    struct Pair l, r;
    l = solve(a, start, mid);
    r = solve(a, mid+1, end);

    p.mi = min(l.mi, r.mi);
    p.mx = max(l.mx, r.mx);

    return p;
}

int main(){
    // find max and min of an array with minimum no. of comparisions ...
    // this method is known as tournament method (divide & conquer)
    int arr[] = {1, 9, 2, 3, 4};
    int len = sizeof(arr)/sizeof(int);
    struct Pair p = solve(arr, 0, len-1);
    cout<<p.mi<<" "<<p.mx;
    return 0;
}