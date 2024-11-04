#include <iostream>
using namespace std;

class IntSmartPtr {
private:
    int* ptr;  // Den underliggande raw pointer

public:
    // Constructor
    IntSmartPtr(int* p = nullptr) : ptr(p) {
        cout << "Smart pointer created\n";
    }

    // Destructor - automatisk cleanup
    ~IntSmartPtr() {
        if (ptr != nullptr) {
            cout << "Deleting pointer with value: " << *ptr << endl;
            delete ptr;
        }
        cout << "Smart pointer destroyed\n";
    }

    // Kopieringskonstruktor - förhindra kopiering
    IntSmartPtr(const IntSmartPtr& other) = delete;

    // Tilldelningsoperator - förhindra kopiering
    IntSmartPtr& operator=(const IntSmartPtr& other) = delete;

    // Move konstruktor
    IntSmartPtr(IntSmartPtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // Move tilldelningsoperator
    IntSmartPtr& operator=(IntSmartPtr&& other) noexcept {
        if (this != &other) {
            delete ptr;  // Frigör existerande resurs
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Dereferencing operator
    int& operator*() {
        if (ptr == nullptr) {
            throw std::runtime_error("Dereferencing null pointer");
        }
        return *ptr;
    }

    // Arrow operator
    int* operator->() {
        if (ptr == nullptr) {
            throw std::runtime_error("Accessing null pointer");
        }
        return ptr;
    }

    // Get raw pointer
    int* get() const {
        return ptr;
    }

    // Check if pointer is null
    bool isNull() const {
        return ptr == nullptr;
    }
};

// Test programmet
int main() {
    // Skapa en smart pointer
    cout << "Creating first pointer\n";
    IntSmartPtr sp1(new int(42));
    
    // Använd pointern
    cout << "Value: " << *sp1 << endl;
    
    // Testa move semantics
    cout << "\nMoving pointer\n";
    IntSmartPtr sp2 = std::move(sp1);
    
    // sp1 är nu null, sp2 äger resursen
    cout << "Original pointer is null: " << sp1.isNull() << endl;
    cout << "New pointer value: " << *sp2 << endl;
    
    // Testa null check
    if (!sp2.isNull()) {
        cout << "Pointer is not null\n";
    }
    
    // Automatisk cleanup när scope avslutas
    cout << "\nExiting program\n";
    return 0;
}