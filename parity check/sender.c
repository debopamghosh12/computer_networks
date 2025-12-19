#include <stdio.h>

int main() {
    int data[10], i, n, count = 0;

    printf("--- SENDER SIDE ---\n");
    printf("Enter number of data bits: ");
    scanf("%d", &n);

    printf("Enter the data bits (space separated): ");
    for(i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        if(data[i] == 1)
            count++;
    }

    // Even Parity Logic:
    // If 1s are Odd, Parity bit = 1 (to make it even)
    // If 1s are Even, Parity bit = 0
    int parity_bit = (count % 2 == 0) ? 0 : 1;

    printf("\nOriginal Data: ");
    for(i = 0; i < n; i++) printf("%d", data[i]);

    printf("\nParity Bit Added: %d", parity_bit);

    printf("\n\nSent Codeword (Data + Parity): ");
    for(i = 0; i < n; i++) printf("%d", data[i]);
    printf("%d\n", parity_bit);

    return 0;
}