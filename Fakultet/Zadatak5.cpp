#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
    Generisati 15 slucajnih brojeva u niz iz intervala [13,88]. Potrebno je zatim razvrstati brojeve u dva nova niza
    parni i neparni.
    Ispisati pocetni niz,  i dva novodobijena niza
*/

int main(){

srand(time(NULL));


int niz[15],bP=0,bN=0;

for(int i=0;i<15;i++){
    niz[i]=rand()%76+13;
    if(niz[i]%2==0){
        bP++;
    }else
    {
        bN++;
    }
}

int nizP[bP], nizN[bN];

bP=0;
bN=0;

for(int i=0;i<15;i++){
    if(niz[i]%2==0){
        nizP[bP]=niz[i];
        bP++;
    }else{
        nizN[bN] = niz[i];
        bN++;
    }
}

cout<<"Pocetni niz:\n";
for(int i=0;i<15;i++){
    cout<<niz[i]<<" ";
}

cout<<"\nParni niz:\n";
for(int i=0;i<bP;i++){
    cout<<nizP[i]<<" ";
}

cout<<"\nNeparni niz:\n";
for(int i=0;i<bN;i++){
    cout<<nizN[i]<<" ";
}

return 0;
}






