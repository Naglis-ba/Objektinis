#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <chrono>

using namespace std;



void Sort(vector<int>& arr) {
   std::sort(arr.begin(), arr.end());
}

void RikiuotiStudentus(vector<Studentas>& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.galVid > b.galVid;
    });
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Rikiavimas uztruko: " << diff.count() << " s\n";
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
//g

void nuskaitytiIsFailo(vector<Studentas>& studentai, const string& failoVardas) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }
    string eilute;
    std::getline(in, eilute);
   
    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        Studentas stud;
        iss >> stud.vardas >> stud.pavarde;
        vector<int> paz;
        int x;
        while (iss >> x) paz.push_back(x);
        if (paz.empty()) continue;
        stud.egz = paz.back();
        paz.pop_back();
        stud.paz = move(paz);
        
        SkaiciuotiGalutinius(stud);
        studentai.push_back(std::move(stud));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Nuskaitymas uztruko: " << diff.count() << " s\n";
};

void Outas_i_faila(const std::vector<Studentas> studentai){
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
};

void Outas_i_console(const vector<Studentas> studentai){
    auto start = std::chrono::high_resolution_clock::now();
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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
};

void Outas_i_du_failus(const vector<Studentas> studentai){
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out1("kietiakai.txt");
    std::ofstream out2("vargsiukai.txt");

    out1 << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(25) << left << "Galutinis (Vid.)"
        << setw(25) << left << "Galutinis (Med.)" << "\n";
    out1 << string(90, '-') << "\n";

    out2 << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(25) << left << "Galutinis (Vid.)"
        << setw(25) << left << "Galutinis (Med.)" << "\n";
    out2 << string(90, '-') << "\n";


    for (const auto& stud : studentai) {
        if (stud.galVid >= 5.0) {
            out1 << setw(20) << left << stud.vardas
                 << setw(20) << left << stud.pavarde
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << "\n";
            out1 << string(90, '-') << "\n";
    }
         else {
            out2 << setw(20) << left << stud.vardas
                 << setw(20) << left << stud.pavarde
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.galVid
                 << setw(25) << left << std::fixed << std::setprecision(2) << stud.galMed << "\n";
            out2 << string(90, '-') << "\n";
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Isvedimas uztruko: " << diff.count() << " s\n";
}