// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::swap;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double galVid;
    double galMed;
};
void Sort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}
double skaiciuotiVidurki(const vector<int>& paz) {
    if (paz.empty()) return 0.0;
    int suma = 0;
    for (int x : paz) suma += x;
    double avg = suma / paz.size();
    return avg;
}

double skaiciuotiMediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    Sort(paz);
    size_t n = paz.size();
    if (n % 2 == 0)
        return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    else
        return paz[n/2];
}


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
    double vid = skaiciuotiVidurki(stud.paz);
    double med = skaiciuotiMediana(stud.paz);
    stud.galVid = 0.4 * vid + 0.6 * stud.egz;
    stud.galMed = 0.4 * med + 0.6 * stud.egz;
    cout << setw(10) << left << stud.vardas
         << setw(15) << left << stud.pavarde
         << "Galutinis (Vid.): " << stud.galVid
         << " | Galutinis (Med.): " << stud.galMed << endl;
}