#include <iostream>
using namespace std;

/*
    Napraviti funkciju koja uneseni niz brojeva sortira (od najmanjeg do najveceg) i ispisuje ga.
*/

void sortiranje(int niz[],int a){
int temp;
for(int i=0;i<a;i++){
    for(int j=i+1;j<a;j++){
        if(niz[j]<niz[i]){
            temp=niz[j];
            niz[j]=niz[i];
            niz[i]=temp;
        }
    }
}

for(int i=0;i<a;i++){
    cout<<niz[i]<<" ";
}


}
int main(){
int a;

cout<<"Unesite duzinu niza:" ;
cin>>a;
int niz[a];

cout<<"Unesite niz:";
for(int i=0;i<a;i++){
    cin>>niz[i];
}

cout<<"Soritrani niz:\n";
sortiranje(niz,a);

return 0;
}
