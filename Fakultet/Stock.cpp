#include <iostream>
using namespace std;
/*
    Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure. Potrebno je
    čuvati informacije o nazivu robe, broju skladišta, količini robe u skladištu, minimalnoj količinu
    (ako je količina robe jednaka ili manja od minimalne količine, to znači da treba pozvati
    dobavljača da se obezbijede efikasne zalihe robe), jediničnoj cijeni robe, i imenu dobavljača.
    Zatim napišite program koji sa tastature čita podatke o robama u skladištu, a nakon toga štampa
    izvještaj koji za svaki artikal prikazuje njegov naziv, broj skladišta, količinu u skladištu, te ime
    dobavljača za one artikle čija je količina u skladištu manja od dozvoljene količine.

*/

//struktura roba koja je napravljena na osnovu trazenih parametara
struct roba{
char naziv[15];
int brojSkladista;
int minKolicina;
int kolicina;
int cijena;
char dobavljac[25];
};

int main(){

//deklaracija varijable koja ce spremiti broj proizvoda (robe)
int brojPr;

//unos broja proizvoda
cout<<"Koliko robe zelite unijeti ? ";
cin>>brojPr;

//deklaracija strukture u main funkciji
roba roba1[brojPr];

//for petlja koja ide od 0 do unesenog broja proizvoda
for(int i=0;i<brojPr;i++){
//klasican unos strukture
    cout<<"\nROBA "<<i+1<<"\n-----------------\n";
    cin.ignore(256,'\n');
    cout<<"Unesite naziv robe: ";
    cin.getline(roba1[i].naziv,15);
    cout<<"Unesite broj skladista gdje se roba nalazi: ";
    cin>>roba1[i].brojSkladista;
    cout<<"Unesite minimalnu kolicinu robe: ";
    cin>>roba1[i].minKolicina;
    cout<<"Na stanju: ";
    cin>>roba1[i].kolicina;
    cout<<"Unesite jedinicnu cijenu robe: ";
    cin>>roba1[i].cijena;
    cin.ignore();
    cout<<"Unesite ime dobavljaca robe: ";
    cin.getline(roba1[i].dobavljac,25);
}

//pomocni char array koji sprema crte. Koristim ih za uredjivanje izvjestaja
char crta[] = "\n--------------------------------------------------\n";

//for petlja koja ide od prvog do zadnjeg elementa u strukturi
for(int i=0;i<brojPr;i++){
cout<<crta<<"\n\t\tIZVJESTAJ ZA ROBU "<<i+1<<endl<<crta<<endl;
cout<<"\tNaziv robe: "<<roba1[i].naziv<<endl;
cout<<"\tBroj skladista: "<<roba1[i].brojSkladista<<endl;
cout<<"\tKolicina robe: "<<roba1[i].kolicina<<" kg/g/kom"<<endl;

/*
    Ako je kolicina za robu do koje je dosla for petlja manja  od minimalne kolicine ispisat ce dobavljaca
    U suprotnom, ako je kolicina u redu, petlja ce nastaviti dalje i preci na sljedecu robu.

*/
if(roba1[i].kolicina<roba1[i].minKolicina){
    cout<<"\tDobavljac: "<<roba1[i].dobavljac<<endl;
}
}
return 0;
}
