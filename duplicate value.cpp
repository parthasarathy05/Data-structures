#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find elements repeated twice in an array
void findElementsRepeatedTwice(int arr[], int size) {
    int hash[MAX_SIZE] = {0};

    printf("Elements repeated twice in the array:\n");

    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;
        if (hash[arr[i]] == 2) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[MAX_SIZE];

    // Input the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    findElementsRepeatedTwice(arr, size);

    return 0;
}
