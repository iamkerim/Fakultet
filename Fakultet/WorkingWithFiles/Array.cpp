#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
    //otvaranje datoteke ulaz.txt
    ifstream duzina("ulaz.txt");
    //deklaracija pomocnih varijabli
    int broj;
    int duzinaNiza;
    //ako je datoteka otvorena
    if(duzina.is_open()){
        //ucitava se broj iz datoteke
        while(duzina>>broj){
            //i sprema u varijablu duzinaNiza
            duzinaNiza=broj;
        }
    duzina.close();
    //ako se datoteka ne otvori ispise odgovarajucu poruku.
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
        return 0;
    }

    //alokacija dinamickog niza duzine duzinaNiza (broj ucitan iz datoteke ulaz.txt)
    double *niz=new double[duzinaNiza];

    //unos elemenata niza
    cout<<"Unesite elemente niza:\n";
    for(int i=0;i<duzinaNiza;i++){
        cout<<i+1<<". ";
        cin>>niz[i];
    }

    //pomocne varijable za racunanje prosjeka
    double zbir=0;
    double prosjek;

    //racunanje zbira svih elemenata niza
    for(int i=0;i<duzinaNiza;i++){
        zbir+=niz[i];
    }

    //racunanje prosjeka
    prosjek=zbir/duzinaNiza;

    /*
        Alociranje novog dinamicnog niza koji ce imati duzinu duzinaNiza+1,
        iz razlog sto u njega moram smjestiti i izracunat prosjek svih elemenata niza.
    */
    double *noviNiz=new double[duzinaNiza+1];

    //for petlja koja ide kroz prvi niz
    for(int i=0;i<duzinaNiza;i++){
        //svaki element prvog niza se smjesta u novi dinamicki niz
        noviNiz[i]=niz[i];
    }

    //na zadnje mjesto u nizu se dodjeljuje vrijednost prosjeka
    noviNiz[duzinaNiza]=prosjek;

    //dealociranje prvog niza, jer vise nije potreban
    delete[] niz;

    //soritanje novog niza (selection sort)
    for(int i=0;i<duzinaNiza+1;i++){
        for(int j=i+1;j<duzinaNiza+1;j++){
            /*
                Ako je element iza veci od ovoga ispred zamjenit ce mjesta,
                na ovaj nacin se dobiva sortiran niz po rastucem redoslijedu.
            */
            if(noviNiz[i]>noviNiz[j]){
                swap(noviNiz[i],noviNiz[j]);
            }
        }
    }

    //stvraranje nove datoteke Izlaz.txt u koju ce biti ispisan sortirani niz sa prosjek
    ofstream izlaz("Izlaz.txt");

    //postavljanje iteratora i na 0
    int i=0;

    //ako je datotetka otvorena
    if(izlaz.is_open()){

        //ispis odgovarajuce poruke u datoteku
        izlaz<<"Sortirani niz sa prosjekom:\n";

        //sve dok i nije jednako duziniNiza+1 (duzina novog niza u kojem se nalazi prosjek)
        while(i!=duzinaNiza+1){

            //u datoteci se ispisuju elementi niza niza
            izlaz<<noviNiz[i]<<" ";

            //i se povecava za jedan dok se ne ispuni uslov
            i++;
        }

    //ispis odgovarajuce poruke nakon sto su svi sortirani elementi novog niza spremljeni u datoteku Izlaz.txt
    cout<<"Program izvrsen. Pogledati Izlaz.txt\n";
    izlaz.close();
    //ukoliko datoteta nije otvorena ispisuje se odgovarajuca poruka
    }else{
        cout<<"[GRESKA] Datotetka Izlaz.txt nije otvorena!\n";
    }

    //dealokacija novog niza, jer je spremljen u datotetku
    delete[] noviNiz;

    return 0;
}
