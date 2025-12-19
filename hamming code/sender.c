#include <stdio.h>
#include <math.h>

int main() {
    int data[20], code[20], i, j, k, n, r = 0, m;

    printf("--- SENDER SIDE (Hamming Code) ---\n");
    printf("Enter number of data bits: ");
    scanf("%d", &n);

    printf("Enter data bits: ");
    for(i = 0; i < n; i++)
        scanf("%d", &data[i]);

    // Reversing data array to handle calculation from LSB easily
    // Usually input is like 1010, we process from right.
    for(i = 0; i < n/2; i++){
        int temp = data[i];
        data[i] = data[n-1-i];
        data[n-1-i] = temp;
    }

    // Calculate number of redundancy bits (r)
    // Formula: 2^r >= n + r + 1
    while(pow(2, r) < (n + r + 1)) {
        r++;
    }

    // Positioning bits (Powers of 2 are Parity, rest Data)
    int total_len = n + r;
    j = 0; // counter for data bits
    k = 0; // counter for parity bits (power of 2)

    for(i = 1; i <= total_len; i++) {
        if(i == pow(2, k)) {
            code[i] = 0; // Placeholder for parity
            k++;
        } else {
            code[i] = data[j];
            j++;
        }
    }

    // Calculating Parity Bits
    for(i = 0; i < r; i++) {
        int pos = pow(2, i);
        int sum = 0;
        
        // Hamming Logic to find parity value
        for(j = 1; j <= total_len; j++) {
            if(((j >> i) & 1) == 1) { // checking specific bit position
                if(j != pos)
                    sum += code[j];
            }
        }
        code[pos] = sum % 2; // Even Parity
    }

    printf("\nData Bits: ");
    for(i = n-1; i >= 0; i--) printf("%d ", data[i]);

    printf("\nRedundant Bits (r): %d", r);
    
    printf("\nSent Codeword: ");
    // Printing in correct order (MSB to LSB)
    for(i = total_len; i >= 1; i--)
        printf("%d", code[i]);
    printf("\n");

    return 0;
}