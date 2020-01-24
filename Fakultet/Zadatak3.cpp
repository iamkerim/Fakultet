#include <iostream>
using namespace std;
/*

    1)  Napraviti  program  u  kojem  se  od  korisnika  traži  da  broj  elemenata  niza  i  zatim  i  članove niza  koji  moraju  biti  parni.
    (Korisnik  unosi  članova  niza,  ako  je  taj  broj  neparan  traži  se ponovni unos tog  broja)
    Potrebno  je  sve  elemente  nizu  pomjeriti  za  jedno  mjesto  u  lijevo,  drugi  ide  na  prvo  mjesto, treći ide  na  drugo  mjesto, ...
    prvi član ide  na  posljednje mjesto.

*/
int main(){

int n;
cout<<"Unesite broj clanova niza: ";
cin>>n;

int niz[n];

cout<<"Unijeti clanove niza:\n";
for(int i=0;i<n;i++){
    naredba:cout<<"niz["<<i+1<<"] ";
    cin>>niz[i];
    if(niz[i]%2==1){
        cout<<"Broj nije paran!\n";
        goto naredba;;
    }
}

cout<<"\nUnijeti brojevi su:"<<endl;

for(int i=0;i<n;i++){
    cout<<niz[i]<<" ";
}


int last;
last=niz[0];

//prva opcija
/*int temp;
for(int i=0;i<n;i++){
    temp=niz[i+1];
    niz[i]=temp;
*/


//druga opcija
cout<<"\nNiz poslije zamjene:"<<endl;
for(int i=1;i<n;i++){
    cout<<niz[i]<<" ";
}

cout<<last;


return 0;
}
