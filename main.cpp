#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// FUNKCIJOS PROTOTIPAS
void sistema(int &I, int &U, int &R, ifstream &fin);

// Pagrindine funkcija
int main()
{
    // Kintamieji saugoti srovei (I), átampai (U) ir varþai (R)
    int I;
    int U;
    int R;

    // Atidaromas failas duomenims skaityti
    ifstream fin("duomenys.txt");

    // Tikrinama, ar failas pavyko atidaryti
    if (!fin)
    {
        cout << "Failas neatidarytas" << endl;
        return -1; // Programa baigia darbà su klaida
    }

    // Isvedama lentelës antraðtë
    cout << "------------------" << endl;
    cout << "  I  U  R  " << endl;
    cout << "------------------";

    // Iðkvieèiama funkcija, kuri apdoroja duomenis
    sistema(I, U, R, fin);

    // Isvedama lentelës apaèia
    cout << "------------------" << endl;

    return 0; // Programos pabaiga be klaidø
}

// FUNKCIJA
void sistema(int &I, int &U, int &R, ifstream &fin)
{
    int n;

    // Nuskaitomas skaièius n ið failo
    fin >> n;

    // Ciklas vykdomas n kartus, kur n - duomenø kiekis
    for (int i = 1; i <= n; i++)
    {
        // Nuskaitomi I, U, R reikðmës
        fin >> I >> U >> R;

        // Apskaièiuojamos trûkstamos reikðmës, jei jos yra lygios 0
        if (I == 0)
            I = U / R;
        else if (U == 0)
            U = R * I;
        else if (R == 0)
            R = U / I;

        // Isvedama rezultatø lentelë
        cout << "  " << I << "  " << U << "  " << R << endl;
    }
}
