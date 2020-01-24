#include <iostream>
#include <time.h>
using namespace std;
/*
        Korisnik prvo unosi broj elemenata a zatim i elemente niza. Potrebno je uraditi sljedece:
        -varijable a i b predstavljaju dimenzije nizova.
        -maksElement(niz,velNiza) - funkcija koja vraca vrijednost maksimalnog elementa niza, tip je double.
        -veci(niz1,niz2,velNiz1,velNiz2) - funkcija koja provjerava koja maksimalna vrijednost elementa od prosljeđenih nizova
         je veca. Ako prvi niz ima veci max element vraca true, ako je to drugi niz vraca false.
        -printaj(niz,velNiz) - funkcija koja ispisuje niz i odvaja svaki broj sa zarezom.
        -mijenjaj(niz,clan,broj)- funkcija koj u nizu pronalazi prosljeđeni clan i mijenja ga sa brojem koji smo proslijedili.


    */
int a,b;

double maksElement(double niz[], int velNiz){
double maks=niz[0];

for(int i=0;i<velNiz;i++){
    if(niz[i]>maks){
        maks=niz[i];
    }
}
return maks;
}

bool veci(double niz1[], double niz2[], int velNiz1, int velNiz2){
    double maks1=niz1[0];
    double maks2=niz2[0];

    for(int i=0;i<velNiz1;i++){
        if(niz1[i]>maks1){
            maks1=niz1[i];
        }
    }

    for(int i=0;i<velNiz2;i++){
        if(niz2[i]>maks2){
            maks2=niz2[i];
        }
    }

    if(maks1>maks2){
        return true;
    }else
        return false;

}

void printaj (double niz[], int velNiz){

cout<<"Niz prije promjene:\n";
    for(int i=0;i<velNiz-2;i++){
        cout<<niz[i]<<", ";
    }

    for(int i=velNiz-2;i<velNiz;i++){

        if(i==velNiz-2){
            cout<<niz[i];
        }else
        cout<<" i "<<niz[i]<<".";
    }
}

void mijenjaj (double niz[], int clan, int broj) {
    int temp;
    cout<<"\nNiz poslije zamjene:\n";

    for(int i=0;i<a;i++){


        if(i==a-2){
            for(int i=a-2;i<a;i++){
                if(i==a-2){
                cout<<niz[i];
        }else{
        cout<<" i "<<niz[i]<<".";
            break;
            }
            }
            break;
        }

        if(i!=clan-1){
            cout<<niz[i]<<", ";
        }else{
            temp=niz[i];
            niz[i]=broj;
            cout<<niz[i]<<", ";
        }
    }

}
int main(){

cout<<"Unesite duzinu prvog niza: ";
cin>>a;
double niz1[a];
for(int i=0;i<a;i++){
    cout<<i+1<<". clan: ";
    cin>>niz1[i];
}

cout<<"\nUnesite duzinu drugog niza: ";
cin>>b;
double niz2[b];
for(int i=0;i<b;i++){
    cout<<i+1<<". clan: ";
    cin>>niz2[i];
}

cout<<"Maksimalni element prvog niza je: "<<maksElement(niz1,a);
cout<<"\nMaksimalni element prvog niza je: "<<maksElement(niz2,b);

if(veci(niz1,niz2,a,b)){
    cout<<"\nPrvi niz ima veci maksimalni element. ";
}else
    cout<<"\nPrvi niz nema veci maksimalni element. ";


int clan,broj;

cout<<"\nUnesite redni broj elementa koji zelite zamjeniti: ";
cin>>clan;
cout<<"\nUnesite vrijednost sa kojom zelite zamjeniti taj element: ";
cin>>broj;
printaj(niz1,a);
mijenjaj(niz1,clan,broj);

return 0;
}
