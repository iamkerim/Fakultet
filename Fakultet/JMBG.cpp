#include <iostream>
using namespace std;

/*
    Napisati funkciju koja kao argument uzima znakovno polje jmbg (jedinstveni maticni
    broj gradjanina) a kao izlaz vraca strukturnu varijablu koja predstavlja datum rodjenja
    doticne osobe. Prototip funkcije je: struct datum fdatum(char *jmbg) gdje struct
    datum predstavlja strukturu definisanu kao:
    struct datum {int dan;int mjesec;int godina;};
    Nakon toga napišite glavni program koji sa standardnog ulaza ucitava jmbg kao
    znakovno polje a nakon poziva funkcije fdatum() ispisuje datum rodjeja osobe sa
    doticnim jedinstvenim maticnim brojem.
*/

//deklaracija strukture koju ču koristiti u funkciji.
struct datum {
    int dan;
    int mjesec;
    int godina;
};

//funkcija
struct datum fdatum(char *jmbg){
/*
    Funkcija stoi konvertuje string(ili u ovom slucaju niz karaktera) u integer.
    S obzirom da je u moj char niz(jmbg) spremljeno prvih 7 karaktera JMBG-a, ako tih
    7 karaktera pretvorim u jedan integer vrlo lahko ću moći taj sedmocifren broj rasčlaniti
    na DD MM GGG, i na taj način dobiti datum rođenja.
*/
int matBroj=stoi(jmbg);

//deklaracija nove strukture
datum novi;

/*
    Rasčlanjivanje sedmocifrenog broja na DD MM GGG

*/
novi.godina=matBroj%1000;
novi.mjesec=(matBroj/1000)%100;
novi.dan=(matBroj/1000)/100;
/*
    Postavljeno je nekoliko uslova iz razloga da mogu kontrolisati ispis godine.
*/
if(novi.godina>900){
cout<<"Datum rodjenja: "<<novi.dan<<"."<<novi.mjesec<<"."<<novi.godina+1000<<".";
}else if(novi.godina<20 || 0){
cout<<"Datum rodjenja: "<<novi.dan<<"."<<novi.mjesec<<"."<<novi.godina+2000<<".";
}else if(novi.dan>31){
cout<<"Unijeli ste netacan JMBG.";
}else if(novi.mjesec>12){
cout<<"Unijeli ste netacan JMBG.";
}else {
cout<<"Unijeli ste netacan JMBG.";
}

//vraćanje strukture u glavni program
return novi;
};

int main(){
/*
    Kao što znamo JMBG ima 13 cifara, ali ću ja deklarisati char niz od duzine 8, jer mi
    je za određivanje datuma rođenja potrebno prvih 7 cifara.
    Korisnik može unijeti čitav JMBG, ali niz pamti samo prvih 7 cifara.
    U deklaraciji se navodi 8 mjesta iz razloga što imamo na 8-om mjestu karakter '\0',
*/
char *jmbg = new char[8];

//unos niza
cout<<"Unesite vas JMBG: ";
cin.getline(jmbg,8);

//poziv funkcije
fdatum(jmbg);

return 0;
}
