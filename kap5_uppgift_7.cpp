#include <iostream>
using namespace std;

// Funktion för att kopiera en sträng till ett annat fält
bool copyString(char *destination, const char *source, size_t destinationSize) {
    size_t i = 0;

    // Kopiera tecken en efter en tills vi når slutet av källsträngen eller maxstorleken
    while (source[i] != '\0') {
        if (i >= destinationSize - 1) {  // Säkerställa att vi inte går utanför destinationens storlek
            return false;  // Misslyckades eftersom destinationen inte har tillräckligt med utrymme
        }
        destination[i] = source[i];  // Kopiera tecken
        i++;
    }

    destination[i] = '\0';  // Lägg till avslutande null-terminator
    return true;  // Kopieringen lyckades
}

int main() {
    const size_t size = 10;
    char destination[size];
    const char *source = "Hello";

    if (copyString(destination, source, size)) {
        cout << "Kopiering lyckades: " << destination << endl; 
    } else {
        cout << "Kopiering misslyckades: destinationens fält är för litet." << endl;
    }

    return 0;
}
