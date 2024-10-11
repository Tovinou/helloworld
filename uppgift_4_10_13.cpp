#include <iostream>
#include <string>

using namespace std;

// Funktion som letar efter t1 i t2 och returnerar startindex om hittad, annars -1
int findSubstring(const string& t1, const string& t2) {
    // Använd string-metoden find för att hitta index där t1 börjar i t2
    size_t index = t2.find(t1);

    // Om delsträngen hittas, returnera dess startindex
    if (index != string::npos) {
        return static_cast<int>(index);  // Returnerar index där t1 börjar i t2
    }

    // Om delsträngen inte hittas, returnera -1
    return -1;
}

int main() {
    const string t1 = "deklaration";  // Delsträng
    const string t2 = "allmänna deklarationsbyrån";  // Sträng där vi letar

    // Anropa funktionen med konstanta referensparametrar
    int result = findSubstring(t1, t2);

    if (result != -1) {
        cout << "Delsträngen hittades på index: " << result << endl;
    } else {
        cout << "Delsträngen hittades inte." << endl;
    }

    return 0;
}
