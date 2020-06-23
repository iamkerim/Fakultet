#include <iostream>
#include <cstring>
using namespace std;

/*
    Funkcija koja briše višak spaceova u recenici
    Prima dva niza karaktera, input(neuređeni) i
    output (prazan koji ce vratiti kao uređeni niz karaktera, bez spaceova)
    Oba niza su char pointer jer kada se vrsi promjena u void funkciji da bude
    prepoznata u citavom programu.
*/
void remove_extra_spaces(char* input, char* output)
{
    /*
        Postavljanje dva iteratora na 0.
        inputIndex - prolazi kroz prosljeđeni char array
        outputIndex - prolazi kroz uređeni char array
    */
    int inputIndex = 0;
    int outputIndex = 0;

    /*
        For petlja koja ide od nule do kraja neuređenog niza
        Pomocu nje cemo izbrisati spaceove koji se nalaze ispred recenice(ako ih ima)
    */
    for(int i=0;i<strlen(input);i++){
        //ako se nalazi space na poziciji  u nizu povecavamo iterator inputIndex
        if(isspace(input[i])){
            inputIndex++;
        /*
            Kada petlja dođe do prvog slova u recenici, a time uslov iznad nece biti ispunjen,
            zavrsit ce se i inputIndex ce imati vrijednost onu na kojoj se nalazi prvo slovo u recenici.
        */
        }else
        break;
    }

    /*
        While petlja koja počinje od mjesta gdje se nalazi nas inputIndex, prvo slovo u recenici.
        Uslov je postavljen tako da se petlja vrti sve dok ne dođe do kraja stringa
    */
    while(input[inputIndex] != '\0')
    {
        //U novi char array smjestamo slova iz neuređenog niza
        output[outputIndex] = input[inputIndex];

        //provjeravamo da li se u neuređenom nizu na inputIndex poziciji nalazi space
        if(input[inputIndex] == ' ')
        {
        /*
            Ako se nalazi onda provjeravamo da li poslije tog spacea ima jos jedan
            Ukoliko nakon tog spacea ima jos jedan povecavamo inputIndex(iterator za neuređeni niz) za jedan
            Na ovaj ako cemo dobiti to da ako imamo 5 spaceova između rijeci u recenici, ostat ce nam samo jedan,
            jer ce se inputIndex povecavati sve dok ne dođe do prvog slova sljedece rijeci u recenici.

            Npr. Kerim    je programer.
            Kada petlja dođe do spacea poslije slova m(inputIndex ima vrijednost 6)
            i if (48. linija koda) prepozna da se na toj poziciji nalazi space,
            while petlja ce provjeriti da li poslije tog spacea ima jos jedan space,
            ako ima inputIndex se povecava za jedan i na taj nacin cemo dobiti to da će na kraju while petlje
            inputIndex imat vrijednost 9 i na taj način smo preskočili 4 space i sveli ih na jedan koji je već
            upisan u novi uređeni char array.
        */
            while(input[inputIndex + 1] == ' ')
            {
                inputIndex++;
            }
        }

        /*
            Nakon while petlje povecavamo outputIndex za 1 da bi mogli smjestiti sljedeće slovo u
            output ili novi uređeni niz.
            inputIndex također povećavamo za 1 da bi provjerili sljedeci karakter u neuređenom char arrayu.

        */
        outputIndex++;
        inputIndex++;
    }

    // Na kraju na novi uređeni niz, bez duplih spaceova, dodajemo oznaku za kraj char arraya.
    output[outputIndex] = '\0';


    /*
        Kada se ova funkcija zavrsi imat cemo novi uređeni niz (output) i s obzirom da je on
        u funkciji void definisan kao pokazivac taj output niz ce biti vidljiv u citavom programu.
    */
}

/*
    Funkcija koja provjerava da li je uneseni redni broj rijeci koju zelimo
    veci od broja rijeci u recenici, ako jeste vratiti ce 1, ako ne vratit ce 0
*/
bool provjera(string recenica,int num){

/*
    Brojac postavljamo na 1, jer cemo brojati spaceove
    Ako je 0 brojac ce na kraju biti za jedan manji od broja rijeci.
*/
int brojRijec=1;

//pomocni char array, duzina mu je jednaka duzini stringa + 1
char recenica_ar[recenica.size()+1];

//u novi char array kopiramo string, da bi lakse radili sa njim
strcpy(recenica_ar, recenica.c_str());

//for petlja koja ide od pocetka da kraja char arraya koji drzi nasu recenicu
for (int i = 0; i < strlen(recenica_ar); i++){
    //ako je karakter do kojeg je dosla for petlja jednak spaceu broj rijeci se povecava za 1
    if(recenica_ar[i]==' '){
        brojRijec++;
    }
}

//ako je uneseni redni broj rijeci koju zelimo veci od ukupnog broja rijeci u recenici vracamo 1
if(num>brojRijec){
    return 1;
}
//u suprotnom vracamo 0
else
return 0;
}

//funkcija za izdvajanje rijeci
string IzdvojiRijec(string recenica, int num){

/*
    Prevodim string u char array, c_str se koristi da bi u niz smjestili citav string, odnosno do NULL karaktera
    Zbog tog NULL karaktera dodajem na duzinu stringa + 1 kao duzinu novog char arraya.
*/
char recenica_ar[recenica.size() + 1];
strcpy(recenica_ar, recenica.c_str());

/*
    Deklaracija stringa rijec, koji ce biti vracen iz funkcije
    index i brojac su pomocne varijable
*/
string rijec;
int index;
int brojac=1;

//for petlja ide od pocetka do kraja char arraya
    for (int i = 0;i<strlen(recenica_ar); i++){
        //Ako je char do kojeg je dosla petlja jednak spaceu brojac se povecava za jedan
        if(recenica_ar[i]==' '){
            brojac++;
        }
        /*
        Kada brojac bude jednak rednom broju rijeci koju trazimo
        pomocna varijabla index ce uzeti i, odnosno poziciju gdje se nalazi space
        i petlja ce se zavrsiti.
        */
        if(brojac==num){
                index=i;
                break;
            }
        }

//ako korisnik zeli prvu rijec
if(num==1){
//Petlja koja ide od index pozicije koju smo zapamtili do kraja char arraya
for(int i=index;i<strlen(recenica_ar);i++){
    //string rijec uzima karaktere koji se mijenjaju kroz petlju
    rijec=rijec+recenica_ar[i];
    //kada string dođe do prvog spacea petlja se zavrsava. Prva rijec je spremljena u string varijablu rijec.
    if(isspace(recenica_ar[i])){
        break;
    }
}
}else {
/*
    Ova petlja se desava u slucaju da korisnik zeli bilo koju rijec osim prve rijeci
    Ovdje petlja ide od index+1, da bi na taj nacin preskocili space do kojeg je dosla prva petlja
    kada smo određivali poziciju indexa
*/
for(int i=index+1;i<strlen(recenica_ar);i++){
    //string rijec uzima karaktere koji se mijenjaju kroz petlju
    rijec=rijec+recenica_ar[i];

    /*
        Ako je karakter do kojeg je dosla petlja jedan kraju char arraya ili jednak spacu petlja ce se zavrsiti.
        Npr. da smo funkciji proslijedili : Napredne tehnike programiranja, 2
        Prva for petlja ide od slova N i kada i dođe do e,odnosno spacea, index uzima vrijednost i.
        Ova petlja ide od index+1 da bi se preskočio space i ide od slova t.
        String rijec uzima svaki karakter sve dok petlja ne dođe do drugog space poslije slova e.
        Kada petlja dođe do drugog space naredbom brake zaustavljam for petlju.
        Na taj način sam uzeo riječ tehnike (2. riječ) i spremio je u string varijablu rijec.
    */

    /*
        Uslov za prekidanje for petlje je kada dođe do spacea(ako se rijec koju zelimo ispisati nalazi na početku
        ili u sredini recenice) ili ako for petlja dođe do kraja recenice (NULL karakter),
        u slucaju da zelimo zadnju rijec u recenici.
    */
    if(isspace(recenica_ar[i]) || recenica_ar[i]=='\0'){
        break;
    }
}
}
//naredba koja vraca string rijec iz funkcije
return rijec;
}

int main()
{
//deklaracija stringa kojeg unosimo
string recenica;

//deklaracija rednog broja rijeci koju zelimo ispisati
int n;

//unos recenice
cout<<"Unesite recenicu: ";
//uz pomoc ove komande cemo uzeti citavu recenicu kao string, a ne samo prvu rijec
getline(cin,recenica);

//unos rijeci koju zelimo ispisati
cout<<"Unesite koju rijec zelite: ";
cin>>n;

//pravim char array pomocni koji ce biti duzine stringa+1
char pomocni[recenica.size()+1];

//u njega smjestam string
strcpy(pomocni,recenica.c_str());

/*
    Pravim novi char array recenicaBezSpace koji ce biti prazan i u koji cu smjestit
    novi uređeni niz (Output iz funkcije)
*/
char recenicaBezSpace[recenica.size()+1];

//funkciji se prosljeđuje char array pomocni koji je neuređen string i jedan prazan char array
remove_extra_spaces(pomocni,recenicaBezSpace);

/*
    Pravim novi string korisnaRecenica jer funkcija IzdvojiRijec prima string
    i moram uređeni char array, recenicaBezSpace, pretvoriti u string
*/
string korisnaRecenica;

//pretvaranje char arraya u string, string korisnaRecenica prima svaki karakter char arraya
for(int i=0;i<strlen(recenicaBezSpace);i++){
    korisnaRecenica=korisnaRecenica+recenicaBezSpace[i];
}

/*
    Bool funkcija provjera koja vraca 1 ukoliko je redni broj rijeci koju zelimo
    veci od broja rijeci u recenici. U tom slucaju se ispisuje odgovarajuca poruka.

    AKo funkcija vratila 0, to znaci da je redni broj rijeci koju zelimo manji od ukupnog
    broja rijeci u recenici i program se moze nastaviti
*/
if(provjera(korisnaRecenica,n)==1){
    cout<<"\n[GRESKA] Nema toliko rijeci u recenici."<<endl;
}else{
//Ispis onoga što će vratiti funkcija IzdvojiRijec
cout<<endl<<n<<". rijec je: "<<IzdvojiRijec(korisnaRecenica,n)<<endl;
}

return 0;
}
