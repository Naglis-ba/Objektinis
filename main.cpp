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
    vector<int> paz;
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
      
        if (!swapped)
            break;
    }
}

double skaiciuotiVidurki(const vector<int>& paz) {
    if (paz.empty()) return 0.0;
    int suma = 0;
    for (int x : paz) suma += x;
    double avg = static_cast<double>(suma) / paz.size();
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
    vector<Studentas> studentai;
    string ivedimas;
    while (true) {
        Studentas stud;
        cout << "Iveskite studento varda (arba 'baigti', kad baigtumete ivedima): ";
        cin >> ivedimas;
        if (ivedimas == "baigti") {
            break;
        }
        stud.vardas = ivedimas;
        cout << "Iveskite studento pavarde: ";
        cin >> stud.pavarde;
        
        cout << "Iveskite namu darbu pazymius (spauskite ENTER po kiekvieno pazymio. Ivedus visus pazymius, spauskite '0' ir ENTER arba bet kokia raide ir ENTER):" << endl;
        int laik_paz;
        while (cin >> laik_paz && laik_paz != 0) {
            stud.paz.push_back(laik_paz);
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        cout << "Koks egzamino ivertinimas? ";
        cin >> stud.egz;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        
        double vid = skaiciuotiVidurki(stud.paz);
        double med = skaiciuotiMediana(stud.paz);
        stud.galVid = 0.4 * vid + 0.6 * stud.egz;
        stud.galMed = 0.4 * med + 0.6 * stud.egz;
        
        studentai.push_back(stud);
        
        cout << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)" << endl;
    cout << string(90, '-') << endl;
    
    for (const auto& stud : studentai) {
        cout << setw(20) << left << stud.vardas
             << setw(20) << left << stud.pavarde
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << endl;
    }
    }
    
}