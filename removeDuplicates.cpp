#include<iostream>
using namespace std;

string duplicate(string s){
    if(s.length()==0)
    return "";
    char ch= s[0];
    string substring = duplicate(s.substr(1));
    if(substring[0] == ch)
    return substring;
    else
    {
        return (ch+substring) ;
    }    
}

int main(){
    string s= (duplicate("aaaaabbbbbdddcceffaaf"));
    cout<<s;
    return 0;
}