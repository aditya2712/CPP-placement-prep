#include<iostream>
using namespace std;

void printpi(string s){
    if(s.length() == 0)
    return;
    if(s[0]=='p' && s[1]== 'i' )
    {
        cout<<"3.14";
        return printpi(s.substr(2));
    }
    cout<<s[0];
    return printpi(s.substr(1));
}

int main(){
    printpi("pixxxpixxpxxiw");
}