#include <iostream>
#include <cstring>
using namespace std;
/*
        Napišite generičku funkciju koja prima 4 parametra od kojih prva dva omeđuju jedan blok
        podataka a druga dva drugi blok podataka. Ovi parametri mogu biti bilo pokazivači bilo iteratori,
        pri čemu su prva dva istog tipa i druga dva također istog tipa, ali tipovi prva dva parametra i
        druga dva parametra ne moraju biti isti. Ova funkcija treba da pronađe da li se drugi blok nalazi
        kao podblok u prvom bloku (npr. blok {3, 5, 2} nalazi se kao podblok u bloku {1, 7, 3, 5, 2, 6}).
        Ukoliko se nalazi, funkcija kao rezultat vraća pokazivač/iterator na mjesto u prvom bloku na
        kojem se drugi blok nalazi kao podblok. Ukoliko se traženi blok nalazi na više mjesta kao
        podblok u prvom bloku, treba vratiti mjesto njegovog prvog pronalaska. Konačno, ukoliko
        traženi blok nije nađen kao podblok u prvom bloku, treba vratiti pokazivač/iterator koji pokazuje
        tačno iza kraja prvog bloka. Napišite i kratki isječak programa u kojem ćete demonstrirati kako
        se koristi napisana funkcija na dva fiksna niza stringova

*/

int funkcija(int niz1[], int l1, int niz2[], int l2){

//pomocna varijabla
int index;

//deklaracija iteratora i za pocetak su postavljeni na 0
int i=0, j=0;

/*
    Dok je i manje od duzine niza1 i j manje od duzine niza2 petlja radi
*/
while(i<l1 && j<l2){
        /*
            Petlja radi sve dok je element iz prvog niza jednak elementu iz drugog, kao i da je index koji se mijenja za
            niz2 manji od duzine svog niza, ako j bude jedanko l2,znaci da je niz2 provjeren i izlazi se iz petlje.
            i i j se uvecava za jedan da bi na taj nacin poredili elemente iz prvog niza i redom elemente iz drugog.
            Nakon svakog povecana iteratora provjerava se je li niz2 dosao do kraja, ako jeste vraca se vrijednost indexa
            koji predstavlja poziciju u nizu1 odakle pocinje niz2. Time zavrsava funkcija.
        */
    while(niz1[i]==niz2[j] && j<l2){
        i++;
        j++;
        if(j==l2){
            return index;
    }
    }

    /*
        Ukoliko se uslov nije ispunio i elementi iz niza1 nizu jedanki elementima iz niza2
        iterator i (iterator za niz1) cemo uvecati za jedan, da bi presao na sljedeci element,
        index će uzeti tu poziciju, a j(interator za drugi niz, onaj koji provjeravamo je li podblok)
        cemo vratiti na 0 da bi ponovno počeo od prvog elementa i provjeravao sve redom.
    */
        i++;
        index=i;
        j = 0;

    }

/*
    Ukoliko se desi da je iterator i(interator za niz1) dosao do kraja, odnosno postao jednak duzini niza1 (l1),
    prva petlja ce se zavrsiti, funkcija ce vratiti i, odnosno iterator koji se nalazi tacno iza prvog bloka,
    jer se u zadnjem prolazu u petlji pomjerio za jos jedno mjesto, i to predstavlja odgovarajuci output za slucaj
    da podblok nije pronađen.
*/
return i;
}


int main(){

//deklaracija duzina nizova
int l1,l2;

//unos duzine niza1
cout<<"Unesite duzinu prvog niza: ";
cin>>l1;

//deklaracija niza1
int niz1[l1];

//unos niza1
cout<<"\nUnesite prvi niz:\n";
for(int i=0;i<l1;i++){
    cout<<i+1<<". -> ";
    cin>>niz1[i];
}

//unos duzine niza2
cout<<"Unesite duzinu drugog niza: ";
cin>>l2;

//Ako za niz2 unesemo duzinu 1, odnosno da ima samo 1 element, program ispisuje gresku i zaustalja se.
if(l2==1){
    cout<<"\n[GRESKA] Drugi niz mora imati vise od jednog elemnta.\n";
    return 0;
}

//Ako je duzina niza1 manja od duzine niza2, program ispisuje gresku i zaustavlja se.
if(l1<l2){
    cout<<"\n[GRESKA] Prvi niz je manji od drugog.\n";
    return 0;
}

//deklaracija niza2
int niz2[l2];

//unos niza2
cout<<"\nUnesite drugi niz:\n";
for(int i=0;i<l2;i++){
    cout<<i+1<<". -> ";
    cin>>niz2[i];
}

/*
    Ako funkacija vraca vrijednost koja je veca od l1-1 (duzine prvog niza),
    to nam znaci da je to ispunjen drugi slucaj u funkciji i da podblok nije pronađen
    OUTPUT : vrijednost iteratora koji pokazuje tacno iza kraja prvog bloka
    Napomena: Iterator pocinje od 0.
*/
if(funkcija(niz1,l1,niz2,l2)>l1-1){
    cout<<"\nPodblok nije pronadjen.\n";
    cout<<"OUTPUT : "<<funkcija(niz1,l1,niz2,l2)<<endl;

/*
    U suprotnom program ispisuje odgovarajucu poruku i kao OUTPUT daje
    index, odnosno poziciju u prvom nizu odakle krece podblok (niz2).
    Napomena: Pozicije kreću od 0.

    Ovaj algoritam u funkciji radi i ako se podblok u nizu1 ponavlja vise puta.
    Funkcija ce vratiti onu poziciju gdje se prvi put pojavljuje, jer se funkcija zavrsava
    nakon sto nađe prvi blok.
*/
   }else{
    cout<<"\nPodblok je pronadjen.\n";
    cout<<"OUTPUT : "<<funkcija(niz1,l1,niz2,l2)<<endl;
    }
return 0;
}

/*
Niz1 : 4 3 6 7 3
Niz2 : 3 6 7

i - iterator za niz1
j - iterator za niz2

Rad funkcije:
1. Ulaz u prvu petlju jer su oba iteratora (i,j == 0) manja od duzine nizova

2. 4!=3, nije ispunjen uslov za drugu while petlju, iterator i se povecava za 1, index=1;

3. 3==3, ispunjen je uslov  za drugu while petlju, i i j se povecavaju za jedan, funkcija ne vraca nista
jer niz2 nije dosao do kraja (j!=l2)

4. 6==6, ispunjen je uslov  za drugu while petlju, i i j se povecavaju za jedan, funkcija ne vraca nista
jer niz2 nije dosao do kraja (j!=l2)

5. 7==7, i i j se povecavaju za 1, ispunjen je if(j==l2), funkcija vraca vrijednost indexa.

OUTPUT: 1

*/
