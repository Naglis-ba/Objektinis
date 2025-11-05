#pragma once
#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <type_traits>
#include <list>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <chrono>


using namespace std;

void Sort(std::vector<int>& arr);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void SkaiciuotiGalutinius(Studentas& stud);
void generuotiAtsitiktinai(Studentas& stud);
void IvestiPazymius(Studentas& stud);


template <typename Container>
void RikiuotiStudentus_paz(Container& studentai) {
    auto start = std::chrono::high_resolution_clock::now();
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.galVid > b.galVid;
        });
    } else {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.galVid > b.galVid;
        });
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Rikiavimas uztruko: " << diff.count() << " s\n";
}
template <typename Container>
void RikiuotiStudentus_vardas(Container& studentai) {
    auto comparator = [](const Studentas& a, const Studentas& b) {
        // Primary Key: Sort by Length (Ascending)
        size_t len_a = a.vardas.length();
        size_t len_b = b.vardas.length();

        if (len_a != len_b) {
            return len_a < len_b;
        }

        return a.vardas < b.vardas;
    };

    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentai.sort(comparator);
    } else {
        std::sort(studentai.begin(), studentai.end(), comparator);
    }
}
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const string& failoVardas) {
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
template <typename Container>
void Outas_i_faila(const Container studentai){
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out("rez.txt");

    out << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(25) << left << "Galutinis (Vid.)"
         << setw(25) << left << "Galutinis (Med.)";
    out << "\n";
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
template <typename Container>
void Outas_i_console(const Container studentai){
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

template <typename Container>
void Outas_i_du_failus(const Container studentai){
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
template <typename Container>
void skirstymas_pagal_paz(const Container studentai, Container &zem_lyg, Container &aukst_lyg){

    for (const auto& stud : studentai) {
        if (stud.galVid >= 5.0) {
           aukst_lyg.push_back(std::move(stud));
    }
         else {
           zem_lyg.push_back(std::move(stud));
        }
    }

}

