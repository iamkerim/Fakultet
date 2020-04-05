#include <iostream>
#include <string.h>
using namespace std;

/*
    Program koji provjerava da li je email adresa iz Bosne i Hercegovine.
*/



//deklaracija funkcije
int ispravna(char *adresa){

//brojac za @ postavljen na 0
int et=0;
int duzina= strlen(adresa);
//for petlja koja ide kroz adresu i trazi znak @, te brojac et povecava za 1
for(int i=0;i<strlen(adresa);i++){
    if(adresa[i]=='@'){
        et++;
    }
}

//for petlja koja prolazi kroz adresu
for(int i=0;i<strlen(adresa);i++){

/*  Ako je et=0 (što znaci da ima samo jedan znak @), zadnji karakter u adresi 'a', predzadnji 'b' i treci od kraja '.',
    to znaci da nam je adresa oblika ime@domena.ba, što predstavlja email adresu Bosne i Hercegovine i u tom slucaju
    funkcija ce vratiti vrijednost 1, u svakom drugom slucaju to će biti 0

*/
if(et==1 && adresa[strlen(adresa)-1]=='a' && adresa[strlen(adresa)-2]=='b' && adresa[strlen(adresa)-3]=='.'){
    //oslobađanje memorije
    delete []adresa;
    return 1;
}else
    //oslobađanje memorije
    delete []adresa;
    return 0;}
}

int main(){

//deklaracija pointera kao niza karaktera koristenjem dinamicke memorije
char *adresa=new char[30];

//unos adrese
cout<<"Unesite adresu: ";
cin.getline(adresa,30);

//ispis onoga što će vratiti funkcija "ispravna"
cout<<ispravna(adresa);

return 0;
}
