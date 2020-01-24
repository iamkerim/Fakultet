#include <iostream>
#include <cmath>
using namespace std;
    /*
    Korisnik unosi dva realna broja (double)
    potrebno je provjeriti koji broj ima veci decimalni dio
    u funkciji provjera koja ima povratni tip bool
    */

bool provjera(double a, double b){
double t1=abs(a), t2= abs(b);
    if(t1-int(t1)>t2-int(t2)){
        return true;
    }else{
        return false;
    }
}
int main(){
double a,b;

cout<<"Unesite prvi realan broj: ";
    cin>>a;
cout<<"Unesite drugi realan broj: ";
    cin>>b;

if(provjera(a,b)){
    cout<<"Broj "<<a<<" ima veci decimalni dio!";
}else{
    cout<<"Broj "<<b<<" ima veci decimalni dio!";

}




return 0;
}
