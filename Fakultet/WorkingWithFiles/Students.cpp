#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;


int main(){
    //pomocne varijable
    string ime, prezime, jezik, broj;
    double ocjena;
    double prosjekE,prosjekN;
    double zbirE=0;
    double zbirN=0;
    int brojPetica=0;
    int brojUcenikaE=0;
    int brojUcenikaN=0;

    //pomocni stringovi za poređenje
    string njemacki="Njemacki";
    string engleski="Engleski";

    //ako je datoteka Ocjene.txt otvorena
    ifstream objekt("Ocjene.txt");

    //iz prvog reda objekta se uzima vrijednost i smjesa se u string broj (broj ucenika)
    getline(objekt,broj);

    //ako je objekat otvoren
    if(objekt.is_open()){
        //iz njega ucitava ime, prezime, jezik, ocjena
        while(objekt>>ime>>prezime>>jezik>>ocjena){

            //ako je ucitani string jezik jednak mom stringu njemacki
            if(jezik.compare(njemacki)==0){

                //onda zbirN se povecava za vrijednost ocjene
                zbirN=zbirN+ocjena;

                //broj ucenika koji uce njemacki se povecava za jedan
                brojUcenikaN++;
            }

            //ako je ucitani string jezik jednak mom stringu engleski, postupak je isti
            if(jezik.compare(engleski)==0){
                zbirE=zbirE+ocjena;
                brojUcenikaE++;
            }

            //ako je ucitana ocjena jednaka 5, broj petica se povecava za 1
            if(ocjena==5){
                brojPetica++;
            }
        }

        //kada zavrsi sa ucitavanjem podataka datoteka se zatvara
        objekt.close();

    //ispis odgovarajuce poruke ako datoteka nije otvorena
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
        return 0;
    }

    //racunanje prosjeka za predmet Engleski jezik
    prosjekE=zbirE/brojUcenikaE;

    //racunanje prosjeka za predmet Njemacki jezik
    prosjekN=zbirN/brojUcenikaN;

    //ispis potrebnih informacija
    //setprecision i fixed koristim da bi zaokruzio prosjek na dvije decimale
    cout<<"Prosjecna ocjena iz engleskog jezika je: "<<setprecision(2)<<fixed<<prosjekE<<endl;
    cout<<"Prosjecna ocjena iz njemackog jezika je: "<<setprecision(2)<<fixed<<prosjekN<<endl;
    cout<<"Ukupan broj petica je: "<<brojPetica<<endl;

    return 0;
}
