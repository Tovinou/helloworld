/*
- En kopieringskonstruktor är en konstruktor som används för att skapa en ny instans.
(ett nytt objekt) som en kopia av ett befintligt objekt. Kopieringskonstruktorn tar en referens till ett
objekt av samma klass som parameter och kopierar värdena från det objektet till det nya.
ex: Car(const Car &other);

- En kopieringskonstruktor är viktig när klassen:
Hanterar dynamiskt allokerat minne (till exempel med new).
Har pekare som behöver kopieras till nya minnesplatser (djupt kopierade) istället för att bara kopiera 
adressen till samma minnesplats (grunt kopierade).
Om man inte definierar en kopieringskonstruktor, genererar C++ en standardkopieringskonstruktor 
som gör en grun kopia, det vill säga kopierar endast värdena för alla medlemsvariabler "som de är".
Detta kan leda till problem när klassen har dynamiskt allokerat minne, eftersom flera objekt då kan
försöka hantera samma minnesadress, vilket kan leda till dubbelfrigöring och minnesläckor.

*/


#include <iostream>
#include <cstring>

class Car {
public:
    char* brand;  // Dynamisk array för märke
    char* model;  // Dynamisk array för modell
    int year;
    double mileage;

    // Konstruktör som tar in och initierar medlemsvariablerna
    Car(const char* carBrand, const char* carModel, int carYear, double carMileage)
        : year(carYear), mileage(carMileage) {
        // Dynamisk allokering och kopiering av brand
        brand = new char[strlen(carBrand) + 1];
        strcpy(brand, carBrand);

        // Dynamisk allokering och kopiering av model
        model = new char[strlen(carModel) + 1];
        strcpy(model, carModel);
    }

    // Kopieringskonstruktor (djupt kopiering)
    Car(const Car &other)
        : year(other.year), mileage(other.mileage) {
        // Allokera nytt minne för brand och kopiera innehållet
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);

        // Allokera nytt minne för model och kopiera innehållet
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
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
};

int main() {
    // Skapa ett Car-objekt
    Car myCar("Volvo", "XC60", 2019, 35000);

    // Använd kopieringskonstruktorn för att skapa en kopia av myCar
    Car copyCar = myCar;

    // Visa information om kopian
    std::cout << "Information om kopierad bil:\n";
    copyCar.displayInfo();

    return 0;
}
