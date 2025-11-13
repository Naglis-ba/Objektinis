#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;


double skaiciuotiVidurki(const vector<int>& paz) {
    if (paz.empty()) return 0.0;
    int suma = 0;
    for (int x : paz) suma += x;
    double avg = static_cast<double>(suma) / paz.size();
    return avg;
}

double skaiciuotiMediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    stable_sort(paz.begin(), paz.end());
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