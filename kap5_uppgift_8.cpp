#include <iostream>
using namespace std;

// Funktion som kopierar source till slutet av destination
char* strcat(char* destination, const char* source) {
    // Hitta slutet av destination-strängen
    char* ptr = destination;
    while (*ptr != '\0') {
        ptr++;
    }

    // Kopiera tecknen från source till slutet av destination
    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }

    // Lägg till en null-terminator på slutet av den nya strängen
    *ptr = '\0';

    return destination;  // Returnera pekaren till destination-strängen
}

int main() {
    char destination[50] = "Hello, ";  // Utrymme för extra tecken
    const char* source = "World!";

    strcat(destination, source);  // Konkatenering av source till destination
    cout << "Resultat: " << destination << endl;  // Skriver ut "Hello, World!"

    return 0;
}
