#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    int n;
    vector<int> pazymiai;
    int egzaminas;
};

void input(Studentas &studentai);


int main(){

    srand(time(NULL));

    int kiekstud = 0;
    vector<Studentas> studentai;

    char tn;
    while (true){
        studentai.resize(kiekstud + 1);
        input(studentai[kiekstud]);
        kiekstud++;

        cout << "Ar norite prideti dar viena studenta?(t/n): ";
        cin >> tn;
        cin.ignore();
        while(tn != 't' && tn != 'n'){
            cout << "Galimas pasirinktimas tik taip(t) arba ne(n)!" << endl;
            cin >> tn;
            cin.ignore();
        }
        if(tn == 'n') {
            break;
        }
        
    }

    cout << "Pradedami isvesti duomenys..." << endl;
    cout << "Ar norite, jog jusu galutinis rezultatas butu pazymiu mediana?(t/n): ";
    cin >> tn;
    while(tn != 't' && tn != 'n'){
        cout << "Galimas pasirinktimas tik taip(t) arba ne(n)!" << endl;
        cin >> tn;
    }
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
            << setw(10) << "Galutinis (Vid.)" << endl;
        cout << string(65, '-') << endl;

        for(int i = 0; i < kiekstud; i++){
            sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end());

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
}

void input(Studentas &studentai){
    string vardas, pavarde;
    int n = 0;
    int egzaminas;
    char tn;
    vector<int>nd;

    cout << "Iveskite studento varda: ";
    getline(cin, vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, pavarde);

    cout << "Toliau iveskite studento " << vardas << " " << pavarde << " prasomus duomenis" << endl;
    cout << "Ar yra zinomas tikslus namu darbu skaicius?(t/n): ";
    cin >> tn;
    while(tn != 't' && tn != 'n'){
        cout << "Galimas pasirinkimas tik taip(t) arba ne(n)!" << endl;
        cin >> tn;
    }

    if(tn == 't'){
        cout << "Iveskite tikslu namu darbu skaiciu: ";
        cin >> n;
        while(cin.fail()){
            cout << "Turite ivesti skaiciu: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }
        cout << "Ar norite, jog studento rezultatai butu sugeneruoti atsitiktinai?(t/n): ";
        cin >> tn;
        while(tn != 't' && tn != 'n'){
            cout << "Galimas pasirinkimas tik taip(t) arba ne(n)!" << endl;
            cin.clear();
            cin >> tn;
        }
        if(tn == 't'){
            for(int i = 0; i < n; i++){
                nd.push_back(rand() % 10 + 1);
                cout << i+1 << "-ojo namu darbo rezultatas: " << nd[i] << endl;
            }
            egzaminas = rand() % 10 + 1;
            cout << "Egzamino rezultatas: " << egzaminas << endl;
        } else {
            for(int i = 0; i < n; i++){
                int input;
                cout << "Iveskite " << i+1 << "-ojo namu darbo rezultata: ";
                cin >> input;
                nd.push_back(input);
                while(nd[n] < 0 || nd[n] > 10 || cin.fail()){
                    cin.clear();
                    cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (0-10): ";
                    cin >> input;
                    nd.push_back(input);
                }
            }
            cout << "Iveskite egzamino rezultata: ";
            cin >> egzaminas;
            while(egzaminas < 0 || egzaminas > 10 || cin.fail()){
                cin.clear();
                cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (0-10): ";
                cin >> egzaminas;
            }
        }
    } else {
        cout << "Noredami sustabdyti namu darbu ivedima irasykite 0" << endl;
        while(true){
            cout << "Iveskite " << n+1 << "-ojo namu darbo rezultata: ";
            int input;
            cin >> input;
            nd.push_back(input);
            while(nd[n] < 0 || nd[n] > 10 || cin.fail()){
                cin.clear();
                cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (0-10): ";
                cin >> input;
                nd.push_back(input);
            }
            if(nd[n] == 0 && n > 0){
                cout << "Iveskite egzamino rezultata: ";
                cin >> egzaminas;
                while(egzaminas < 0 || egzaminas > 10 || cin.fail()){
                    cin.clear();
                    cout << "Ivedete netinkama reiksme, iveskite rezultata is naujo (0-10): ";
                    cin >> egzaminas;
                }
                break;
            } else if(nd[n] == 0 && n ==0){
                cout << "Turi buti ivestas bent vienas namu darbo rezultatas!" << endl;
            } else n++;
        }

    }
    studentai.vardas = vardas;
    studentai.pavarde = pavarde;
    studentai.n = n;
    studentai.pazymiai = nd;
    studentai.egzaminas = egzaminas;

}