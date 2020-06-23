#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    //otvaranje datoteke test.txt
    ifstream objekt("test.txt");

    //pomocna varijabla string, prazan string
    string red="";

    //ispis desifrovanog dokumenta u terminalu

    cout<<"Desifrovan dokument\n\n";

    //ako je datoteka test.txt otvorena
    if(objekt.is_open()){

        //radi sve dok ne dodje do kraja dokumenta
        while(! objekt.eof()){

            //do while petlja
            do{
                //uzima iz objekta svaki red(sifrirani tekst) i sprema u string red
                getline(objekt,red);

                //int varijabla n koja ima vrijednost cjelobrojnog korijena duzine sifriranog teksta
                int n = int(sqrt(red.length()) + 0.5);

                /*
                    Ako n na kvadrat nije jednak duzini teksta, to znaci da korijen nije cjelobrojan.
                    U tom slucaju ispisuje se odgovarajuca poruka.
                */
                if(pow(n,2)!=red.length()){

                    //ispis greske i prelazak na sljedecu liniju
                    cout<<"[GRESKA]\n";
                    continue;
                }


    //deklaracija 2D vektora duzine n*n tipa char
    vector<vector<char> > vec( n , vector<char> (n));

    //deklaracija pomocnog iteratora
    int k=0;

    //dvostruka for petlja za unos karaktera u vektor
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){

            //u vektor se unose karakteri iz stringa red
            vec[i][j] = red[k];
            k++;
        }
    }

    /*
        Sada kada imam smjestene karaktere u 2D vektor jednostavno mogu ispisati
        karaktere iz vektora ali tako da ih ispisujem po kolonama
        Na ovaj nacin cu dobiti desifrovanu poruku.
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout<<vec[j][i];
        }
    }

    //ispis praznog reda i nastavak petlje
    cout<<endl;

            //petlja se izvrsava sve dok ne dodje do kraja dokumenta
            }while(! objekt.end);
        }

    //ukoliko dokument nije otvoren ispisuje se odgovarajuca poruka
    }else{
        cout<<"[GRESKA] Datoteka nije otvorena!\n";
    }

    return 0;
}
