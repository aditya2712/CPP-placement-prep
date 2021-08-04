#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void solve(int a[], int n){
    int mid = 0, i;
    for(i=0;i<n;i++){
        if(a[i]<0){
            swap( &a[i], &a[mid] );
            mid++;
        }
    }
}

// Seperate all negative and positive elements of a given array (order is not important)

int main(){
    int a[] = {-1, -12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(a)/sizeof(int);
    cout<<n<<endl;
    for(int i =0; i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    solve(a, n);
    for(int i =0; i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}