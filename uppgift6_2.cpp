#include <iostream>
using namespace std;

int main() {
    int current_year, car_year, car_age;

    // Inmatning av aktuellt år och bilens årsmodell
    cout << "2024: ";
    cin >> current_year;

    cout << "1998: ";
    cin >> car_year;

    // Beräkna bilens ålder
    car_age = current_year - car_year;

    // Kontrollera vilken typ av försäkring som rekommenderas
    if (car_age < 0) {
        // Om användaren anger ett framtida årtal som årsmodell
        cout << "Fel: Årsmodellen kan inte vara senare än det aktuella året." << endl;
    } else if (car_age >= 25) {
        // Veteranbilförsäkring om bilen är minst 25 år gammal
        cout << "Välj en veteranbilförsäkring." << endl;
    } else if (car_age >= 5) {
        // Halvförsäkring om bilen är äldre än 5 år men inte en veteranbil
        cout << "Välj en halvförsäkring." << endl;
    } else {
        // Helförsäkring om bilen är yngre än 5 år
        cout << "Välj en helförsäkring." << endl;
    }

    return 0;
}
