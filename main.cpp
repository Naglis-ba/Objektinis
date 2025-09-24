#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>

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

void RikiuotiStudentus(vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        if (a.pavarde == b.pavarde)
            return a.vardas < b.vardas;
        return a.pavarde < b.pavarde;
    });
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

void SkaiciuotiGalutinius(Studentas& stud) {
    double vid = skaiciuotiVidurki(stud.paz);
    double med = skaiciuotiMediana(stud.paz);
    stud.galVid = 0.4 * vid + 0.6 * stud.egz;
    stud.galMed = 0.4 * med + 0.6 * stud.egz;
}

void generuotiAtsitiktinai(Studentas& stud) {
    int n;
    cout << "Kiek namu darbu pazymiu generuoti? ";
    cin >> n;
    stud.paz.clear();
    for (int i = 0; i < n; i++) {
        stud.paz.push_back(rand() % 10 + 1);
    }
    stud.egz = rand() % 10 + 1;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void IvestiPazymius(Studentas& stud){
    cout << "Iveskite namu darbu pazymius (du ENTER is eiles baigia ivedima):" << endl;
    string paz_str;
    int laik_paz;
    int tusciu_eiluciu = 0;
    stud.paz.clear();
    while (true) {
        std::getline(cin, paz_str);
        if (paz_str.empty()) {
            tusciu_eiluciu++;
            if (tusciu_eiluciu == 2) break;
            continue;
        }
        tusciu_eiluciu = 0;
        try {
            laik_paz = std::stoi(paz_str);
            stud.paz.push_back(laik_paz);
        } catch (...) {
            cout << "Iveskite skaiciu arba ENTER." << endl;
        }
    }
}


void nuskaitytiIsFailo(vector<Studentas>& studentai, const string& failoVardas) {
    std::ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }
    string eilute;
    std::getline(in, eilute); // skip header

    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        Studentas stud;
        iss >> stud.vardas >> stud.pavarde;
        int skaicius;
        vector<int> paz;
        while (iss >> skaicius) paz.push_back(skaicius);
        if (paz.empty()) continue;
        stud.egz = paz.back();
        paz.pop_back();
        stud.paz = paz;
        SkaiciuotiGalutinius(stud);
        studentai.push_back(stud);
    }
    in.close();
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Studentas> studentai;

    while (true) {
        cout << "\nPasirinkite veiksma:\n";
        cout << "1 - Ivesti studento duomenis rankiniu budu\n";
        cout << "2 - Generuoti studento duomenis atsitiktinai\n";
        cout << "3 - Nuskaityti studentus is failo\n";
        cout << "0 - Baigti/Rodyti lentelę\n";
        cout << "Jusu pasirinkimas: ";
        int pasirinkimas;
        cin >> pasirinkimas;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pasirinkimas == 0) break;

        if (pasirinkimas == 3) {
            nuskaitytiIsFailo(studentai, "studentai10000.txt");
            continue;
        }

        Studentas stud;
        cout << "Iveskite studento varda: ";
        std::getline(cin, stud.vardas);
        cout << "Iveskite studento pavarde: ";
        std::getline(cin, stud.pavarde);

        if (pasirinkimas == 1) {
            IvestiPazymius(stud);
            cout << "Koks egzamino ivertinimas? ";
            cin >> stud.egz;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (pasirinkimas == 2) {
            generuotiAtsitiktinai(stud);
            cout << "Sugeneruoti pazymiai: ";
            for (int p : stud.paz) cout << p << " ";
            cout << "\nSugeneruotas egzamino balas: " << stud.egz << endl;
        } else {
            cout << "Tokio pasirinkimo nera.\n";
            continue;
        }
        
        SkaiciuotiGalutinius(stud);
        studentai.push_back(stud);
    }
    cout << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)" << endl;
    cout << string(90, '-') << endl;

    RikiuotiStudentus(studentai);
    
    for (const auto& stud : studentai) {
        cout << setw(20) << left << stud.vardas
             << setw(20) << left << stud.pavarde
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << endl;
        cout << string(90, '-') << endl;
    }
    
}