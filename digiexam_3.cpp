#include <stdio.h>
#include <stdlib.h>

void memoryLeak() {
    int *ptr = (int *)malloc(sizeof(int)); // Allokera minne
    *ptr = 10; // Använd pekaren
    // Frigör aldrig minnet
    // Minnesläcka eftersom minnet inte frigörs
}

void doubleFree() {
    int *ptr = (int *)malloc(sizeof(int)); // Allokera minne
    *ptr = 20; // Använd pekaren

    free(ptr); // Frigör minnet första gången
    free(ptr); // Frigör minnet en gång till (dubbel frigöring)
}

void danglingPointer() {
    int *ptr = (int *)malloc(sizeof(int)); // Allokera minne
    *ptr = 30; // Använd pekaren

    free(ptr); // Frigör minnet
    *ptr = 40; // Försöker använda en frigjord pekare (dangling pointer)
}

int main() {
    memoryLeak();
    doubleFree();
    danglingPointer();
    return 0;
}
