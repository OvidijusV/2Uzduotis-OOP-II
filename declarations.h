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
};

void input(vector<Studentas> &studentai);
void checkInputChar(char &tn);
void readFile(vector<Studentas> &studentai);
bool palyginimas(const Studentas& pirmas, const Studentas& antras);
void output(vector<Studentas> &studentai);

#endif