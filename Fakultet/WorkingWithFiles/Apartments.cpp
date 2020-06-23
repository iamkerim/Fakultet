#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

    //deklaracija strukture koja ce primiti podatke iz datoteke
    struct apartmani{
        string naziv,mjesto;
        int brojK,cijena;
    };

int main(){

    //pomocne varijable
    string naziv,mjesto;
    int brojK,cijena;
    int brojApartmana=0;
    int pomocnaCijena=0;
    double prosjek;
    int BAP=0;
    string lokacija("Paralia");

    //otvaranje datoteke apartmani.txt
    ifstream objekt("apartmani.txt");

    //ako je datoteka otvorena
    if(objekt.is_open()){
        //petlja radi sve dok ucitava podatke iz nje
        while(objekt>>naziv>>mjesto>>brojK>>cijena){
            //ako je kraj jedne linije u dokumentu broj apartmana se povecava za 1
            if(objekt.end){
                brojApartmana++;
            }

            //ako je cijena veca od 0 ukupna cijena se povecava za vrijednost cijene u datoteci
            if(cijena>0){
                pomocnaCijena+=cijena;
            }
            //ako je mjesto jednako "Paralia" broj apartmana u Paraliji se povecava za 1
            if(mjesto.compare(lokacija)==0){
                BAP++;
            }
        }
        //nakon sto iscita sve podatke iz datotoke datoteka se zatvara
        objekt.close();
    }

    //racunanje prosjecne cijene apartmana
    prosjek=pomocnaCijena/brojApartmana;

    //ponovno otvaranje datoteke
    ifstream provjera("apartmani.txt");

    //deklaracija strukture u glavnom funkciji
    apartmani a1[brojApartmana];

    //postavljanje iteratora i na 0
    int i=0;

    //ako je datototeka otvorena, sve dok cita podatke iz nje, sprema ih u funkciju
    if(provjera.is_open()){
        while(provjera>>naziv>>mjesto>>brojK>>cijena){
            a1[i].naziv=naziv;
            a1[i].mjesto=mjesto;
            a1[i].brojK=brojK;
            a1[i].cijena=cijena;
            i++;
        }
        provjera.close();
    }

    //deklaracija pomocne cijene koja uzima vrijednost prve cijene u strukturi
    int pCijena=a1[0].cijena;

    //pomocna varijabla
    int index;
    //prolazak kroz strukturu
    for(int i=0;i<brojApartmana;i++){
        //ako je broj kreveta veci ili jednak dva a cijena manja od pomocne cijene
        if(brojK>=2 && a1[i].cijena<pCijena){
            //taj index u strukturi preuzima varijabla index
            index=i;
        }
    }
    //deklaracija stringa apartmana sa najmanjom cijenom koji uzima naziv apartmana sa najmanjom cijenom za 2 osobe
    string ASNC=a1[index].naziv;

    //sortiranje apartmana po cijeni (najmanja-najveca)
    for(int i=0;i<brojApartmana;i++){
        for(int j=0;j<brojApartmana;j++){
            if(a1[i].cijena<a1[j].cijena){
                swap(a1[i].naziv,a1[j].naziv);
                swap(a1[i].mjesto,a1[j].mjesto);
                swap(a1[i].brojK,a1[j].brojK);
                swap(a1[i].cijena,a1[j].cijena);

            }
        }
    }

    //ispis odgovarajucih poruka u terminalu
    cout<<"Ukupan broj apartmana: "<<brojApartmana<<endl;
    cout<<"Prosjecna cijena apartmana u agenciji: "<<prosjek<<endl;
    cout<<"Broj apartmana u mjestu Paralia: "<<BAP<<endl;
    cout<<"Naziv apartmana za dvije osobe sa najmanjom cijenom: "<<ASNC<<endl;
    cout<<"Spisak apartmana sortiranih po cijeni (najmanja-najveca):\n----------------------------------\n";

    for(int i=0;i<brojApartmana;i++){
        cout<<a1[i].naziv<<" "<<a1[i].mjesto<<" "<<a1[i].brojK<<" "<<a1[i].cijena<<endl;
    }
    cout<<"----------------------------------\n";
    return 0;
}
