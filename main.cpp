#include "declarations.h"
int main(){

    srand(time(NULL));

    vector<Studentas> studentai;

    char tn;
    cout << "Ar norite, jog duomenis butu sugeneruoti automatiskai ir iskarto nuskaityti?(t/n): ";
    cin >> tn;
    cin.ignore();
    checkInputChar(tn);
    int skai = generationNumber();
    if(tn == 't'){
        cout << "Pasirinkite ar failus nuskaityti i vector, list ar deque konteinerius(v, l, d): ";
        cin >> tn;
        if(tn == 'v'){
            vector<Studentas> studentai;
            generateFile(skai);
            generatedFileRead(studentai, skai);
            sortStudentsVector(studentai);
        } else if (tn == 'l'){
            list<Studentas> studentai;
            generateFile(skai);
            generatedFileRead(studentai, skai);
            sortStudentsList(studentai);
        } else {
            deque<Studentas> studentai;
            generateFile(skai);
            generatedFileRead(studentai, skai);
            sortStudentsDeque(studentai);
        }
    }
    else if (tn == 'n'){
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
}