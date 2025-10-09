#pragma once
#include <vector>
#include <string>
#include "studentas.h"
#include "funkcijos.cpp"

void Sort(std::vector<int>& arr);
void RikiuotiStudentus(std::vector<Studentas>& studentai);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void SkaiciuotiGalutinius(Studentas& stud);
void generuotiAtsitiktinai(Studentas& stud);
void IvestiPazymius(Studentas& stud);
void nuskaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoVardas);
void Outas_i_faila(const std::vector<Studentas> studentai);
void Outas_i_console(const std::vector<Studentas> studentai);
void Outas_i_du_failus(const std::vector<Studentas> studentai);