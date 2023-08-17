#include <stdio.h>

int main() {
    int arr[] = { 5, 12, 7, 3, 8, 6, 10, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Odd values in the array:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\nEven values in the array:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
