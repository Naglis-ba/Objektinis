#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

using namespace::std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "startas";
    std::ofstream out("vardai.txt");
    vector<int> paz;
    int egz;
    int n = 10000000;
    int paz_sk = 7;

    out << "Vardas" << "        " << "Pavarde" << "         " << "ND1"<< "    "<<"ND2"<< "    "<< "ND3"<< "    " << "ND4"<< "    "<<"ND5"<< "    "<< "ND6"<< "  "<<"ND7"<<"     "<<  "Egz"<< endl;
    for(int i=1; i<n; i++){

        for (int k = 0; k < paz_sk; k++) {
            paz.push_back(rand() % 10 + 1);
        }
        egz = rand() % 10 + 1;

        out << "Vardas" + to_string(i) << "         " << "Pavarde" + to_string(i) << "        ";
        for (int j: paz){
            out << to_string(j) << "    ";
        }
        out << egz;
        out << endl;
        paz.clear();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo generavimas uztruko: " << diff.count() << " s\n";
}