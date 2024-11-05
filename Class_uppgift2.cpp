/* 
1- En destruktor är en metod som:

Har samma namn som klassen, men föregås av ett ~-tecken (till exempel ~Car() för en klass som heter Car).
Har ingen returtyp och tar inga parametrar.
Anropas automatiskt när objektet förstörs.
Den är en destruktor är en funktion som körs automatiskt när ett objekt av klassen går ur sitt giltighetsområde
Destruktorn används för att rensa upp minnesallokeringar och frigöra resurser som klassen kan ha använt under sin livstid.

2- En destruktor behövs när klassen:

Dynamiskt allokerar minne med new eller malloc.
Använder andra resurser, som filhanterare, nätverksanslutningar, eller dylikt, som måste frigöras korrekt.
Om klassen inte behöver hantera dynamiska resurser är det ofta onödigt att definiera en destruktor,
*/



#include <iostream>
#include <cstring>

class Car {
public:
    // Publika medlemsvariabler
    char* brand;  // Dynamisk array för märke
    char* model;  // Dynamisk array för modell
    int year;
    double mileage;

    // Konstruktör som tar in och initierar medlemsvariablerna
    Car(const char* carBrand, const char* carModel, int carYear, double carMileage)
        : year(carYear), mileage(carMileage) {
        // Dynamisk allokering och kopiering av brand
        brand = new char[strlen(carBrand) + 1]; // +1 för null-terminator
        strcpy(brand, carBrand);

        // Dynamisk allokering och kopiering av model
        model = new char[strlen(carModel) + 1]; // +1 för null-terminator
        strcpy(model, carModel);
    }

    // Destruktor för att frigöra dynamiskt allokerat minne
    ~Car() {
        delete[] brand;  // Frigör minnet för brand
        delete[] model;  // Frigör minnet för model
    }

    // Metod för att öka mätarställningen
    void drive(double distance) {
        if (distance > 0) {
            mileage += distance;
        }
    }

    // Metod för att visa information om bilen
    void displayInfo() const {
        std::cout << "Märke: " << brand << "\n"
                  << "Modell: " << model << "\n"
                  << "Årsmodell: " << year << "\n"
                  << "Mätarställning: " << mileage << " km\n";
    }

    // Metod för att få årsmodellen
    int getYear() const {
        return year;
    }

    // Metod för att få mätarställningen
    double getMileage() const {
        return mileage;
    }
};

int main() {
    // Skapa ett Car-objekt
    Car myCar("Volvo", "XC60", 2019, 35000);

    // Visa information om bilen
    std::cout << "Information om bilen:\n";
    myCar.displayInfo();

    // Kör en viss sträcka och uppdatera mätarställningen
    double distance = 150.0; // Exempel på sträcka i kilometer
    myCar.drive(distance);

    // Visa den uppdaterade informationen om bilen
    std::cout << "\nEfter att ha kört " << distance << " km:\n";
    myCar.displayInfo();

    return 0;
}
