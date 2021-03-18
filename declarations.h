#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double vidurkis = 0;
};

void input(vector<Studentas> &studentai);
void checkInputChar(char &tn);
void readFile(vector<Studentas> &studentai);
bool palyginimas(const Studentas& pirmas, const Studentas& antras);
void output(vector<Studentas> &studentai);
void generationNumber();
void generateFile(int numberStudents);
void generatedFileRead(vector<Studentas> &studentai, int studsNumber);
void countAvg(vector<Studentas> &studentai);
void sortStudents(vector<Studentas> &studentai);

#endif