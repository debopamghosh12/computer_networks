#include <stdio.h>
#include <string.h>

void xor_operation(char *dividend, char *divisor) {
    for (int i = 0; i < strlen(divisor); i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

int check_crc(char *received_data, char *divisor) {
    int data_len = strlen(received_data) - (strlen(divisor) - 1);
    int divisor_len = strlen(divisor);
    
    char current_block[divisor_len + 1];
    strncpy(current_block, received_data, divisor_len);
    current_block[divisor_len] = '\0';

    for (int i = 0; i < data_len; i++) {
        if (current_block[0] == '1') {
            xor_operation(current_block, divisor);
        }
        
        for (int j = 0; j < divisor_len - 1; j++) {
            current_block[j] = current_block[j + 1];
        }
        current_block[divisor_len - 1] = received_data[i + divisor_len];
        current_block[divisor_len] = '\0';
    }

    for (int i = 0; i < divisor_len - 1; i++) {
        if (current_block[i] == '1') return 0; 
    }
    return 1; 
}

int main() {
    char received_data[100], divisor[50];

    printf("Enter Received Data: ");
    scanf("%s", received_data);
    printf("Enter Divisor (Generator): ");
    scanf("%s", divisor);

    if (check_crc(received_data, divisor)) {
        printf("Data Accepted! No Error.\n");
    } else {
        printf("Data Rejected! Error Detected.\n");
    }

    return 0;
}