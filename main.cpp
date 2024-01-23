#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// FUNKCIJOS PROTOTIPAS
void sistema(int &I, int &U, int &R, ifstream &fin);

// Pagrindine funkcija
int main()
{
    // Kintamieji saugoti srovei (I), �tampai (U) ir var�ai (R)
    int I;
    int U;
    int R;

    // Atidaromas failas duomenims skaityti
    ifstream fin("duomenys.txt");

    // Tikrinama, ar failas pavyko atidaryti
    if (!fin)
    {
        cout << "Failas neatidarytas" << endl;
        return -1; // Programa baigia darb� su klaida
    }

    // Isvedama lentel�s antra�t�
    cout << "------------------" << endl;
    cout << "  I  U  R  " << endl;
    cout << "------------------";

    // I�kvie�iama funkcija, kuri apdoroja duomenis
    sistema(I, U, R, fin);

    // Isvedama lentel�s apa�ia
    cout << "------------------" << endl;

    return 0; // Programos pabaiga be klaid�
}

// FUNKCIJA
void sistema(int &I, int &U, int &R, ifstream &fin)
{
    int n;

    // Nuskaitomas skai�ius n i� failo
    fin >> n;

    // Ciklas vykdomas n kartus, kur n - duomen� kiekis
    for (int i = 1; i <= n; i++)
    {
        // Nuskaitomi I, U, R reik�m�s
        fin >> I >> U >> R;

        // Apskai�iuojamos tr�kstamos reik�m�s, jei jos yra lygios 0
        if (I == 0)
            I = U / R;
        else if (U == 0)
            U = R * I;
        else if (R == 0)
            R = U / I;

        // Isvedama rezultat� lentel�
        cout << "  " << I << "  " << U << "  " << R << endl;
    }
}
