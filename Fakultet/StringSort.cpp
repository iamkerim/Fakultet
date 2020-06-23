#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;
/*
    Napišite program koji traži od korisnika da unese niz rečenica, pri čemu se broj rečenica
    prethodno unosi sa tastature. Za svaku unesenu rečenicu dinamički alocirajte prostor,
    uz vođenje evidencije o adresi svake alocirane rečenice u dinamičkom nizu pokazivača
    na početke svake od rečenica. Nakon toga, treba ispisati unesene rečenice sortirane u
    abecedni poredak (odnosno u poredak po ASCII kodovima). Sortiranje obavite ručno,
    bilo kojim postupkom koji Vam je poznat (drugim riječima, nemojte koristiti gotove
    funkcije za sortiranje, poput funkcije "sort„ iz biblioteke "algorithm".
*/


int main(){
//Unos broja recenica
int br;
cout<<"Unesite broj recenica: ";
cin>>br;

vector<string> vec;


for(int i=0;i<br+1;i++){
    string recenica;
    getline(cin,recenica);
    vec.push_back(recenica);
}

for(int i=1;i<vec.size();i++){
    cout<<vec[i]<<"\n";
}
vector<string> temp;
for(int i=1;i<vec.size();i++){
    for(int j=i+1;j<vec.size();j++){
        if(vec[i]>vec[j]){
            vec[i].pop_back(temp);
            vec[i]=vec[j];
            vec[j]=temp;
        }
    }
}

cout<<"\n\nNakon sortiranja: \n----------------------------\n";
for(int i=1;i<vec.size();i++){
    cout<<vec[i]<<"\n";
}
return 0;
}
