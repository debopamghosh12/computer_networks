#include <stdio.h>
#include <string.h>

void xor_operation(char *dividend, char *divisor) {
    for (int i = 0; i < strlen(divisor); i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

void calculate_crc(char *data, char *divisor, char *result) {
    int data_len = strlen(data);
    int divisor_len = strlen(divisor);
    char temp[data_len + divisor_len];

    strcpy(temp, data);
    for (int i = 0; i < divisor_len - 1; i++) {
        temp[data_len + i] = '0';
    }
    temp[data_len + divisor_len - 1] = '\0';

    char current_block[divisor_len + 1];
    strncpy(current_block, temp, divisor_len);
    current_block[divisor_len] = '\0';

    for (int i = 0; i < data_len; i++) {
        if (current_block[0] == '1') {
            xor_operation(current_block, divisor);
        }
        
        for (int j = 0; j < divisor_len - 1; j++) {
            current_block[j] = current_block[j + 1];
        }
        current_block[divisor_len - 1] = temp[i + divisor_len];
        current_block[divisor_len] = '\0';
    }

    strcpy(result, current_block);
}

int main() {
    char data[100], divisor[50], crc[50];

    printf("Enter Data bits: ");
    scanf("%s", data);
    printf("Enter Divisor (Generator): ");
    scanf("%s", divisor);

    calculate_crc(data, divisor, crc);

    printf("CRC is: %s\n", crc);
    printf("Transmitted Data (Data + CRC): %s%s\n", data, crc);

    return 0;
}