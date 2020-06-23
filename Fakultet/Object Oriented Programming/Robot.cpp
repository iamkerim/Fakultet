#include <iostream>
using namespace std;

//deklaracija klase
class Robot{
//varijable
double X,Y,ugao;

public:
//metoda koja definise varijable za robota
Robot(double x, double y, double u){
    X=x;
    Y=y;
    ugao=u;
}

//metoda za kretanje naprijed, nazad i za ispis
void IdiNaprijed(double pomak);
void IdiNazad(double pomak);
void Ispisi() const;

//metoda okreni se na lijevo koja prima ugao i dodaje na postojeci ugao tu velicinu jer je orijentacija u odnosu na x osu
void OkreniSeNaLijevo(double ug){
    ugao=ugao+ug;
    Ispisi();
    }

//metoda koja okrece robota na desno, oduzima ugao jer je orijentacija u odnosu na x osu
void OkreniSeNaDesno(double ug){
    ugao=ugao-ug;
    Ispisi();
}

//metoda koja vraca x kooridnatu
int DajPozicijuX() const{
    return X;
    Ispisi();
    }

//metoda koja vraca y koordinatu
int DajPozicijuY() const{
    return Y;
    Ispisi();
    }

//metoda koja vraca ugao
int DajOrijentaciju() const{
    return ugao;
    Ispisi();
    }

};

//ispis koordinata i ugla za robota
void Robot::Ispisi() const{
cout<<"Robot se nalazi na poziciji "
    <<"("<<X<<","<<Y<<") i gleda pod uglom od "<<ugao<<" stepeni u odnosu na x osu.\n";
}

//kretanje robota naprijed nazad u zavisnosti gdje se nalazi mijenja se vrijednost X i Y
void Robot::IdiNaprijed(double pomak){
if(ugao>0 && ugao<90){
X+=pomak;
Y+=pomak;
}
if(ugao>90 && ugao<180){
    X-=pomak;
    Y+=pomak;
}
if(ugao>180 && ugao<270){
    X-=pomak;
    Y-=pomak;
}
if(ugao>270 && ugao<360){
    X+=pomak;
    Y-=pomak;
}

if(ugao==0){
    X+=pomak;
}

if(ugao==90){
    Y+=pomak;
}

if(ugao==180){
    X-=pomak;
}

if(ugao==270){
    Y-=pomak;
}

if(ugao==360){
    X+=pomak;
}

Ispisi();
}

//metoda za kretanje robota nazad u zavisnosti gdje se nalazi
void Robot::IdiNazad(double pomak){
if(ugao>0 && ugao<90){
    X-=pomak;
    Y-=pomak;
}
if(ugao>90 && ugao<180){
    X+=pomak;
    Y-=pomak;
}
if(ugao>180 && ugao<270){
    X+=pomak;
    Y+=pomak;
}
if(ugao>270 && ugao<360){
    X-=pomak;
    Y+=pomak;
}

if(ugao==0){
    X-=pomak;
}

if(ugao==90){
    Y-=pomak;
}

if(ugao==180){
    X+=pomak;
}

if(ugao==270){
    Y+=pomak;
}

if(ugao==360){
    X-=pomak;
}

Ispisi();
}

int main(){

//deklaracija varijabli
double a,b,c;

//unos koordinata robota
cout<<"Unesite pocetnu poziciju robota:\n";
cout<<"X = ";
cin>>c;
cout<<"Y = ";
cin>>b;
cout<<"Ugao = ";
cin>>c;

//prosljeđivanje koordinata u metodu
Robot r(a,b,c);

//pomocne varijable
int izbor;
double pomak;

//meni
do{
    do{
    //ispis menija
cout<<"Opcije:\n";
cout<<"[1] Idi naprijed\n";
cout<<"[2] Idi nazad\n";
cout<<"[3] Okreni se na lijevo\n";
cout<<"[4] Okreni se na desno\n";
cout<<"[5] Daj orijentaciju\n";
cout<<"[6] Daj poziciju na X osi\n";
cout<<"[7] Daj poziciju na Y osi\n";
cout<<"[8] Izlaz\n";

//unos izbora te pozivanje odgovarajuce metode
cout<<"\Izbor: ";
cin>>izbor;
    if(izbor==1){
        cout<<"Unesite pomak: ";
        cin>>pomak;
        r.IdiNaprijed(pomak);
    }
    if(izbor==2){
        cout<<"Unesite pomak: ";
        cin>>pomak;
        r.IdiNazad(pomak);
    }
    if(izbor==3){
        double ug;
        cout<<"Pod kojim uglom? ";
        cin>>ug;
        r.OkreniSeNaLijevo(ug);
    }
    if(izbor==4){
        double ug;
        cout<<"Pod kojim uglom? ";
        cin>>ug;
        r.OkreniSeNaDesno(ug);
    }
    if(izbor==5){
        cout<<"Orijentacija u odnosu na X osu: "<<r.DajOrijentaciju()<<" stepeni\n\n";

    }
    if(izbor==6){
        cout<<"Pozicija na X osi: "<<r.DajPozicijuX()<<endl<<endl;

    }
    if(izbor==7){
        cout<<"Pozicija na Y osi: "<<r.DajPozicijuY()<<endl<<endl;

    }
    if(izbor==8){
        cout<<"Hvala i dovidjenja!\n";
    }
    }while(izbor!=8);
}while(izbor<1 || izbor>8);


return 0;
}
