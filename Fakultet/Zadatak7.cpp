#include <iostream>
#include <iomanip>
using namespace std;

/*
Program učitava sadržaj ovog niza, pri čemu je predmet cijeli broj između 1 i 10 (uključujući i ta dva). Treba naći srednju
vrijednost ocjene svakog predmeta ukoliko ga je polagao bar jedan student (bez obzira da li je student pao ili ne) i ispisati:
broj predmeta (2 karaktera), prosječna ocjena (6 karaktera, 2 decimale)
Ako neki predmet nije slušao niti jedan student, taj predmet se ne treba nalaziti na izlazu. Primjer unosa sa tastature:
ANTE    ANTIC   3   6

BORIS   ORUC    4   10

SULJO   SULJIC  8   5

MILEVA  MUJIC   3   5

MINKA   BUGIC   4   6

Za gore navedene podatke, izlaz treba da izgleda:
3   5.50
4   8.00
8   5.00
*/


//deklaracija strukture
struct student {
char ime[10];
char prezime[15];
int predmet;
int ocjena;
}studenti[100];

//funkcija za ispis
void funkcija(struct student st[], int n){
float sumaOcjena=0;
int br=0;
float prosjek;
int index;
int i,j;

for(j=1;j<=10;j++){
    for(i=0;i<n;i++){
        if(st[i].predmet==j){
            sumaOcjena+=st[i].ocjena;
            br++;
            index=i;
        }

    }
        if(sumaOcjena>0){
            prosjek=sumaOcjena/br;
            cout<<st[index].predmet<<"\t"<<setprecision(2)<<fixed<<prosjek<<endl;
            br=0;
            sumaOcjena=0;
            prosjek=0;
        }
}
}

int main(){
int n;
cout<<"Unesite broj studenata: ";
cin>>n;
student st[n];

//unos podataka za studente
for(int i=0;i<n;i++){
cout<<"Unesite ime "<<i+1<<". studenta: ";
cin>>st[i].ime;
cout<<"Unesite prezime "<<i+1<<". studenta: ";
cin>>st[i].prezime;
cout<<"Unesite predmet od 1 do 10 koji student polaze: ";
cin>>st[i].predmet;
cout<<"Unesite ocjenu iz tog predmeta: ";
cin>>st[i].ocjena;
}

//pozivanje funkcije
funkcija(st,n);

return 0;
}
