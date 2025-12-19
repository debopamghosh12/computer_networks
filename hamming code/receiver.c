#include <stdio.h>
#include <math.h>

int main() {
    int code[20], n, i, j, r = 0, error_pos = 0;

    printf("--- RECEIVER SIDE (Hamming Code) ---\n");
    printf("Enter total number of bits received: ");
    scanf("%d", &n);

    // Calculate 'r' based on input length
    while(pow(2, r) < n + 1) {
        r++;
    }

    printf("Enter received bits (one by one, MSB to LSB): ");
    // Storing in reverse logic to match 1-based indexing easily
    for(i = n; i >= 1; i--) {
        scanf("%d", &code[i]);
    }

    // Detecting Error
    for(i = 0; i < r; i++) {
        int pos = pow(2, i);
        int sum = 0;

        for(j = 1; j <= n; j++) {
            if(((j >> i) & 1) == 1) {
                sum += code[j];
            }
        }
        
        // If parity is odd, add position value to error_pos
        if(sum % 2 != 0) {
            error_pos += pos;
        }
    }

    if(error_pos == 0) {
        printf("\nSTATUS: No Error Detected! Correct Data. ✅\n");
    } else {
        printf("\nSTATUS: Error Detected at Position: %d ❌\n", error_pos);
        
        // Correcting the error
        if(code[error_pos] == 0) code[error_pos] = 1;
        else code[error_pos] = 0;

        printf("Corrected Codeword: ");
        for(i = n; i >= 1; i--) printf("%d", code[i]);
        printf("\n");
    }

    return 0;
}