#include <iostream>
#include <memory>  // Krävs för smart pointers
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource skapad\n"; }
    ~Resource() { cout << "Resource borttagen\n"; }
    void doWork() { cout << "Utför arbete\n"; }
};

int main() {
    // 1. unique_ptr - Exklusivt ägande
    {
        unique_ptr<Resource> ptr1 = make_unique<Resource>();
        ptr1->doWork();
        
        // Kan inte kopiera unique_ptr
        // unique_ptr<Resource> ptr2 = ptr1;  // Kompileringsfel!
        
        // Men kan flytta ägandet
        unique_ptr<Resource> ptr2 = move(ptr1);
        ptr2->doWork();
        
        // ptr1 är nu nullptr
        if (ptr1 == nullptr) {
            cout << "ptr1 är nu null\n";
        }
    } // Resursen frigörs automatiskt här
    
    cout << "\n-----------------\n";
    
    // 2. shared_ptr - Delat ägande
    {
        shared_ptr<Resource> ptr1 = make_shared<Resource>();
        cout << "Antal ägare: " << ptr1.use_count() << endl;
        
        {
            shared_ptr<Resource> ptr2 = ptr1;  // OK att kopiera
            cout << "Antal ägare: " << ptr1.use_count() << endl;
            ptr2->doWork();
        } // ptr2 förstörs, men resursen lever kvar
        
        cout << "Antal ägare: " << ptr1.use_count() << endl;
    } // Resursen frigörs när sista ägaren förstörs
    
    cout << "\n-----------------\n";
    
    // 3. weak_ptr - Svag referens till shared_ptr
    {
        shared_ptr<Resource> shared = make_shared<Resource>();
        weak_ptr<Resource> weak = shared;
        
        if (auto temp = weak.lock()) {  // Kontrollera om objektet finns
            temp->doWork();
        }
        
        shared.reset();  // Frigör resursen
        
        if (weak.expired()) {
            cout << "Objektet finns inte längre\n";
        }
    }
}