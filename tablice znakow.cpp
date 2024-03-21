#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_LEN 128

/*----------------------------------------------------------------------------
  int str_len( char s[] )

  Funkcja:
  Wlasna implementacja funkcji wyznaczajacej dlugosc napisu liczona w znakach

  Parametry:
    char s[] -- tablica zawierajaca napis ktorego dlugosc jest wyznaczana

  Rezultat:
    dlugosc napisu liczona w znakach
----------------------------------------------------------------------------*/
int str_len( char s[] ) {
    int i = 0;
    while (true) {
        if (s[i] != '\0')
            i++;
        else
            return i;
    }
}
/*----------------------------------------------------------------------------
  int lwr_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe malych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba malych liter w napisie s
----------------------------------------------------------------------------*/
int lwr_str_cnt( char s[] )
{
    int liczba_malych_liter = 0;
    for (int i = 0; i < str_len(s); i++){
        if (int(s[i]) >= 97 && int(s[i]) <= 122){
            liczba_malych_liter += 1;
        }
    }
    return liczba_malych_liter;
}

/*----------------------------------------------------------------------------
  int upr_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe duzych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba duzych liter w napisie s
----------------------------------------------------------------------------*/
int upr_str_cnt( char s[] )
{
    int liczba_duzych_liter = 0;
    for (int i = 0; i < str_len(s); i++){
        if (int(s[i]) >= 65 && int(s[i]) <= 90){
            liczba_duzych_liter += 1;
        }
    }
    return liczba_duzych_liter;
}


/*----------------------------------------------------------------------------
  int dgt_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe cyfr w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba cyfr w napisie s
----------------------------------------------------------------------------*/
int dgt_str_cnt( char s[] )
{
    int liczba_cyfr = 0;
    for (int i = 0; i < str_len(s); i++){
        if (isdigit(s[i]))
            liczba_cyfr += 1;
    }
    return liczba_cyfr;
}

/*----------------------------------------------------------------------------
  int nalpha_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe liter i cyfr w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba liter i cyfr w napisie s
----------------------------------------------------------------------------*/
int nalpha_str_cnt( char s[] )
{
    return lwr_str_cnt(s) + upr_str_cnt(s) + dgt_str_cnt(s);
}

/*----------------------------------------------------------------------------
  int chr_str_cnt( char c, char s[] )

  Funkcja:
    Wyznacza liczbe wystapien znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Liczba wystapien znaku c w napisie s
----------------------------------------------------------------------------*/
int chr_str_cnt( char c, char s[] )
{
    int liczba_wystapien = 0;
    for (int i = 0; i < str_len(s); i++){
        if (s[i] == c){
            liczba_wystapien += 1;
        }
    }
    return liczba_wystapien;
}

/*----------------------------------------------------------------------------
int chr_str_pos( char c, char s[] )

  Funkcja:
    Wyznacza indeks (pozycje w napisie) pierwszego wystapienia znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Pozycja znaku w tablicy liczona od 0 lub -1 gdy znak nie znaleziony
----------------------------------------------------------------------------*/
int chr_str_pos( char c, char s[] )
{
    for (int i = 0; i < str_len(s); i++){
        if (s[i] == c){
            return i;
        }
    }
    return -1;
}

/*----------------------------------------------------------------------------
int chr_str_rpos( char c, char s[] )

  Funkcja:
    Wyznacza indeks (pozycje w napisie) ostatniego wystapienia znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Pozycja znaku w tablicy liczona od 0 lub -1 gdy znak nie znaleziony
----------------------------------------------------------------------------*/
int chr_str_rpos( char c, char s[] )
{
    for (int i = str_len(s)-1; i >= 0; i--){
        if (s[i] == c){
            return i;
        }
    }
    return -1;
}

/*----------------------------------------------------------------------------
  void str_rev( char s[] )

  Funkcja:
    Odwraca kolejnosc znakow w tablicy s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Brak
----------------------------------------------------------------------------*/
void str_rev( char s[] )
{
    int l = str_len(s);
    for (int i = 0; i < int(l/2); i++){
        char znak = s[l-i-1];
        s[l-i-1] = s[i];
        s[i] = znak;
    }
}

// Ten main bedzie dzialal po prawidlowym zaimplementowaniu powyzszych funkcji
int main()
{
    char line[ MAX_LEN ];
    char c;
    int pos;

    cout << "\n\nWpisz linie tekstu: ";
    cin.getline( line, MAX_LEN );

    cout << "\nLiczba znakow           : " << str_len( line );
    cout << "\nLiczba malych liter     : " << lwr_str_cnt( line );
    cout << "\nLiczba duzych liter     : " << upr_str_cnt( line );
    cout << "\nLiczba cyfr             : " << dgt_str_cnt( line );
    cout << "\nLiczba alfanumerycznych : " << nalpha_str_cnt( line );

    cout << "\n\nPodaj pojedynczy znak: ";
    cin.get( c );

    cout << "\nLiczba wystapien znaku  " << c << " : " << chr_str_cnt( c, line );

    if( ( pos = chr_str_pos( c, line ) ) != -1 )
        cout << "\nPierwsze wystapienie znaku " << c << " od poczatku : " << pos + 1;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    if( ( pos = chr_str_rpos( c, line ) ) != -1 )
        cout << "\nPierwsze wystapienie znaku " << c << " od konca : " << pos + 1;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    cout << "\n\nNapis oryginalny : " << line;
    str_rev( line );
    cout << "\nNapis odwrocony  : " << line;

    cin.ignore();
    cin.get();
    return EXIT_SUCCESS;
}