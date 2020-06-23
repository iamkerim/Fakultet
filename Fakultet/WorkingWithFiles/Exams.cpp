#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
    //deklaracija strukture koja ce primiti podatke iz datoteke
    struct Student{
        int indeks;
        int predmet;
        int ocjena;
    };

int main(){
    //otvaranje dokumenta ispiti.txt
    ifstream objekt("ispiti.txt");
    //pomocne varijable
    int br=0;
    int indeks, predmet, ocjena;
    //ako je datoteka otvorena
    if(objekt.is_open()){
        //cita podatke iz nje ovim redom
        while(objekt>>indeks>>predmet>>ocjena){
            //ako je kraj jednog reda
            if(objekt.end){
                //brojac se povecava za jedan, na ovaj nacin cu dobiti broj ispita
                br++;
            }
        }
    //zatvaranje dokumenta
    objekt.close();
    //ispis odgovarajuce poruke ukoliko dokument nije otovren
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
    }
    //ponovno otvaranje datoteke ispiti.txt
    objekt.open("ispiti.txt");

    //deklaracije strukture u glavnoj funkciji, velicine broja ispita
    Student s1[br];

    //deklaracija iteratora i
    int i=0;

    //ako je dokument otvoren
    if(objekt.is_open()){
        //cita podatke iz njega ovim redom
        while(objekt>>indeks>>predmet>>ocjena){
            //smjestanje podataka u strukturu
            s1[i].indeks=indeks;
            s1[i].predmet=predmet;
            s1[i].ocjena=ocjena;
            i++;
        }
    objekt.close();
    }

    //deklaracija broja ispita
    int broj;

    //ispis mogucnih predmeta
    cout<<"[1]Uvod u tehnike programiranja\n";
    cout<<"[2]Napredne tehnike programiranja\n";
    cout<<"[3]Elektrotehnika\n";
    cout<<"[4]Operativni sistemi\n";
    cout<<"[5]Matematika\n";

    cout<<"Unesite broj predmeta ->";

    //unos broja predmeta mora biti u opsegu od 1 do 5
    do{
        cin>>broj;
    }while(broj<1 || broj>5);

    //deklaracija pomocnih varijabli
    float suma=0;
    float brojProlaza=0;
    float izlaznost=0;

    //prolatak kroz strukturu for petljom
    for(int i=0;i<br;i++){
        //ako je predmet jednak broju koji smo izabrali
        if(s1[i].predmet==broj){
            //racuna sumu ocjena tog predmeta
            suma=suma+s1[i].ocjena;

            //povecava brojac za izlaznost za 1
            izlaznost++;

            //ako je ocjena veca od 5 znaci da je student polozio predmet
            if(s1[i].ocjena>5){
                //broj prolaza se povecava za jedan(studenti koji su polozili)
                brojProlaza++;
            }
        }
    }


    //ako je broj jedan 1 ispis ogovarajuceg predmeta, prosjeka iz predmeta, i postotak studenata koji su polozili predmet
    //ponavlja se isto za svaki predmet
    if(broj==1){
        cout<<"Prosjecna ocjena iz predmeta Uvod u tenike programiranja je "<<setprecision(2)<<fixed<<suma/izlaznost;
        cout<<"\nProlaznost je "<<(brojProlaza/izlaznost)*100<<"%";
    }
    if(broj==2){
        cout<<"Prosjecna ocjena iz predmeta Napredne tehnike programiranja je "<<setprecision(2)<<fixed<<suma/izlaznost;
        cout<<"\nProlaznost je "<<(brojProlaza/izlaznost)*100<<"%";
    }
    if(broj==3){
        cout<<"Prosjecna ocjena iz predmeta Elektrotehnika je "<<setprecision(2)<<fixed<<suma/izlaznost;
        cout<<"\nProlaznost je "<<(brojProlaza/izlaznost)*100<<"%";
    }
    if(broj==4){
        cout<<"Prosjecna ocjena iz predmeta Operativni sistemi je "<<setprecision(2)<<fixed<<suma/izlaznost;
        cout<<"\nProlaznost je "<<(brojProlaza/izlaznost)*100<<"%";
    }
    if(broj==5){
        cout<<"Prosjecna ocjena iz predmeta Matematika je "<<setprecision(2)<<fixed<<suma/izlaznost;
        cout<<"\nProlaznost je "<<(brojProlaza/izlaznost)*100<<"%";
    }

    //unos broja indeksa
    int br_indeks;
    cout<<"\nUnesite broj indeksa studenta za kojeg zelite informacije:";
    cin>>br_indeks;

    //pomocne varijable
    float sumaOcjena=0;
    float brojPolozenih=0;
    float brojIzlazaka=0;

    //prolazak kroz strukturu for petljom
    for(int i=0;i<br;i++){

        //ako je indeks u strukturi jednak unesenom indeksu
        if(s1[i].indeks==br_indeks){
            //za tog studenta racuna sumu ocjena i povecava brojac za izlazak na ispit za 1
            sumaOcjena=sumaOcjena+s1[i].ocjena;
            brojIzlazaka++;

            //ako je student polozio predmet povecava broj polozenih ispita za 1
            if(s1[i].ocjena>5){
                brojPolozenih++;
            }
        }
    }

    //ispis broja indeksa,broj izlazaka, broj polozenih predmeta,procenat prolaznosti i prosjek za studenta
    cout<<"\nBroj indeksa: "<<(int)br_indeks<<endl;
    cout<<"Broj izlazaka na ispit: "<<(int)brojIzlazaka<<endl;
    cout<<"Broj polozenih predmeta: "<<(int)brojPolozenih<<endl;
    cout<<"Prolaznost: "<<(brojPolozenih/brojIzlazaka)*100<<"%\n";
    cout<<"Prosjecna ocjena: "<<sumaOcjena/brojIzlazaka<<endl;
    return 0;
}
