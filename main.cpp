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
using std::stoi;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz;
    double galVid;
    double galMed;
};

void Sort(vector<int>& arr) {
   std::sort(arr.begin(), arr.end());
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
    cout << "Iveskite namu darbu pazymius (du ENTER is eiles baigia ivedima):\n";
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
            laik_paz = stoi(paz_str);
            stud.paz.push_back(laik_paz);
        } catch (...) {
            cout << "Iveskite skaiciu arba ENTER.\n";
        }
    }
}


void nuskaitytiIsFailo(vector<Studentas>& studentai, const string& failoVardas) {
    std::ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }
    string vardas, pavarde, eilute;
    std::getline(in, eilute);
   
    while (in >> vardas >> pavarde) {
        Studentas stud;
        stud.vardas = vardas;
        stud.pavarde = pavarde;
        vector<int> paz;
        int x;
        while (in.peek() != '\n' && in >> x) paz.push_back(x);
        if (paz.empty()) continue;
        stud.egz = paz.back();
        paz.pop_back();
        stud.paz = paz;
        SkaiciuotiGalutinius(stud);
        studentai.push_back(std::move(stud));
    }
}

void Outas_i_faila(const vector<Studentas> studentai){
    std::ofstream out("rez.txt");

    out << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)";
    out << string(90, '-') << "\n";
    for (const auto& stud : studentai) {
        out << setw(20) << left << stud.vardas
             << setw(20) << left << stud.pavarde
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << "\n";
        out << string(90, '-') << "\n";
    }



};

void Outas_i_console(const vector<Studentas> studentai){
    
    cout << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)" << "\n";
    cout << string(90, '-') << "\n";

    for (const auto& stud : studentai) {
        cout << setw(20) << left << stud.vardas
             << setw(20) << left << stud.pavarde
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
             << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << "\n";
        cout << string(90, '-') << "\n";
    }

    
};

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
            nuskaitytiIsFailo(studentai, "vardai.txt");
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
            cout << "\nSugeneruotas egzamino balas: " << stud.egz << "\n";
        } else {
            cout << "Tokio pasirinkimo nera.\n";
            continue;
        }
        
        SkaiciuotiGalutinius(stud);
        studentai.push_back(stud);
    }


    RikiuotiStudentus(studentai);


        cout << "Ar įrašyti į failą?" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int y;
        cin >> y;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(y == 1){
            Outas_i_faila(studentai);
        }

        else Outas_i_console(studentai);

   
}