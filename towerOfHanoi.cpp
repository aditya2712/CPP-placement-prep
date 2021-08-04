#include<iostream>
using namespace std;
 
void towerOfHanoi(int n, char src, char dest, char helper){
    if(n==0)
    return;

    towerOfHanoi(n-1, src, helper, dest);
    cout<<"move block from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, src);
}

int main(){
    towerOfHanoi(7, 'A', 'C', 'B');
}