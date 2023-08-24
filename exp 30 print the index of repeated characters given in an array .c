#include <stdio.h>
#include <stdbool.h>

int main() {
    int size;

    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    char array[size];

    
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &array[i]);
    }

    bool found[256] = {false}; 

    printf("Repeated characters and their indices:\n");
    for (int i = 0; i < size; i++) {
        if (found[array[i]]) {
            printf("Character '%c' at index %d\n", array[i], i);
        } else {
            found[array[i]] = true;
        }
    }

    return 0;
}

