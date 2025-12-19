#include <stdio.h>

int verify_checksum(int a[], int n, int checksum) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    sum += checksum;
    return ~sum;
}

int main() {
    int n, checksum;
    printf("Enter number of data segments: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the received data segments: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printf("Enter the received Checksum: ");
    scanf("%d", &checksum);

    if (verify_checksum(data, n, checksum) == 0) {
        printf("Data Accepted! No Error.\n");
    } else {
        printf("Data Rejected! Error Detected.\n");
    }

    return 0;
}