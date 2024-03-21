#include <iostream>
#include <cmath>
using namespace std;
string funkcjaKwadratowa( double a, double b, double c ){
    return (pow(b, 2)-(4*a*c)) < 0 ? "Brak miejsc zerowych" : (pow(b, 2)-(4*a*c)) > 0 ? "Dwa miejsca zerowe x1 = " + to_string((-1*b-sqrt((pow(b, 2)-(4*a*c))))/(2*a)) + ", x2 = " + to_string((-1*b+sqrt((pow(b, 2)-(4*a*c))))/(2*a)) : "Jedno miejsce zerowe x0 = " + to_string(((-1*b)/(2*a)));
}
int main() {
    cout << funkcjaKwadratowa(2, -4, 6) << endl;
    cout << funkcjaKwadratowa(6, -1, 2) << endl;
    cout << funkcjaKwadratowa(-2, 4, 2) << endl;
    cout << funkcjaKwadratowa(1, 2, 1) << endl;
    return 0;
}
