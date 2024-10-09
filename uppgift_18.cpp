#include <iostream>
using namespace std;

int main()
{
    int antal;  // Antal tal som användaren vill sortera
    
    // Läs in antal tal
    cout << "Hur många tal vill du mata in? ";
    cin >> antal;

    int tal[antal];  // Skapa en array för att lagra talen
    
    // Läs in talen från användaren
    cout << "Mata in " << antal << " heltal:" << endl;
    for (int i = 0; i < antal; i++) 
    {
        cin >> tal[i];
    }

    // Bubbelsortering av talen
    for (int i = 0; i < antal - 1; i++) 
    {
        for (int j = 0; j < antal - i - 1; j++) 
        {
            if (tal[j] > tal[j + 1]) 
            {
                // Byt plats om tal[j] är större än tal[j + 1]
                int temp = tal[j];
                tal[j] = tal[j + 1];
                tal[j + 1] = temp;
            }
        }
    }

    // Skriv ut de sorterade talen
    cout << "Talen i stigande ordning är:" << endl;
    for (int i = 0; i < antal; i++) 
    {
        cout << tal[i] << " ";
    }
    cout << endl;

    return 0;
}
