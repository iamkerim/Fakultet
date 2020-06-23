#include <iostream>
using namespace std;

/*
    Napišite program koji od korisnika traži da sa tastature unese rečenicu, a koji će zatim
    ispisati unesenu rečenicu bez prve riječi te rečenice. Unesena rečenica se smješta u
    klasični niz znakova (dakle, ne u promjenljivu tipa “string”). Za realizaciju zadatka
    koristiti isključivo pokazivačku aritmetiku. Nije dozvoljena upotreba funkcija iz
    biblioteka “cstring” niti “string”, kao ni upotreba indeksiranja (uključujući i njegovu
    trivijalnu simulaciju koja podrazumijeva pisanje “*(a + n)” umjesto “a[n]”).
*/


//funkcija za ispis
void ispis(char* recenica,int index){

/*
    Ova for petlja kreće od index+1, gdje je index mjesto gdje se nalazi prvi razmak u rečenici,
    odnosno kraj prve riječi, a dodajem +1 iz razloga da preskočim taj razmak, odnosno da mi
    ispis krene od druge riječi u rečenici, a ne od razmaka.
*/
for(int i=index+1;recenica[i]!='\0';i++){
    cout<<recenica[i];
}

}

int main(){

//Deklaracija recenice kao niza karaktera i pomoćne varijable index
char *recenica=new char[100];
int index;

//Unos rečenice
cout<<"Unesite recenicu: ";
cin.getline(recenica,100);

/*
    For petlja ide kroz niz karaktera sve do kraja niza.
    Kada dođe do prvog razmaka u nizu uzima index od te pozicije u nizu i završava for petlju.
*/
for(int i=0;recenica[i]!='\0';i++){
    if(recenica[i]==' '){
        index=i;
        break;
    }
}

//poziv void funkcije za ispis niza
ispis(recenica,index);

return 0;
}
