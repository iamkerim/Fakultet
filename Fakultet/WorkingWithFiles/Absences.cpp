#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//fukcija koja racunar broj izostanaka, prima niz sa izostancima i duzinu niza (a)
void brojIzostanaka(int niz[], int a){
    //pomocna varijabla za sumu
    int suma=0;

    //prolazak od pocetka do kraja niza i sabiranje izostanaka
    for(int i=0;i<a;i++){
        suma=suma+niz[i];
    }
    //ispis odgovarajuce poruke
    cout<<"Ukupan broj neopravdanih izostanaka je: "<<suma<<endl;
}

//funkcija koja racuna prosjek izostanaka
void prosjekIzostanaka(int niz[], int a){
    //pomocne varijable
    double suma=0;
    double prosjek;

    //racunanje sume
    for(int i=0;i<a;i++){
        suma=suma+niz[i];
    }

    //racunanje prosjeka
    prosjek=suma/a;

    //ispis odgovarajuce poruke, setprecision i fixed iz razloga zaokruzivanja prosjeka na 2 decimale
    cout<<"Prosjecan broj neopravdanih izostanaka je: "<<setprecision(2)<<fixed<<prosjek<<endl;
}

//funkcija koja ispisuje najveci broj izostanaka
void najveciBrIzostanaka(int niz[], int a){
    //deklaracija maks varijable koja uzima prvi broj u nizu
    int maks=niz[0];
        //prolazak kroz niz
        for(int i=0;i<a;i++){
            //ukoliko je clan niza veci od maks
            if(niz[i]>maks){
                //maks postaje zaj clan niza
                maks=niz[i];
            }
        }
    //ispis odgovarajuce poruke
    cout<<"Najveci broj izostanaka je: "<<maks<<endl;
}

//funkcija za pronalazak broja ucenika bez izostanaka
void bezIzostanaka(int niz[], int a){
    //deklaracija brojaca i postavljanje istog na 0
    int brojac=0;

    //prolazak kroz niz
    for(int i=0;i<a;i++){
        //ako je element u nizu jedank 0
        if(niz[i]==0){
            //brojac se povecava za 1
            brojac++;
        }
    }
    //ispis odgovarajuce poruke
    cout<<"Broj ucenika bez izostanaka je : "<<brojac<<endl;
}

int main(){

    //otvaranje datoteke Izostanci.txt
    ifstream objekt("Izostanci.txt");

    //deklaracija pomocnih varijabli za duzinu niza i brojeve koji se ucitavaju iz datoteke
    int duzinaNiza=0;
    int broj;

    //ako je datototeka otvorena
    if(objekt.is_open()){
        //sve dok ucitava brojeve
        while(objekt>>broj){
            //duzina niza se povecava za 1
            duzinaNiza++;
        }
    //zatvaranje datoteke
    objekt.close();
    //ispis odgovarajuce poruke
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
        return 0;
    }

    //deklaracija niza u koji cu smjestiti izostanke iz datoteke
    int *niz=new int[duzinaNiza];

    //ponovno otvaranje dokumenta Izostanci.txt
    ifstream unos("Izostanci.txt");

    //ako je dokument otvoren
    if(unos.is_open()){
        //deklarisem pomocne varijable
        int i=0;
        int num;
        //sve dok i nije jednak duzini niza i dok ucitava brojeve iz datoteke
        while(i!=duzinaNiza && unos>>num){
            //niz prima te brojeve
            niz[i]=num;
            //i povecava i za 1
            i++;
        }
    //isis odgovarajuce poruke ukoliko datoteka nije otvorena
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
        return 0;
    }

    //poziv funkcija, sve funkcije su tipa void
    brojIzostanaka(niz,duzinaNiza);
    prosjekIzostanaka(niz,duzinaNiza);
    najveciBrIzostanaka(niz,duzinaNiza);
    bezIzostanaka(niz,duzinaNiza);

    //nakon sto se funkcije izvrse dealociram niz
    delete[] niz;
    return 0;
}
