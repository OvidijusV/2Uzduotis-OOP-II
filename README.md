# Ovidijus Vaštakas, 2oji užduotis "Pažymių skaičiuoklė"


## Funkcijos
Vartotojas gali/turi:
* Pasirinkti ar generuoti duomenis ir nuskaityti automatiškai ar įvesti studento duomenis pačiam, nuskaityti iš failo
* Pasirinkus įvesti pačiam, prašoma įvesti studento vardą ir pavardę
* Pasirinkti ar žino atliktų namų darbų skaičių (t/n forma)
* Pasirinkti ar namų darbų rezultatus sugeneruoti atsitiktine tvarka ar įvesti pačiam
* Įvesti egzamino rezultatą
* Pasirinkti ar pridėti kitą studentą
* Pasirinkti galutinio pažymio skaičiavimo būdą (vidurkis arba mediana)
* Rikiavimas pagal studento pavardę
* Programa išveda gautus rezultatus panašiu pavidalu: 
```
Vardas      Pavarde            Galutinis Vid.(arba Mediana)
------------------------------------------------------------
Ovidijus    Bulka              5.00
Justas      Vairuotojas        7.49
Antanas     Programuotojas     6.33 
```
## Įdiegimo ir naudojimo instrukcija
* Įdiegimas ir naudojimas
  * Iš skilties "releases" pasirinkti norimą programos versiją ir atsisiųsti
  * Atsisiųstą kodą sukompiliuoti per komandinę eilutę (CMD) arba naudojamu IDE
  ```
  g++ -o programa main.cpp functions.cpp
  ```
  * Paleisti gautą vykdomąjį failą (.exe)
  ```
  ./programa
  Arba tiesiog atidaryti .exe failą tame aplanke kur atsisiuntėte programą
  ```
* Naudojimas
  * Paleidus failą iš pradžių pasirinkti ar norima sugeneruoti duomenis automatiškai ir nuskaityti ar įvesti duomenis pačiam, nuskaityti iš failo
  * Jei pasirinkta generuoti ir nuskaityti automatiškai, pasirenkama kokį kiekį studentų norima generuoti
  * Jei pasirinkta duomenis nuskaityti iš failo galima atsisiųsti kelis šablonus, norimą nuskaityti failą pervadinti į "kursiokai.txt"
  * Pasirinkus įvesti pačiam, įvesti studento vardą ir pavardę
  * Toliau atsakyti į programos užklausas įvedant t- TAIP, n- NE
  * Įvesti namų darbų ar egzamino rezultatus dešimtbalėje sistemoje
  * Pasirinkti ar norime, jog galutinis pažymis būtų skaičiuojamas kaip mediana - t, jei norime jog būtų išvestas vidurkis - n

## Versijos
[v0.1](https://github.com/OvidijusV/2Uzduotis-OOP/tree/v0.1) Vardo, pavardės ir pažymių įvestis, atsakymai į programos užklausas, galutinio pažymio skaičiavimas(vidurkis arba mediana)\
[v0.2](https://github.com/OvidijusV/2Uzduotis-OOP/tree/v0.2) Pridėta galimybe nuskaityti rezultatus iš failo, pridėtas automatinis rikiavimas pagal pavardes\
[v0.3](https://github.com/OvidijusV/2Uzduotis-OOP/tree/v0.3) Atliktas kodo reorganizavimas, pagrindinis failas išskirtas į antraščių ir funkcijų failą, pridėti keli pranešimai nepavykus įvykdyti programos\
[v0.4](https://github.com/OvidijusV/2Uzduotis-OOP/tree/v0.4) Pridėtas automatinis duomenų generavimas ir nuskaitymas iš failo, studentų rūšiavimas pagal galutinį vidurkį ir išvedimas į du atskirus failus
