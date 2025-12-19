#include <stdio.h>

int main() {
    int codeword[20], i, n, count = 0;

    printf("--- RECEIVER SIDE ---\n");
    printf("Enter number of bits received (Data + Parity): ");
    scanf("%d", &n);

    printf("Enter the received bits: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &codeword[i]);
        if(codeword[i] == 1)
            count++;
    }

    printf("\nReceived Codeword: ");
    for(i = 0; i < n; i++) printf("%d", codeword[i]);

    // Checking Parity
    if(count % 2 == 0) {
        printf("\n\nSTATUS: No Error Detected (Data Accepted) ✅\n");
    } else {
        printf("\n\nSTATUS: Error Detected (Data Rejected) ❌\n");
    }

    return 0;
}