#include <iostream>
#include <time.h>
using namespace std;
    /*
        Unijeti broj elemenata nizai generisati elemente niza u intervalu 5-15.
        Ispisati "Novonastali niz" tako da svaki element u nizu bude suma prethodnih elemenata.
        npr. 5 6 7
        Novonastali niz: 5 11 18
    
    */
int main() {

srand(time(NULL));
int n;
cout<<"Unesite broj elementa niza: ";
cin>>n;
int niz[n];

for(int i=0;i<n;i++){
    niz[i]=rand()%11+5;
}

cout<<"Generisani niz je:\n";
for(int i=0;i<n;i++){
    cout<<niz[i]<<" ";
}

int suma=0;
cout<<"\nNovonastali niz je:\n";
for(int i=0;i<n;i++){

    suma=niz[i]+suma;
    cout<<suma<<" ";
}

return 0;
}
