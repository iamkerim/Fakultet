#include <iostream>
#include <time.h>
using namespace std;

/*
    Napraviti program koji generise 20 slucajnih brojeva iz intervala
    10-50 u niz. Zatim napraviti funkciju koja ce ispisati samo slozene
    brojeve (brojevi koji nisu prosti).
    Ispisati pocetni niz i trazene brojeve.
*/

bool prost (int broj){
    int br=0;
    for(int i=2;i<broj/2;i++){
        if(broj%i==0){
            br++;
        }
    }
    if(br>0){
        return false;
    }else
        return true;
}

void slozeni (int niz[]){
cout<<"\nTrazeni brojevi:\n";
for(int i=0;i<20;i++){
    if(!prost(niz[i])){
    cout<<niz[i]<<" ";
    }
}

}
int main(){

srand(time(NULL));

int niz[20];

for(int i=0;i<20;i++){
    niz[i]=rand()%41+10;
}

cout<<"Pocetni niz:\n";
for(int i=0;i<20;i++){
    cout<<niz[i]<<" ";
}
slozeni(niz);

return 0;
}
