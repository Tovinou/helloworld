#include <iostream>
#include <string>

class Car {
public:
    // Publika medlemsvariabler
    std::string brand;
    std::string model;
    int year;
    double mileage;

    // Konstruktör som tar in och initierar medlemsvariablerna
    Car(std::string carBrand, std::string carModel, int carYear, double carMileage)
        : brand(carBrand), model(carModel), year(carYear), mileage(carMileage) {}

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
