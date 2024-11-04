#include <iostream>
using namespace std;

int main() {
    // 1. lokal variabler
    int number = 42;
    double decimal = 3.14;
    
    // 2. Deklarera pekare
    int* numberPtr;      // Pekare till int
    double* decimalPtr;  // Pekare till double
    
    // 3. Initialisera pekare med adresser
    numberPtr = &number;     // & ger adressen till number, referens
    decimalPtr = &decimal;   // & ger adressen till decimal, referens
    
    // 4. Visa värden och adresser
    cout << "number värde: " << number << endl;
    cout << "number adress: " << &number << endl;
    cout << "numberPtr pekar på adress: " << numberPtr << endl;
    cout << "numberPtr derefererat värde: " << *numberPtr << endl;
    
    cout << "\ndecimal värde: " << decimal << endl;
    cout << "decimal adress: " << &decimal << endl;
    cout << "decimalPtr pekar på adress: " << decimalPtr << endl;
    cout << "decimalPtr derefererat värde: " << *decimalPtr << endl;
    
    // 5. Ändra värden via pekare
    *numberPtr = 100;    // Ändrar värdet på number via pekaren
    *decimalPtr = 6.28;  // Ändrar värdet på decimal via pekaren
    
    cout << "\nEfter ändring via pekare:" << endl;
    cout << "number nytt värde: " << number << endl;
    cout << "decimal nytt värde: " << decimal << endl;
    
    return 0;
}