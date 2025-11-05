#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>     
#include <algorithm>   
#include <sstream> 
#include <fstream>
#include <list>
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
    int data;
    cout << "Pasirinkite duomenų struktūrą: \n";
    cout << "0 - vector \n";
    cout << "1 - list \n";
    cin >> data;
        vector<Studentas> studentai_vec;
        vector<Studentas> zem_lyg_vec;
        vector<Studentas> aukst_lyg_vec;
        std::list<Studentas> studentai_list;
        std::list<Studentas> zem_lyg_list;
        std::list<Studentas> aukst_lyg_list;
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
            if (data == 1){
                nuskaitytiIsFailo(studentai_list, failo_vardas);
            } 
            else {
                nuskaitytiIsFailo(studentai_vec, failo_vardas);
            }
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
        if (data == 1){
                studentai_list.push_back(stud);
            } 
        else {
                studentai_vec.push_back(stud);
        }
       
    }
        cout << "Kaip rikiuoti sudentus?\n";
        cout << "1 - Pagal vardą \n";
        cout << "2 - Pagal pažymius \n";

        int a;
        cin >> a;
        if (a == 1){
            if (data == 1) {

                RikiuotiStudentus_vardas(studentai_list);

            }
            if (data == 0){

                RikiuotiStudentus_vardas(studentai_vec);

            }
        }
        else if(a == 2){
            if (data == 1) {

                RikiuotiStudentus_vardas(studentai_list);

            }
            if (data == 0){

                RikiuotiStudentus_vardas(studentai_vec);

            }
        }
       


        cout << "Ar įrašyti į failą?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int y;
        cin >> y;

        cout << "Ar įrašant išskirti išlaikiusius ir neišlaikiusius?\n" ;
        cout << "1 - Taip\n";
        cout << "0 - Ne\n" ;
        int x;
        cin >> x;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(y == 1){
            if(x == 0){
                if (data == 1) {

                Outas_i_faila(studentai_list);

                }
                if (data == 0){

                Outas_i_faila(studentai_vec);

                }
            }
            else if(x == 1){
                if (data == 1) {
                    Outas_i_du_failus(studentai_list);
                    skirstymas_pagal_paz(studentai_list, zem_lyg_list, aukst_lyg_list);
                }
                if (data == 0){
                    Outas_i_du_failus(studentai_vec);
                    skirstymas_pagal_paz(studentai_vec, zem_lyg_vec, aukst_lyg_vec);
                }
            } 
        }

        else if (y == 0) {
            if(x == 0){
                if (data == 1) {

                Outas_i_console(studentai_list);

                }
                if (data == 0){

                Outas_i_console(studentai_vec);

                }

            } 
            else if (x == 1) {
                if (data == 1) {

                Outas_i_console(zem_lyg_list);
                Outas_i_console(aukst_lyg_list);

                }
                if (data == 0){

                Outas_i_console(zem_lyg_vec);
                Outas_i_console(aukst_lyg_vec);

                }

            }

        } 

   return 0;
}