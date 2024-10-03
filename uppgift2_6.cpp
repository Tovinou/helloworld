#include <iostream>
using namespace std;

int main() {
    int price, amount_paid, change;
    
    // Inmatning av pris och belopp betalat
    cout << "711 (i kronor): ";
    cin >> price;

    cout << "1000 (i kronor): ";
    cin >> amount_paid;

    // Beräkna växeln
    change = amount_paid - price;

    if (change < 0) {
        cout << "Fel: Betalat belopp är mindre än priset." << endl;
        return 1; // Avsluta programmet vid fel
    }

    cout << "Växel att få tillbaka: " << change << " kr" << endl;

    // Definiera valörer
    int denominations[] = {100, 50, 20, 10, 5, 1}; // Sedlar och mynt
    int count[6] = {0}; // Räkna hur många av varje valör som behövs

    // Beräkna växeln i sedlar och mynt
    for (int i = 0; i < 6; i++) {
        while (change >= denominations[i]) {
            change -= denominations[i];
            count[i]++;
        }
    }

    // Skriv ut resultaten
    if (count[0] > 0) cout << count[0] << " hundrakronorssedlar" << endl;
    if (count[1] > 0) cout << count[1] << " femtiokronorssedlar" << endl;
    if (count[2] > 0) cout << count[2] << " tjugokronorssedlar" << endl;
    if (count[3] > 0) cout << count[3] << " tiokronorsmynt" << endl;
    if (count[4] > 0) cout << count[4] << " femkronorsmynt" << endl;
    if (count[5] > 0) cout << count[5] << " en-kronor" << endl;

    return 0;
}
