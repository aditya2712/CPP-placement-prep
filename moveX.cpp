#include<iostream>
using namespace std;
string moveX(string s){
    if(s.length()==0){
        return "";
    }
    char ch= s[0];
    string substring= moveX(s.substr(1));
    if(ch=='x')
    return substring+'x';
    else
    {
        return ch+substring;
    }
    
}

int main(){
    cout<<moveX("abcxsodcksxx");
}