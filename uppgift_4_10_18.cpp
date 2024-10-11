#include <iostream>

using namespace std;

// Rekursiv funktion som beräknar månadslönen för ett givet år
double calculateSalary(int year) {
    // Basfall: år 1 är lönen fast till 15000 kr
    if (year == 1) {
        return 15000;
    }

    // Rekursivt fall: lönen är 4% ökning från föregående år + 400 kr
    double previousYearSalary = calculateSalary(year - 1);
    return previousYearSalary * 1.04 + 400;
}

int main() {
    int year;
    cout << "Ange år för att beräkna månadslönen: ";
    cin >> year;

    // Beräkna månadslönen för det angivna året
    double salary = calculateSalary(year);

    cout << "Månadslönen för år " << year << " är: " << salary << " kr" << endl;

    return 0;
}
