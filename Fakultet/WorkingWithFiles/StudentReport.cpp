#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

    //sturktura ucenik koja ima iste parametre kao i datoteka
    struct ucenik{
        string ime;
        double prosjek;
        int izostanci;
    };

int main(){
    //varijable u glavnom programu koje ce se koristiti da primaju podatke iz datoteke
    string ime;
    double prosjek;
    int izostanci;

    //otvaranje datoteka grupa1,grupa2,grupa3
    ifstream dat1("grupa1.txt");
    ifstream dat2("grupa2.txt");
    ifstream dat3("grupa3.txt");

    //postavljanje brojaca na 0
    int brojac=0;

    //ako je grupa1.txt otvorena
    if(dat1.is_open()){
        //cita podatke iz nje
        while(dat1>>ime>>prosjek>>izostanci){
            //kada dodje do kraja linije, brojac se povecava za 1
            if(dat1.end){
                brojac++;
            }
        }
        //zatvaranje datoteke
        dat1.close();
    //ukoliko datoteka nije otvorena ispisuje odgovarajucu poruku
    }else{
        cout<<"[GRESKA] Datoteka grupa1.txt nije otvorena!\n";
        return 0;
    }

    /*
        Otvara se druga datoteka (grupa2.txt)
        i postupak je isti, brojac se povecava za 1 svaki put kada je jedna linija iz datoteke procitana.
    */
    if(dat2.is_open()){
        while(dat2>>ime>>prosjek>>izostanci){
            if(dat2.end){
                brojac++;
            }
        }
        dat2.close();
    }else{
        cout<<"[GRESKA] Datoteka grupa2.txt nije otvorena!\n";
        return 0;
    }

    //otvara se treca datoteka(grupa3.txt), postupak je isti
    if(dat3.is_open()){
        while(dat3>>ime>>prosjek>>izostanci){
            if(dat3.end){
                brojac++;
            }
        }
        dat3.close();
    }else{
        cout<<"[GRESKA] Datoteka grupa3.txt nije otvorena!\n";
        return 0;
    }

    //Na ovaj nacin brojac je spremio ukupan broj studenata upisanih u grupa1,grupa2,grupa3
    ucenik uc1[brojac];


    //ponovno otvaranje datoteka
    dat1.open("grupa1.txt");
    dat2.open("grupa2.txt");
    dat3.open("grupa3.txt");

    //deklaracija interatora i i postavljanje istog na 0
    int i=0;

    //ako je grupa1.txt otvorena
    if(dat1.is_open()){
        //cita podatek iz nje
        while(dat1>>ime>>prosjek>>izostanci){

            //struktura uzima ime, prosjek i izostanke iz datoteke
            uc1[i].ime=ime;
            uc1[i].prosjek=prosjek;
            uc1[i].izostanci=izostanci;

            //i se povecava za jedan nakon svakog prolaza
            i++;
        }

        //zatvaranje datoteke
        dat1.close();
    //ispis poruke u slucaju da datoteka1 nije otvorena
    }else{
        cout<<"[GRESKA] Datoteka grupa1.txt nije otvorena.\n";
        return 0;
    }

    //ako je grupa2.txt otvorena radit ce
    if(dat2.is_open()){

        //sve dok ucitava podatke iz datoteke 2
        while(dat2>>ime>>prosjek>>izostanci){
            //struktura uzima te podatke i sprema u strukturu
            uc1[i].ime=ime;
            uc1[i].prosjek=prosjek;
            uc1[i].izostanci=izostanci;

            //iterator i se nastavlja povecavati za 1
            i++;
        }
        //zatvaranje datoteke
        dat2.close();
    //ukoliko se datoteka 2 nije otvorila ispisat ce odgovarajucu poruku
    }else{
        cout<<"[GRESKA] Datoteka grupa2.txt nije otvorena.\n";
        return 0;
    }

    //ako je grupa3.txt otvorena
    if(dat3.is_open()){
        //ucitavaju se podaci iz dokumenta u strukturu
        while(dat3>>ime>>prosjek>>izostanci){
            uc1[i].ime=ime;
            uc1[i].prosjek=prosjek;
            uc1[i].izostanci=izostanci;
            i++;
        }
    //poruka u slucaju ne otvaranja datoteke
    }else{
        cout<<"[GRESKA] Datoteka grupa3.txt nije otvorena.\n";
        return 0;
    }

    //zaokljucivnje ocjena na osnovu prosjeka
    for(int i=0;i<brojac;i++){
        //prolazi se kroz strukturu i prosjeke, te zaokruzuje prosjek na cijeli broj (zakljucne ocjene)
        uc1[i].prosjek=(int)round(uc1[i].prosjek);
    }

    //sortiranje prema zakljucnim ocjenama od najvece do najmanje (selection sort)
    for(int i=0;i<brojac;i++){
        for(int j=i+1;j<brojac;j++){
            //ako je prosjek iza manji od ovoga ispred
            if(uc1[i].prosjek<uc1[j].prosjek){
                //mijenjaju se imena na tim pozicijama
                swap(uc1[i].ime,uc1[j].ime);
                //prosjeci
                swap(uc1[i].prosjek,uc1[j].prosjek);
                //i izostanci
                swap(uc1[i].izostanci,uc1[j].izostanci);
            }
        }
    }

    //otvaranje novog dokumenta izvjestaj.txt u koji ce se upisati podaci
    ofstream izvjestaj("izvjestaj.txt");

    //ako je dokument izvjestaj otvoren radi
    if(izvjestaj.is_open()){

        //iterator i vracam na nulu, jer mi ponovo treba
        i=0;

        //deklaracija novog brojaca
        int br=0;

        //sve dok novi brojac ne dostigne vrijednost ukupnog broja ucenika petlja radi
        while(br!=brojac){

            //ako su izostanci veci ili jednaki 5
            if(uc1[i].izostanci>=5){
            //u izvjestaj se upisuje ime, zakljucena ocjena i da ucenik nije zadovoljio
            izvjestaj<<"Ime: "<<uc1[i].ime<<"\nZakljuceno: "<<uc1[i].prosjek<<"\nNije zadovoljio(Izostanci: "<<uc1[i].izostanci<<")"<<"\n---------------------\n";
            }
            //ako si izostanci manji od 5
            else{
            //u izvjestaj se upisuje ime, zakljucena ocjena i da je ucenik zadovoljio
            izvjestaj<<"Ime: "<<uc1[i].ime<<"\nZakljuceno: "<<uc1[i].prosjek<<"\nZadovoljio(Izostanci: "<<uc1[i].izostanci<<")"<<"\n---------------------\n";
            }

            //povecavanje iteratora i i brojaca za 1
            i++;
            br++;
        }

        //Ispis poruke u terminalu nakon sto se napravi datoteka izvjestaj.txt i sve prođe bez greške
        cout<<"Sve je u redu. Pogledati datoteku izvjestaj.txt\n";

    //Ispis poruke u slucaju da nije moguće otvoriti izvjestaj.txt
    }else{
        cout<<"[GRESKA]Nemoguće je otvoriti izvjestaj.txt\n";
        return 0;
    }

    return 0;
}
