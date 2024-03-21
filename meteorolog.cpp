#include <iostream>
using namespace std;
int main() {
    float temperatura_min_dodatnia = 0, temperatura_max_ujemna = 0, temperatura_min_ujemna = 0, temperatura_max_dodatnia = 0, suma_odczytow = 0;
    int liczba_odczytow_dodatnich = 0, liczba_odczytow_ujemnych = 0, liczba_odczytow_zero = 0, wybor;
    do{
        cout << "Menu: " << endl;
        cout << "1.Wczytywanie temperatury" << endl;
        cout << "2.Wyswietlanie wynikow obliczen" << endl;
        cout << "Nr opcji: ";
        cin >> wybor;
        switch (wybor){
            case 1:
                float odczyt;
                cout << "Temperatura: ";
                cin >> odczyt;
                if (odczyt == 0.0){
                    liczba_odczytow_zero++;
                }
                //zapisywanie temperatury min dodatniej dla pierwszego odczytu
                else if (liczba_odczytow_dodatnich == 0 && odczyt > 0){
                    temperatura_min_dodatnia = odczyt;
                    liczba_odczytow_dodatnich++;
                    suma_odczytow += odczyt;
                }
                //zapisywanie temperatury min i max dla pierwszego odczytu ujemnego
                else if (liczba_odczytow_ujemnych == 0 && odczyt < 0){
                    temperatura_min_ujemna = odczyt;
                    temperatura_max_ujemna = odczyt;
                    liczba_odczytow_ujemnych++;
                    suma_odczytow += odczyt;
                }
                else {
                    if (odczyt < 0) {
                        if (odczyt > temperatura_max_ujemna)
                            temperatura_max_ujemna = odczyt;
                        else if (odczyt < temperatura_min_ujemna)
                            temperatura_min_ujemna = odczyt;
                        liczba_odczytow_ujemnych++;
                        suma_odczytow += odczyt;
                    }
                    else if (odczyt > 0) {
                        if (odczyt < temperatura_min_dodatnia)
                            temperatura_min_dodatnia = odczyt;
                        else if (odczyt > temperatura_max_dodatnia)
                            temperatura_max_dodatnia = odczyt;
                        liczba_odczytow_dodatnich++;
                        suma_odczytow += odczyt;
                    }
                }
                break;
            case 2:
                //wypisywanie wyników
                cout << "Srednia temperatura = " << suma_odczytow/(liczba_odczytow_dodatnich + liczba_odczytow_ujemnych + liczba_odczytow_zero) << endl;
                cout << "Liczba odczytow rownych zero = " << liczba_odczytow_zero << endl;
                cout << "Liczba odczytow liczb dodatnich = " << liczba_odczytow_dodatnich << endl;
                cout << "Liczba odczytow liczb ujemnych = " << liczba_odczytow_ujemnych << endl;
                cout << "Temperatura najnizsza sposrod temperatur ujemnych = " << temperatura_min_ujemna << endl;
                cout << "Temperatura najwyzsza sposrod temperatur ujemnych = " << temperatura_max_ujemna << endl;
                cout << "Temperatura najnizsza sposrod temperatur dodatnich = " << temperatura_min_dodatnia << endl;
                cout << "Temperatura najwyzsza sposrod temperatur dodatnich = " << temperatura_max_dodatnia << endl;
                break;
            default:
                cout << "BLAD" << endl;
                wybor = 2;
                break;
        }
    } while(wybor != 2);
    return 0;
}
