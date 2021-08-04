#include<iostream>
using namespace std;
int firsto(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]== key)
    return i;
    return firsto(arr, n, i+1, key);
}
int last(int arr[], int n, int i, int key){
    if(i==n)
    return -1;
    int restarr = last(arr, n, i+1, key);
    if(restarr != -1){
        return restarr;
    }
    if(arr[i] == key){
        return i;
    }
    return -1;

}
int main(){
    int arr[]={1,4,3,1,5,3};
    cout<<firsto(arr, 6, 0, 2);
    cout<<endl;
    cout<<last(arr, 6,0,2);
}