#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    //otvaranje datoteke pismo.txt
    ifstream objekt("pismo.txt");

    //pomocne varijable
    string linija;
    char crta[]="----------------------------------------------";

    //a;
    cout<<"Ispis sadrzaja datoteke u terminalu\n"<<crta<<endl;

    //ako je datoteka otvoren
    if(objekt.is_open()){
        //sve dok cita rijeci iz datoteke
        while(objekt>>linija){

            //ispisuje ih u terminal
            cout<<linija<<" ";
        }

    //kada dodje do kraja datoteke, vise nece imati rijeci za citanje i onda zatvaram datoteku
    objekt.close();
    }

    //b) prepis datoteke u novu mijenjajuci mala i velika slova

    //ponvono otvaram datoteku pismo.txt
    objekt.open("pismo.txt");

    //pomocne varijable
    string text;
    int brojac=0;

    //stvaranje nove datoteke prepis.txt u koji ce bit smjesten prepis datoteke pismo.txt
    ofstream prepis("prepis.txt");

    //ako je datoteka prepis.txt otvorena
    if(prepis.is_open()){

        //ako je otvorena i datoteka pismo.txt
        if(objekt.is_open()){

            //sve dok ne dodje do kraja datoteke pismo.txt
            while(!objekt.eof()){

                //uzima red teksta i smjesta u string linija
                getline(objekt,linija);

                //dvije sljedece linije koda su potrebne pod c
                //u string tekst smjesta citavo pismo dodavajući linije
                text=text+linija;

                //brojac karaktera u pismu, povecava se za duzinu svake linije(reda) uzetog iz datoteke
                brojac=brojac+linija.length();

                //sada for petlja ide od pocetka do kraja linije(reda u datoteci)
                for(int i=0;i<linija.length();i++){

                    //ako je karakter u redu malo slovo
                    if(islower(linija[i])){
                        //taj isti karakter postaje veliko slove
                        linija[i]=toupper(linija[i]);
                        //i sprema se u datoteku prepis.txt
                        prepis<<linija[i];
                    //u slucaju da je karakter veliko slovo
                    }else{
                        //taj isti karakter postaje malo slovo
                        linija[i]=tolower(linija[i]);
                        //i smjesta je u datoteku prepis.txt
                        prepis<<linija[i];
                    }
                }
            }
            /*
                Kada prodje kroz sve redove citav tekst ce biti
                prepisan mijenjajuci mala i velika slova i ispisuje se odgovarajuca poruka u terminalu
            */
            cout<<endl<<endl<<crta<<"\nPrepis uspjesno izvrsen. Pogledati datoteku prepis.txt\n"<<crta;
        }
        //zatvaranje obije datoteke
        objekt.close();
        prepis.close();
    }

    //c
    cout<<"\n\nIspis sadrzaja datoteke unazad\n\n";

    //u proslom otvaranju datoteke u string text sam spremio citavo pismo i sada ga samo ispisujem unazad
    for(int i=brojac;i>=0;i--){
        cout<<text[i];
    }
    cout<<endl;

    //d) provjerava da li u datoteci ima rijeci koje su palindrom

    //otvaranje dototeke pismo.txt
    objekt.open("pismo.txt");

    //pomocne varijable
    string rijec;
    string line;
    string line_rev;

    cout<<"\n\nRijeci koje su palindromi u datoteci: ";

    //ako je datoteka otvorena
    if(objekt.is_open()){

        //cita rijeci iz datoteke i sprema u string rijec
        while(objekt>>rijec){
            //ako je duzina rijeci 1 nastavlja dalje (na sljedecu rijec)
            if(rijec.length()==1){
                continue;
            }
            //ako nije, string line uzima string rijec
            line=rijec;

            //string line_rev uzima string line
            line_rev=line;

            /*
                built-in funkcija za okretanje rijeci, sada line_rev postaje obrnuta
                Ako je line=Kerim, sada je line_rev=mireK
            */
            reverse(line_rev.begin(),line_rev.end());

            //ako je line jednako line_rev to znaci da je rijec palindorm. U tom slucaju je ispisuje u terminalu.
            if(line==line_rev){
                cout<<line<<" ";
            }
        };
        cout<<endl;
    }

    return 0;
}
