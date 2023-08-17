#include <stdio.h>

#define MAX_REGNOS 100

int searchRegNo(int regNos[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (regNos[i] == target) {
            return i; // Return the index where the reg no was found
        }
    }
    return -1; // Return -1 if the reg no was not found
}

int main() {
    int size, target;

    // Input the size of the array
    printf("Enter the number of registration numbers: ");
    scanf("%d", &size);

    int regNos[MAX_REGNOS];

    // Input the registration numbers
    printf("Enter the registration numbers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &regNos[i]);
    }

    // Input the target registration number to search for
    printf("Enter the registration number to search for: ");
    scanf("%d", &target);

    int index = searchRegNo(regNos, size, target);

    if (index != -1) {
        printf("Registration number %d found at index %d\n",  target, index);
    } else {
        printf("Registration number %d not found\n", target);
    }

    return 0;
}
