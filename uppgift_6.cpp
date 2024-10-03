#include <iostream>
#include <iomanip> // För att hantera decimaler
using namespace std;

int main() {
    int current_meter, previous_meter;
    double fuel_liter;

    // Läs in mätarställningarna och bränsleförbrukningen
    cout << "1487 (i km): ";
    cin >> current_meter;

    cout << "0 (i km): ";
    cin >> previous_meter;

    cout << "0.83 (i liter): ";
    cin >> fuel_liter;

    // Beräkna körd sträcka i mil (1 mil = 10 km)
    int miles_drive = (current_meter - previous_meter) / 10;

    // Kontrollera att vi inte dividerar med 0 ifall bilen inte körts alls
    if (miles_drive == 0) {
        cout << "Ingen sträcka körd, omöjligt att beräkna förbrukning." << endl;
    } else {
        // Beräkna genomsnittlig bränsleförbrukning per mil
        double used_fuel = fuel_liter / miles_drive;

        // Använd fixed och setprecision för att visa decimaler
        cout << fixed << setprecision(2); // Sätt precision till 2 decimaler
        
        // Visa resultat
        cout << "Antal körda mil: " << miles_drive << " mil." << endl;
        cout << "Antal liter bensin förbrukad: " << fuel_liter << " liter." << endl;
        cout << "Genomsnittlig bensinförbrukning: " << used_fuel << " liter per mil." << endl;
    }

    return 0;
}
