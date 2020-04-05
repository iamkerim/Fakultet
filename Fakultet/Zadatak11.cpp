#include <iostream>
using namespace std;

/*
    Program koji šestocifreni broj rastavlja na dva dijela, te računa zbir da dva trocifrena broja.
    Zatim, ako je suma trocifren broj, provjerava da li je palindorm.
    Ako je suma cetverocifren broj ispisuje zbir cifara tog broja.

    Npr. Input: 123456
    123 456
    123 + 456 = 579
    579 nije palindrom.
*/

int main(){
int broj;
do{
    cout<<"Unesite sesterocifreni broj: ";
cin>>broj;
if(broj<100000 || broj>999999){
    cout<<"[GRESKA] Uneseni broj nije sesterocifreni! \n";
}
}while(broj<100000 || broj>999999);

int prvi, drugi;

prvi=broj/1000;
drugi=broj%1000;

int suma;
suma=prvi+drugi;

cout<<"Broj "<<broj<<" rastavljen da dva dijela: "<<prvi<<" i "<<drugi<<".\n";

cout<<"Suma ova dva dijela iznosi: "<<suma<<".\n";

if(suma<1000){
    if(suma/100==suma%10){
        cout<<"Broj "<<suma<<" je PALINDROM.\n";
    }else{
        cout<<"Broj "<<suma<<" nije PALINDROM.\n";
}
}else {
    int sumica=0;
    while(suma>0){
        sumica+=suma%10;;
        suma=suma/10;
    }
    cout<<"Suma cifara iznosi: "<<sumica;
}
return 0;
}
