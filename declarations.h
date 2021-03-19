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
#include <chrono>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double vidurkis = 0;
};

class Timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        Timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
        start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
        return std::chrono::duration<double>
        (std::chrono::high_resolution_clock::now() - start).count();
        }
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