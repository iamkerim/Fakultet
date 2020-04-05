#include <iostream>
using namespace std;

//Sabiranje dva broja sa pokazivačima

//Funkcija koja prima
void saberi(int *x, int *y, int *z){
*z = *x+*y;

}

void saberi(int &x, int &y, int &z){
    z=x+y;

}
int main(){
int a,b,c;

cout<<"Unesite dva broja: ";
cin>>a>>b;

//Prvi nacin, radit ce funkcija iz 7 linije koda
saberi(&a,&b,&c);
cout<<"c = "<<c<<endl;

//Drugi nacin, radit ce funkcija iz 12 linije koda
saberi(a,b,c);
cout<<"c = "<<c<<endl;

return 0;
}
