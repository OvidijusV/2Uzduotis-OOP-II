#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    int n;
    int *pazymiai;
    int egzaminas;
};

void input(Studentas &studentai);
void checkInputChar(char &tn);

int main(){

    srand(time(NULL));

    int kiekstud = 0;
    Studentas *studentai = new Studentas[kiekstud + 1];

    char tn;
    while (true){
        input(studentai[kiekstud]);
        kiekstud++;

        cout << "Ar norite prideti dar viena studenta?(t/n): ";
        cin >> tn;
        cin.ignore();
        checkInputChar(tn);

        if(tn == 'n') {
            break;
        } else {
            
			Studentas* studentai_temp = new Studentas[kiekstud + 1];

			for (int i = 0; i < kiekstud; i++)
				studentai_temp[i] = studentai[i];

			delete[] studentai;
			studentai = studentai_temp;
        }
        
    }

    cout << "Pradedami isvesti duomenys..." << endl;
    cout << "Ar norite, jog jusu galutinis rezultatas butu pazymiu mediana?(t/n): ";
    cin >> tn;
    checkInputChar(tn);

    if(tn == 'n'){
        cout << left << setw(20) << "Pavarde"
            << setw(15) << "Vardas"
            << setw(10) << "Galutinis (Vid.)" << endl;
        cout << string(65, '-') << endl;
        
        for(int i = 0; i < kiekstud; i++){
            double galutinisvid = 0;
            for(int j = 0; j < studentai[i].n; j++)
                galutinisvid += studentai[i].pazymiai[j];
            galutinisvid = galutinisvid / studentai[i].n;
            galutinisvid = galutinisvid * 0.4 + studentai[i].egzaminas * 0.6;

            cout << left << setw(20) << studentai[i].pavarde
                << setw(15) << studentai[i].vardas
                << setw(10) << setprecision(2) << galutinisvid << endl;
        }
    } else {
        cout << left << setw(20) << "Pavarde"
            << setw(15) << "Vardas"
            << setw(10) << "Galutinis (Med.)" << endl;
        cout << string(65, '-') << endl;

        for(int i = 0; i < kiekstud; i++){
            sort(studentai[i].pazymiai, studentai[i].pazymiai + studentai[i].n);

            double mediana = 0;
            if (studentai[i].n % 2 == 1)
				mediana = studentai[i].pazymiai[studentai[i].n / 2];

            else mediana = ((double)studentai[i].pazymiai[studentai[i].n / 2] + (double)studentai[i].pazymiai[studentai[i].n / 2 - 1]) / 2;

            double galutinis = mediana * 0.4 + studentai[i].egzaminas * 0.6;

            cout << left << setw(20) << studentai[i].pavarde
                << setw(15) << studentai[i].vardas
                << setw(10) << setprecision(2) << galutinis << endl;
        }
    }
    delete [] studentai;
}

void input(Studentas &studentai){
    string vardas, pavarde;
    int n = 0;
    int egzaminas;
    char tn;
    int *nd = new int[n + 1];
    int input;

    cout << "Iveskite studento varda: ";
    getline(cin, vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, pavarde);

    cout << "Toliau iveskite studento " << vardas << " " << pavarde << " prasomus duomenis" << endl;
    cout << "Ar yra zinomas tikslus namu darbu skaicius?(t/n): ";
    cin >> tn;
    checkInputChar(tn);

    if(tn == 't'){
        cout << "Iveskite tikslu namu darbu skaiciu: ";
        cin >> n;
        while(cin.fail()){
            cout << "Turite ivesti skaiciu: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }
        delete[] nd;
        nd = new int[n];
        cout << "Ar norite, jog studento rezultatai butu sugeneruoti atsitiktinai?(t/n): ";
        cin >> tn;
        checkInputChar(tn);

        if(tn == 't'){
            for(int i = 0; i < n; i++){
                nd[i] = rand() % 10 + 1;
                cout << i+1 << "-ojo namu darbo rezultatas: " << nd[i] << endl;
            }
            egzaminas = rand() % 10 + 1;
            cout << "Egzamino rezultatas: " << egzaminas << endl;
        } else {
            for(int i = 0; i < n; i++){
                cout << "Iveskite " << i+1 << "-ojo namu darbo rezultata: ";
                cin >> input;
                while(input < 0 || input > 10 || cin.fail()){
                    cin.clear();
                    cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (1-10): ";
                    cin >> input;
                }
                nd[i] = input;
            }
            cout << "Iveskite egzamino rezultata: ";
            cin >> input;
            while(input < 0 || input > 10 || cin.fail()){
                cin.clear();
                cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (1-10): ";
                cin >> input;
            }
            egzaminas = input;
        }
    } else {
        cout << "Noredami sustabdyti namu darbu ivedima irasykite 0" << endl;
        while(true){
            cout << "Iveskite " << n+1 << "-ojo namu darbo rezultata: ";
            cin >> input;
            while(input < 0 || input > 10 || cin.fail()){
                cin.clear();
                cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (1-10): ";
                cin >> input;
            }
            nd[n] = input;
            if(input == 0 && n > 0){
                cout << "Iveskite egzamino rezultata: ";
                cin >> input;
                while(input < 0 || input > 10 || cin.fail()){
                    cin.clear();
                    cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (1-10): ";
                    cin >> input;
                }
                egzaminas = input;
                break;
            } else if(input == 0 && n ==0){
                cout << "Turi buti ivestas bent vienas namu darbo rezultatas!" << endl;
            } else{
                n++;
                int* nd_temp = new int[n + 1];

				for (int i = 0; i < n; i++)
					nd_temp[i] = nd[i];

				delete[] nd;
				nd = nd_temp;
            }
        }

    }
    studentai.vardas = vardas;
    studentai.pavarde = pavarde;
    studentai.n = n;
    studentai.pazymiai = nd;
    studentai.egzaminas = egzaminas;

};

void checkInputChar(char &tn){
    while(tn != 't' && tn != 'n'){
        cout << "Galimas pasirinkimas tik taip(t) arba ne(n)!" << endl;
        cout << "Pakartokite pasirinkima(t/n): ";
        cin >> tn;
    }
}
