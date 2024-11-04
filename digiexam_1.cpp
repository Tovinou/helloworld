#include <iostream>


// Allokera en enskild int
int* ptr = new int;
*ptr = 5;
delete ptr; // Frigör minnet

// Allokera en array
int* arr = new int[5];
arr[0] = 1;
delete[] arr; // Frigör array-minnet

//exemple
// Dynamisk array vars storlek bestäms vid körning
cout << "Hur många element? ";
int size;
cin >> size;
int* dynamicArray = new int[size];

// Använd arrayen...

delete[] dynamicArray;