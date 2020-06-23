#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){

//otvaranje datoteke Podaci.txt
ofstream objekt("Podaci.txt");

//pomocne varijable u koje ce se spremati podaci iz datoteke
string ime,pol;
double godiste;
double prosjek;

//unos podataka u datoteku putem terminala
cout<<"Unesite podatke \tIME\tPOL(M/Z)\tGODISTE\t\tPROSJEK\n";
if(objekt.is_open()){
    //sve dok se unose podaci kako slijedi
    while(cin>>ime>>pol>>godiste>>prosjek){
        //datoteka prima te podatke
        objekt<<ime<<" "<<pol<<" "<<godiste<<" "<<prosjek<<endl;
    }

//nakon sto zatvorim terminal prestaje unos i zatvara se i datoteka
objekt.close();
}

//postavljanje brojaca za broj zenskih i muskih osoba
int brojacZ=0;
int brojacP=0;

//deklaracija stringa koji cu koristiti za poređenje
string temp1="Z";

//otvaranje datoteke Podaci.txt
ifstream provjera("Podaci.txt");

//ako je datoteka otvorena
if(provjera.is_open()){
    //radi sve dok cita podatke iz nje
    while(provjera>>ime>>pol>>godiste>>prosjek){
        //ako je string za pol jednak mom stringu ("Z")
        if(pol.compare(temp1)==0){
            //brojac za zene se povecava za 1
            ++brojacZ;
        }
        //ako je vrijednost prosjeka iz datoteke veca od 4.5 broj petica se povecava za 1
        if(prosjek>4.5){
            brojacP++;
        }
    }
    provjera.close();
}

//ispis odgovarajucih poruka u terminalu
cout<<"\n-----------------------------------\nBroj zenskih osoba: "<<brojacZ<<endl;
cout<<"Broj osoba sa prosjekom vecim od 4.50: "<<brojacP;

return 0;
}
