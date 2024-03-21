#include <cstdlib>
#include <iostream>
using namespace std;

double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien )
{
    double odsetki_suma = 0;
    for (int i = 0; i < lbDni; i++){
        double odsetki_dzien;
        odsetki_dzien = kwota*(odsetkiZaDzien/100);
        odsetki_suma += odsetki_dzien;
        kwota += odsetki_dzien;
    }
    return double(int(odsetki_suma*100))/100;
}

int main()
{
    double odsetki;

    // Test 1
    odsetki = odsetkiProgresywne( 1000, 4, 3 );
    if(odsetki == 125.50)
        cout << "\nTest 1: OK";
    else
        cout << "\nTest 1: Blad";

    // Test 2
    odsetki = odsetkiProgresywne( 1000, 10, 3 );
    if(odsetki == 343.91)
        cout << "\nTest 2: OK";
    else
        cout << "\nTest 2: Blad";

    // Test 3
    odsetki = odsetkiProgresywne(1000, 10, 5);
    if(odsetki == 628.89)
        cout << "\nTest 3: OK";
    else
        cout << "\nTest 3: Blad";

    // Test 4
    odsetki = odsetkiProgresywne(5000, 5, 10);
    if(odsetki == 3052.55)
        cout << "\nTest 4: OK";
    else
        cout << "\nTest 4: Blad";
    return EXIT_SUCCESS;
}