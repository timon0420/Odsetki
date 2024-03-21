#include <iostream>
#include <cmath>
#include <algorithm>
#include <unistd.h>
using namespace std;
//sprawdzanie czy dana wprowadzona przez urzytkownika jest poprawna
double sprawdzanie_poprawnosci_danych(string dana){
    for (int i = 0; i < dana.length(); i++){
        if (!isdigit(dana[i]) && dana[i] != '.')
            throw 0;
    }
    return stod(dana);
}
//wczytywanie danych do tablicy
void wczytywanie_danych(double tab[], int l){
    for (int i = 0; i < l; i++){
        try {
            string dana;
            cout << "Kwota: ";
            cin >> dana;
            double sprawdzona_dana = sprawdzanie_poprawnosci_danych(dana);
            tab[i] = sprawdzona_dana;
        } catch (int e) {
            cout << "BLAD" << endl;
            i++;
        }
    }
}
void menu(){
    cout << "1.Wczytywanie przychodow\n";
    cout << "2.Wczytywanie kosztow\n";
    cout << "3.Wyswietlanie danych sumarycznych\n";
    cout << "4.Wyswietlanie minimalnych, maksymalnych i sredniej\n";
    cout << "5.Bilans\n";
    cout << "6.Koniec\n";
    cout << "Wybor: ";
}
void podmenu(){
    cout << "1.Przychody\n";
    cout << "2.Koszty\n";
    cout << "3.dochody\n";
    cout << "4.Powrot do gownego menu\n";
    cout << "Wybor: ";
}
//sprawdzanie ktora opcja została wybrana
int nr_opcji(){
    int opcja;
    cin >> opcja;
    while (true){
        if ((int)opcja - opcja == 0){
            return opcja;
        }
        else {
            cout << "BLAD prosze wprowadzic poprawna wartosc: ";
        }
    }
}
//obliczanie dochodow
void dochody_obliczanie(double przychody[], double koszty[], double dochody[], int l){
    for (int i = 0; i < l; i++){
        dochody[i] = round((przychody[i] - koszty[i])*100)/100;
    }
}
//sumowanie danych z tablicy
double sumaryczne(double tab[], int l){
    double wynik = 0;
    for (int i = 0; i < l; i++){
        wynik += tab[i];
    }
    return round(wynik*100)/100;
}
//funckcja zwraca min, max oraz miesiac dla min i max
string min_max(double tab[], int l){
    double kopia_tab[l];
    for (int i = 0; i < l; i++){
        kopia_tab[i] = tab[i];
    }
    sort(kopia_tab, kopia_tab+l);
    int pozycja_max, pozycja_min;
    for (int i = 0; i < l; i++){
        if (tab[i] == kopia_tab[0]){
            pozycja_min = i+1;
        }
        else if (tab[i] == kopia_tab[l-1]){
            pozycja_max = i+1;
        }
    }
    return "Max = " + to_string(round(kopia_tab[l-1]*100)/100) + " dla " + to_string(pozycja_max) + " miesiaca, Min = " + to_string(round(kopia_tab[0]*100)/100) + " dla " +
           to_string(pozycja_min) + " miesiaca";
}
//funckcja oblicza srednia
double srednia(double tab[], int l){
    return round((sumaryczne(tab, l)/12)*100)/100;
}
//funkcja oblicza bilans
void bilans(double przychody[], double koszty[], double dochody[], int l){
    cout << "Przychody\t | Koszty\t | Dochody\t | Komentarz" << endl;
    for (int i = 0; i < l; i++){
        string komentarz;
        if (dochody[i] == 0)
            komentarz = "zero";
        else if (dochody[i] > 0)
            komentarz = "zysk";
        else if (dochody[i] < 0)
            komentarz = "strata";
        cout << przychody[i] << "\t |  " << koszty [i] << "\t |  " << dochody[i] << "\t |  " << komentarz << endl;
    }
}
//funkcja zapelnia tablice zerami
void zerowanie_tablic(double tab[], int l){
    for (int i = 0; i < l; i++){
        tab[i] = 0;
    }
}
void program(){
    int l = 12;
    int czas_uspienia = 2;
    int opcja;
    double przychody[l], koszty[l], dochody[l];
    zerowanie_tablic(przychody, l);
    zerowanie_tablic(koszty, l);
    zerowanie_tablic(dochody, l);
    do {
        menu();
        opcja = nr_opcji();
        switch (opcja) {
            case 1: //wczytywanie przychodow
                wczytywanie_danych(przychody, l);
                break;
            case 2: //wczytywanie kosztow
                wczytywanie_danych(koszty, l);
                break;
            case 3: //wyswietlanie danych sumarycznych
                podmenu(); //wyswietlanie podmenu
                switch (nr_opcji()) {
                    case 1: //obliczanie sumarycznych przychodow
                        cout << "Suma przychodow = " << sumaryczne(przychody, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 2: //obliczanie sumarycznych kosztow
                        cout << "Suma kosztow = " << sumaryczne(koszty, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 3: //obliczanie sumarycznych dochodow
                        dochody_obliczanie(przychody, koszty, dochody, l); //obliczanie dochodow
                        cout << "Suma dochodow = " << sumaryczne(dochody, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 4: //opuszczenie podmenu
                        break;
                    default:
                        cout << "BLAD" << endl;
                        break;
                }
                break;
            case 4: //wyswietlanie max, min, sredniej
                podmenu(); //wyswietlanie podmenu
                switch (nr_opcji()){
                    case 1: //obliczanie min, max, srednia dla przychodow
                        cout << min_max(przychody, l) << endl;
                        cout << "Srednia = " << srednia(przychody, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 2: //obliczanie min, max, srednia dla kosztow
                        cout << min_max(koszty, l) << endl;
                        cout << "Srednia = " << srednia(koszty, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 3: //obliczanie min, max, srednia dla dochodow
                        dochody_obliczanie(przychody, koszty, dochody, l); //obliczanie dochodow
                        cout << min_max(dochody, l) << endl;
                        cout << "Srednia = " << srednia(dochody, l) << endl;
                        sleep(czas_uspienia);
                        break;
                    case 4: //opuszczanie podmenu
                        break;
                    default:
                        cout << "BLAD" << endl;
                        break;
                }
                break;
            case 5: //obliczanie bilansu
                dochody_obliczanie(przychody, koszty, dochody, l);
                bilans(przychody, koszty, dochody, l);
                sleep(czas_uspienia*2);
                break;
            case 6: //zakonczenie programu
                break;
            default:
                cout << "BLAD" << endl;
        }
    } while (opcja != 6);
}
int main() {
    cout << "Program wczytuje od urzytkownika przychody oraz koszty z calego roku a nastepnie dokonuje obliczeni na podanych danych.\n"
            "Program wyswietla proste menu umozliwiajace urzytkownikowi wybranie co program powinien wykonac.\n"<< endl;
    program();
    return 0;
}
