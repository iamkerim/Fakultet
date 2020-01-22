#include <iostream>
#include <time.h>
using namespace std;

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
