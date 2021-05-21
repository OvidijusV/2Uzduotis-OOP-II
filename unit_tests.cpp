#define CATCH_CONFIG_MAIN
#include "declarations.h"

TEST_CASE("Klasės studentas tikrinimas", "[Studentas]") 
{

    Studentas studentas;

    REQUIRE(studentas.getPazymiai().size() == 0);
    SECTION("Set Vardas ir Pavarde") 
    {
        studentas.setVardas("TestName");
        studentas.setPavarde("TestSurname");

        REQUIRE(studentas.getVardas() == "TestName");
        REQUIRE(studentas.getPavarde() == "TestSurname");
    }
    SECTION("Namu darbo rezultato pridejimas i vektoriu ir egzamino priskyrimas") 
    {
        studentas.setPazymys(7);
        studentas.setEgz(4);

        REQUIRE(studentas.getPazymiai().size() == 1);
        REQUIRE(studentas.getPazymiai().at(0) == 7);
        REQUIRE(studentas.getEgzaminas() == 7);
    }
    SECTION("Vidurkio skaičiavimas") 
    {
        std::vector<int> pazymiaiV{7, 7, 7, 7, 7};
        studentas.setPazymiai(pazymiaiV);

        REQUIRE(studentas.getVidurkis() == 7.0);
    }
}