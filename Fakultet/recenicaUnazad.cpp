#include <iostream>
#include <vector>
using namespace std;

int main(){

    string recenica;
    cout<<"Unesite string: ";
    getline(cin,recenica);
    vector <string> rijeci;
    string temp;

    for(int i=0;i<recenica.length();i++){

        if(recenica[i]!=' '){
        temp=temp+recenica[i];
        }

        if(recenica[i]==' '){
            rijeci.push_back(temp);
            temp="";
        }
    }
    rijeci.push_back(temp);

    cout<<"String unazad: ";
    for(int i=rijeci.size()-1;i>=0;i--){
        cout<<rijeci[i]<<" ";
    }

    cout<<endl;
    return 0;
}

