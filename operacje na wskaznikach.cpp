#include <cstdlib>
#include <iostream>
using namespace std;
const int MAX_LEN = 128;

/*
  int str_len(char * s)

  Wlasna implementacja funkcji wyznaczajacej dlugosc
  napisu liczona w znakach

  Parametry:
    char * s -- tablica zawierajaca napis, ktorego
    dlugosc jest wyznaczana

  Rezultat:
    Dlugosc napisu liczona w znakach
*/
int str_len(char * s)
{
    int i = 0;
    while (*(s+i) != '\0'){
        i++;
    }
    return i;
}

/*
  int lwr_str_cnt(char * s)

  Wyznacza liczbe malych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba malych liter w napisie s
*/
int lwr_str_cnt(char * s)
{
    int liczba_malych_liter = 0;
    for (int i = 0; *(s+i) != '\0'; i++){
        if (islower((*(s+i))))
            liczba_malych_liter++;
    }
    return liczba_malych_liter;
}

/*
  int upr_str_cnt(char * s)

  Wyznacza liczbe duzych liter w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba duzych liter w napisie s
*/
int upr_str_cnt(char * s)
{
    int liczba_duzych_liter = 0;
    for (int i = 0; *(s+i) != '\0'; i++){
        if (isupper((*(s+i))))
            liczba_duzych_liter++;
    }
    return liczba_duzych_liter;
}

/*
  int dgt_str_cnt(char * s)

  Wyznacza liczbe cyfr w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba cyfr w napisie s
*/
int dgt_str_cnt(char * s)
{
    int liczba_cyfr = 0;
    for (int i = 0; *(s+i) != '\0'; i++){
        if (isdigit((*(s+i))))
            liczba_cyfr++;
    }
    return liczba_cyfr;
}

/*
  int nalpha_str_cnt(const char * s)

  Wyznacza liczbe liter i cyfr w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba liter i cyfr w napisie s
*/
int nalpha_str_cnt(char * s)
{
    return lwr_str_cnt(s)+ upr_str_cnt(s)+ dgt_str_cnt(s);
}

/*
  int chr_str_cnt(char c, char * s)

  Wyznacza liczbe wystapien znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba wystapien znaku c w napisie s
*/
int chr_str_cnt(char c, char * s)
{
    int liczba_wystapien_litery = 0;
    for (int i = 0; *(s+i) != '\0'; i++){
        if (*(s+i) == c)
            liczba_wystapien_litery++;
    }
    return liczba_wystapien_litery;
}

/*
  char * chr_str_pos(char c, char * s)

  Wyznacza wskazanie na pierwsze wystapienie znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na pierwsze wystapienie znaku c w s lub 0 gdy znak
    nie zostal znaleziony
*/
char * chr_str_pos(char c, char * s)
{
    for (int i = 0; *(s+i) != '\0'; i++){
        if (*(s+i) == c)
            return s+i;
    }
    return 0;
}

/*
  char * chr_str_rpos(char c, char * s)

  Wyznacza wskazanie na ostatnie wystapienie znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na ostatnie wystapienie znaku c w s lub NULL gdy znak
    nie zostal znaleziony
*/
char * chr_str_rpos(char c, char * s) {
    for (int i = 1; i <= str_len(s); i--){
        if (*(s+str_len(s)-i) == c)
            return s+str_len(s)-i+1;
    }
    return NULL;
}

/*
  char * str_rev( char * s )

  Odwraca kolejnosc znakow w tablicy s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na tablice s
*/
char * str_rev(char * s) //Nie działa
{
    int len = str_len(s);
    for (int i = 0; i < int(len / 2); i++){
        char znak;
        znak = *(s+i);
        *(s+i) = *(s+(len-i));
        *(s+(len-i)) = znak;
    }
    return s;
}

/*
  int str_word_count(char * s)

  Funkcja wyznacza liczbe slow w tablicy s. Jako slowo
  rozumiemy ciag liter cyfr i znakow podkreslenia. Slowa
  moga być rozdzielane jednym lub wieloma znakami spacji, tabulacji,
  podzialu wiersza.

  Przyklad:
  Napis: "Ala _ma_    kot_ta i    dwa psy"
  Liczba slow: 6

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba slow w napisie s
*/
int str_word_count(char * s) //Nie działa
{
    int licznik_slow = 0;
    for (int i = 1; *(s+i) != '\0'; i++){
        if (*(s) == ' ' && *(s+i) != ' ')
            licznik_slow++;
    }
    return licznik_slow;
}

int main()
{
    char line[MAX_LEN];
    char c;
    char * pos;

    cout << "\n\nWpisz linie tekstu: ";
    cin.getline(line, MAX_LEN-1);

    cout << "\nLiczba znakow         : " << str_len(line);
    cout << "\nLiczba malych liter   : " << lwr_str_cnt(line);
    cout << "\nLiczba duzych liter   : " << upr_str_cnt(line);
    cout << "\nLiczba cyfr           : " << dgt_str_cnt(line);
    cout << "\nLiczba znakw alphanum : " << nalpha_str_cnt(line);

    cout << "\n\nPodaj pojedynczy znak: ";
    cin >> c;

    cout << "\nLiczba wystapien znaku " << c << ": " << chr_str_cnt(c, line);

    if((pos = chr_str_pos(c, line)) != 0)
        cout << "\nPierwsze wystapienie znaku " << *pos << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    if((pos = chr_str_rpos(c, line)) != 0)
        cout << "\nOstatnie wystapienie znaku " << *pos  << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    cout << "\n\nNapis oryginalny : " << line;
    cout << "\nNapis odwrocony  : " << str_rev(line);
    cout << "\nLiczba slow w napisie: " << str_word_count(line);
    cin.ignore();
    cin.get();
    return EXIT_SUCCESS;
}

