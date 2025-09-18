#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double gal;
};

int main() {
    int n, laik_paz, suma =0;
    Studentas stud;
    cout << "Kuo vardu studentas(-e)? "; cin >> stud.vardas;
    cout << "Kokia jo (jos) pavarde? "; cin >> stud.pavarde;
    cout << "Kiek pazymiu ivesite? "; cin >> n;
    for (auto i = 0; i<n; i++) {
        cout << i+1 << "-asis pazymys: "; cin >> laik_paz;
        stud.paz.push_back(laik_paz);
        suma+=laik_paz;
    }
    cout << "Koks egzamino ivertinimas? "; cin >> stud.egz;
    stud.gal = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    cout << setw(10) << left << stud.vardas << setw(15) << left << stud.pavarde << stud.gal << endl;
}