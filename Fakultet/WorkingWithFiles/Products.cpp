#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//pomocna struktura u koju cu smjestati podatke iz datoteke
struct proizvod{
    int cijena, kolicina;
    string naziv, proizvodac;
};

int main(){
    //pomocna varijabla za broj proizvoda
    int brojP=0;

    //pomocna varijabla za nalazenje proizvoda proizvođača FIAT
    string fiat="FIAT";

    //pomocna varijabla za broj proizvoda proizvođača FIAT
    int brojFIAT=0;

    //pomocna varijabla za ukupnu vrijednost proizvoda u prodavnici
    int vrijednost=0;

    //deklaracija varijabli koje su mi potrebne za citanje iz datoteke
    int cijena, kolicina;
    string naziv, proizvodac;

    /*
        ifstream iz razloga sto samo trebam da citam datoteku,
        naziv datoteke u programu (objekt), naziv datoteke koju zelimo otvoriti "proizvodi.txt".
    */
    ifstream objekt("proizvodi.txt");

    //ako je datoteka otvorena program radi
    if(objekt.is_open()){

        //sve dok iz datoteke cita podatke da radi
        while(objekt>>naziv>>proizvodac>>cijena>>kolicina){

            //ako je kraj jedne sekvence(linije u datoteci) broj proizvoda se povecava za 1
            if(objekt.end){
                brojP++;
            }

            //ako je cijena proizvoda veca od 0, ta cijena se dodaje na varijablu vrijednost
            if(cijena>0){
                vrijednost+=cijena;
            }

            /*
                Poređenje dva stringa, vraca 0 ako su isti.
                Ako su string proizvodac i moj string fiat ("FIAT") jednaki brojFIAT će se povećati za 1.
            */
            if(proizvodac.compare(fiat)==0){
                brojFIAT++;
            }
        }

        //nakon while petlje, odnosno nakon sto su se isčitali svi podaci iz datoteke, datoteka se zatvara.
        objekt.close();

    //Ako datoteka nije otvorena ispisat će se odgovarajuća poruka
    }else{
        cout<<"[GREŠKA] Datoteka nije otvorena!\n";
    }

    //ponovno otvaramo datoteku proizvodi.txt, sada ce se zvati struktura
    ifstream struktura("proizvodi.txt");

    //deklaracija strukture u glavnom programu, velicina je jednaka broju proizvoda
    proizvod pr1[brojP];

    //postavljanje iteratora i na 0;
    int i=0;

    //ako je datoteka otvorena radi
    if(struktura.is_open()){

        //sve dok iz datoteke cita podatke da radi
        while(struktura>>naziv>>proizvodac>>cijena>>kolicina){

            /*
                Svaka varijabla iz strukture uzima odovarajucu vrijednost iz datoteke.
            */
            pr1[i].naziv=naziv;
            pr1[i].proizvodac=proizvodac;
            pr1[i].cijena=cijena;
            pr1[i].kolicina=kolicina;

            //nakon svakog prolaza i se povecava za 1
            i++;
        }

        //kada se iscitaju svi podaci iz datoteke i upišu i strukturu, datoteka se zatvara.
        struktura.close();

    //ako datoteka nije otvorena, ispisuje odgovarajuću poruku
    }else{
        cout<<"[GREŠKA] Datoteka nije otvorena!\n";
    }

    //Ispis vrijednost izračunatih iznad
    cout<<"Ukupan broj proizvoda u datoteci je: "<<brojP<<endl;
    cout<<"Ukupna vrijednost svih proizvoda u prodavnici je: "<<vrijednost<<endl;

    cout<<"Spisak proizvoda cija je kolicina 0:\n-------------------------------\n";

    //for pelja ide od pocetka da kraja strukture (broj proizvoda)
    for(int i=0;i<brojP;i++){

        //ako je kolicina proizvoda do kojeg je dosla pelja jednaka 0
        if(pr1[i].kolicina==0){

            //ispisuje njegov naziv,proizvođača i cijenu
            cout<<pr1[i].naziv<<" "<<pr1[i].proizvodac<<" "<<pr1[i].cijena<<endl;
        }
    }
    cout<<"-------------------------------\n";


    //ispis broja proizvoda koje proizvodi FIAT
    cout<<"Broj proizvoda koje proizvodi FIAT: "<<brojFIAT<<endl;


    //soritanje strukture po cijeni proizvoda (selection sort)
    //iterator i ide od 0 do broja proizvoda
    for(int i=0;i<brojP;i++){

        //iterator j ide od i+1 do broja proizvoda
        for(int j=i+1;j<brojP;j++){

            //ako je proizvod prije imao manju vrijednost od onoga ispred, njihove vrijednost se mijenjaju.
            if(pr1[i].cijena<pr1[j].cijena){

                //mijenjaju se naziv,proizvođač,kolicina i cijena
                swap(pr1[i].naziv,pr1[j].naziv);
                swap(pr1[i].proizvodac,pr1[j].proizvodac);
                swap(pr1[i].kolicina,pr1[j].kolicina);
                swap(pr1[i].cijena,pr1[j].cijena);
            }
        }
    }

    cout<<"Spisak proizvoda sortiranih po cijeni (najveca-najmanja):\n-------------------------------\n";
    for(int i=0;i<brojP;i++){
        cout<<pr1[i].naziv<<" "<<pr1[i].proizvodac<<" "<<pr1[i].cijena<<" "<<pr1[i].kolicina<<endl;
    }
    cout<<"-------------------------------\n";
    return 0;
}


