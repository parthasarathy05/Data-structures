#include <stdio.h>
int reverse 32BitSigned(int num) {
    int result = 0, i;
    for (i = 0; i < 32; i++) {
        result <<= 1;
        result |= num & 1;
        num >>= 1;
    }

    return result;
}

int main() {
    int num = 32768, i;
    printf("Original: %d\n", num);

    int reversed = reverse32BitSigned(num);
    printf("Reversed: %d\n", reversed);
    return 0;
}
