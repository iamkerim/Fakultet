#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
/*
    Napisati program koji traži od korisnika da unese spisak riječi
    (broj riječi se prethodno unosi sa tastature), a zatim ispisuje na
    ekran prvu i poslednju riječ iz spiska po abecednom poretku,
    kao i popis svih unesenih riječi, ali bez ispisivanja duplikata (tj.
    bez ispisivanja riječi koje su se već jednom ispisale). Program
    realizirati korištenjem vektora stringova, odnosno vektora čiji
    su elementi tipa “string”.
*/


int main(){

//Deklaracija vektora i n - broja riječi u njemu
vector<string> v;
int n;

//Unos broja riječi
cout<<"Unesite broj rijeci: ";
cin>>n;

//Unos vektora
for(int i=0;i<n;i++){
    cout<<i+1<<". ";
    //pomoćna varijabla za unos riječi
    string temp;
    //unos riječi
    cin>>temp;
    //riječ šaljemo u vektor, pomoćna varijabla temp sada možemo ponovo pozvati u sljedećem prolasku kroz for petlju
    v.push_back(temp);
}


//ISPIS PRVE I POSLJEDNJE RIJEČI PO ABECEDNOM PORETKU

/*
    Deklaracija dvije string varijable, jedna će pohraniti prvu riječ po abecedi, a druga posljednju.
    I jedna i druga uzimaju prvu rijec iz vektora, kao referentnu vrijednost.
*/
string first=v[0];
string last=v[0];

//for petlja koja ide od početka do kraja vektora
for(int i=0;i<v.size();i++){
    //kroz v[i] prolaze sve riječi iz vektora, od prve do posljednje
    //ako je ta riječ do koje je petlja došla(v[i]) manja od prve, prva postaje ta riječ.
    if(v[i]<first) first=v[i];
    //ako je veca od posljednje, posljednja postaje ta riječ.
    if(v[i]>last)  last=v[i];
}

//Na ovaj nacin smo sigurno dobili prvu i posljednju riječ po abecedi iz unijetog vektora
//Ipis prve i posljednje riječi
cout<<"Prva: "<<first<<endl;
cout<<"Posljednja: "<<last<<endl;

//ISPIS BEZ DUPLIKATA
cout<<"Bez duplikata: "<<endl;
//For petlja koja ide od početka do kraja vektora
for(int i=0;i<v.size();i++){
    /*
        Ako je riječ do koje je došla for petlja različita od prve i različita od druge, ispisat će je.
        Ako uslov nije ispunjen(a to znači da je neka riječ iz vektora ista kao dvije prethodno ispisane)
        petlja će preći na sljedeću riječ.
        Na ovaj način će se ispisati samo riječi koje nisu vec prije ispisane. (Ispis bez duplikata)
    */
    if(v[i]!=first && v[i]!=last){
        cout<<v[i]<< " ";
    }
}

return 0;
}
