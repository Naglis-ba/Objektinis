#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>     
#include <algorithm>   
#include <sstream> 
#include <fstream>
#include "studentas.h"
#include "funkcijos.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::swap;
using std::stoi;


int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Studentas> studentai;
    studentai.reserve(100000);
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
            cout << "Failo pavadinimas: ";
            string failo_vardas;
            cin >> failo_vardas;
            nuskaitytiIsFailo(studentai, failo_vardas); 
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


        cout << "Ar įrašyti į failą?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int y;
        cin >> y;

        cout << "Ar įrašyti išskirti išlaikiusius ir neišlaikiusius?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int x;
        cin >> x;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(y == 1){
            if(x == 1){
                Outas_i_du_failus(studentai);
            }
            else Outas_i_faila(studentai);
        }

        else Outas_i_console(studentai);

   return 0;
}