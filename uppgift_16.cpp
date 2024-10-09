#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int maxantal = 100;
    const float grans = 50000., pro1 = 0.1, pro2 = 0.15;
    float tab[maxantal], belopp, arvode;
    int nr[maxantal], i, j, tempNr;  // Skapa en array för försäljningsnummer
    
    // Nollställ tabellen och nummer
    for (i = 0; i < maxantal; i++)
    {
        tab[i] = 0;    // Specificera arrayen "tab"
        nr[i] = i + 1; // försäljningsnumren till 1, 2, 3, ..., 100
    }
    
    // Läs in försäljningsuppgifter
    while (cin >> tempNr >> belopp)
    {
        if (tempNr < 1 || tempNr > maxantal || belopp < 0)  
            cout << "Felaktiga indata" << endl;
        else
            tab[tempNr - 1] += belopp;
    }

    // Sortera fältet "tab" och motsvarande nummer "nr" med bubbelsort
    for (i = 0; i < maxantal - 1; i++) 
    {
        for (j = 0; j < maxantal - i - 1; j++) 
        {
            if (tab[j] < tab[j + 1]) // Sortera i fallande ordning
            {
                // Byt plats på försäljningsbeloppen
                float tempBelopp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tempBelopp;

                // Byt även plats på motsvarande försäljningsnummer
                int tempNummer = nr[j];
                nr[j] = nr[j + 1];
                nr[j + 1] = tempNummer;
            }
        }
    }

    // Skriv sammanställning
    cout << endl
         << "Nummer   Belopp     Arvode" << endl  
         << "======   ======     ======" << endl;
    
    for (i = 0; i < maxantal; i++)
    {
        if (tab[i] > 0)
        {
            if (tab[i] <= grans)
                arvode = pro1 * tab[i];  
            else
                arvode = pro1 * grans + pro2 * (tab[i] - grans);
            
            // Skriv ut sorterade nummer, belopp och arvoden
            cout << setw(4) << nr[i] << setprecision(0) << fixed
                 << setw(13) << tab[i] << setw(10) << arvode << endl;
        }
    }

    return 0;
}