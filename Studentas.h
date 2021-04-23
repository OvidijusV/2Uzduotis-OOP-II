#ifndef STUDENTASH
#define STUDENTASH

#include <string>
#include <vector>
using namespace std;

class Studentas {
    private:
        string vardas;
        string pavarde;
        vector<int> pazymiai;
        int egzaminas;
        double vidurkis;
    public:
        Studentas() : vidurkis(0) { }
        Studentas(string vardas, string pavarde, int egzaminas, vector<int> pazymiai);
        //get
        inline string getVardas() const {return vardas; }
        inline string getPavarde() const {return pavarde; }
        inline vector<int> getPazymiai() const {return pazymiai; }
        inline int getEgzaminas() const {return egzaminas; }
        inline double getVidurkis() const {return vidurkis; }
        //set
        inline void setVardas(string vardas) {Studentas::vardas = vardas; }
        inline void setPavarde(string pavarde) {Studentas::pavarde = pavarde; }
        inline void setPazymiai(vector<int> pazymiai) {Studentas::pazymiai = pazymiai; }
        inline void setEgz(int egz) {Studentas::egzaminas = egz; }
        inline void setVidurkis(double vidurkis) {Studentas::vidurkis = vidurkis; }
        inline void setPazymys(int pazymys) {pazymiai.push_back(pazymys); }
};

#endif