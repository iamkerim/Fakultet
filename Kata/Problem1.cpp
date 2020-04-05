#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
/*
    The goal of this exercise is to convert a string to a new string where each character in the new string is "("
    if that character appears only once in the original string, or ")" if that character appears more than once in the original string.

    Examples:

    "din"      =>  "((("
    "recede"   =>  "()()()"
    "Success"  =>  ")())())"
    "(( @"     =>  "))(("

*/
int main(){

string str;
cout<<"Input string: ";
cin>>str;

transform(str.begin(), str.end(), str.begin(), ::tolower);

int lng=str.length();
int c=0;
string str2;

for(int i=0;i<lng;i++){

    for(int j=0;j<lng;j++){

        if(str[i]==str[j]){
            c++;
        }
        }
        if(c>=2){
            str2+=')';
        }else{
            str2+='(';
        }
        c=0;
    }
cout<<"Converted string:\n";
cout<<str2;
return 0;
}
