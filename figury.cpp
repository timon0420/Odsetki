#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;
//menu wyswietlające możliwosci wyboru
void menu(){
    cout << "1.Kwadrat" << endl;
    cout << "2.Prostokat" << endl;
    cout << "3.Kolo" << endl;
    cout << "4.Trojkat" << endl;
    cout << "5.Trapez" << endl;
    cout << "6.Koniec" << endl;
    cout << "Wybor: ";
}
//pobieranie numeru opcji
int nr_opcji(){
    int opcja;
    cin >> opcja;
    if (opcja >= 1 && opcja <= 6 && (int)opcja-opcja == 0){
        return opcja;
    }
}
//pobieranie danych liczbowych
float pobieranie_danych(){
    float dana;
    while (true) {
        cin >> dana;
        if (dana >= 0) {
            return dana;
        }
        else {
            cout << "Podana wartosc jest nieprawidlowa\nPoprawna wartosc: ";
        }
    }
}
float kwadrat(){
    float a;
    cout << "Bok: ";
    a = pobieranie_danych();
    return round((a*a)*100)/100;
}
float prostokat(){
    float a, b;
    cout << "Bok: ";
    a = pobieranie_danych();
    cout << "Bok: ";
    b = pobieranie_danych();
    return round((a*b)*100)/100;
}
float kolo(){
    float r;
    cout << "Promien: ";
    r = pobieranie_danych();
    return round((r*r*3.14)*100)/100;
}
float trojkat(){
    float a, h;
    cout << "Podstawa: ";
    a = pobieranie_danych();
    cout << "Wysokosc: ";
    h = pobieranie_danych();
    return round((0.5*a*h)*100)/100;
}
float trapez(){
    float a, b, h;
    cout << "Podstawa: ";
    a = pobieranie_danych();
    cout << "Podstawa: ";
    b = pobieranie_danych();
    cout << "Wysokosc: ";
    h = pobieranie_danych();
    return round((0.5*(a+b)*h)*100)/100;
}
void wypisywanie_wynikow(float wynik){
    cout << "Wynik: " << wynik << endl;
    sleep(1);
}
void program(){
    int opcja;
    do{
        menu();
        try {
            opcja = nr_opcji();
            switch (opcja) {
                case 1:
                    wypisywanie_wynikow(kwadrat());
                    break;
                case 2:
                    wypisywanie_wynikow(prostokat());
                    break;
                case 3:
                    wypisywanie_wynikow(kolo());
                    break;
                case 4:
                    wypisywanie_wynikow(trojkat());
                    break;
                case 5:
                    wypisywanie_wynikow(trapez());
                    break;
                case 6:
                    break;
                default:
                    cout << "BLAD" << endl;
                    break;
            }
        } catch (int e) {
            cout << "BLAD" << endl;
            opcja = 6;
        }
    } while (opcja != 6);
}
int main() {
    program();
    return 0;
}
