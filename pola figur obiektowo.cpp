#include <iostream>
#include <math.h>
using namespace std;
class Kwadrat{
private:
    float bok;
public:
    Kwadrat(float bok){
        this->bok = bok;
    }
    float pole(){
        return round(bok*bok*100)/100;
    }
};
class Prostokat{
private:
    float bok_1, bok_2;
public:
    Prostokat(float bok_1, float bok_2){
        this->bok_1 = bok_1;
        this->bok_2 = bok_2;
    }
    float pole(){
        return round(bok_1*bok_2*100)/100;
    }
};
class Trojkat{
private:
    float wysokosc, podstawa;
public:
    Trojkat(float wysokosc, float podstawa){
        this->wysokosc = wysokosc;
        this->podstawa = podstawa;
    }
    float pole(){
        return round(0.5*podstawa*wysokosc*100)/100;
    }
};
class Kolo{
private:
    float promien;
public:
    Kolo(float promien){
        this->promien = promien;
    }
    float pole(){
        return round(3.14*(promien*promien)*100)/100;
    }
};
class Trapez{
private:
    float podstawa_1, podstawa_2, wysokosc;
public:
    Trapez(float podstawa_1, float podstawa_2, float wysokosc){
        this->podstawa_1 = podstawa_1;
        this->podstawa_2 = podstawa_2;
        this->wysokosc = wysokosc;
    }
    float pole(){
        return round(0.5*(podstawa_1+podstawa_2)*wysokosc);
    }
};
void menu(){
    cout << "1.Kwadrat" << endl;
    cout << "2.Prostokat" << endl;
    cout << "3.Trojkat" << endl;
    cout << "4.Kolo" << endl;
    cout << "5.Trapez" << endl;
    cout << "6.Koniec" << endl;
    cout << "Wybor: ";
}
int nr_opcji(){
    int opcja;
    cin >> opcja;
    return opcja;
}
float pobieranie_liczby(){
    float liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    if (liczba >= 0)
        return liczba;
    else if (liczba < 0)
        return abs(liczba);
    else
        return 0;
}
void program(){
    int opcja;
    do{
        opcja = nr_opcji();
        Kwadrat *kwadrat;
        Prostokat *prostokat;
        Trojkat *trojkat;
        Kolo *kolo;
        Trapez *trapez;
        switch (opcja) {
            case 1:
                kwadrat = new Kwadrat(pobieranie_liczby());
                cout << kwadrat->pole() << endl;
                break;
            case 2:
                prostokat = new Prostokat(pobieranie_liczby(), pobieranie_liczby());
                cout << prostokat->pole() << endl;
                break;
            case 3:
                trojkat = new Trojkat(pobieranie_liczby(), pobieranie_liczby());
                cout << trojkat->pole() << endl;
                break;
            case 4:
                kolo = new Kolo(pobieranie_liczby());
                cout << kolo->pole() << endl;
                break;
            case 5:
                trapez = new Trapez(pobieranie_liczby(), pobieranie_liczby(), pobieranie_liczby());
                cout << trapez->pole() << endl;
                break;
            case 6:
                break;
            default:
                cout << "BLAD" << endl;
                break;
        }
    } while (opcja != 6);
}
int main() {
    return 0;
}
