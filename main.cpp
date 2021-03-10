#include "declarations.h"

int main(){

    srand(time(NULL));

    vector<Studentas> studentai;

    char tn;
    cout << "Ar norite, jog duomenis butu sugeneruoti automatiskai?(t/n): ";
    cin >> tn;
    cin.ignore();
    checkInputChar(tn);

    if(tn == 't'){
        generationNumber();
    }

    cout << "Ar norite, jog duomenis butu nuskaityti is failo?(t/n): ";
    cin >> tn;
    cin.ignore();
    checkInputChar(tn);

    if(tn == 't'){
        readFile(studentai);
        cout << "Failo duomenys nuskaityti" << endl;
        sort(studentai.begin(), studentai.end(), palyginimas);
        output(studentai);

    } else {
        while (true){
            input(studentai);

            cout << "Ar norite prideti dar viena studenta?(t/n): ";
            cin >> tn;
            cin.ignore();
            checkInputChar(tn);
            if(tn == 'n') {
                break;
            }   
        }
        output(studentai);
    }
}