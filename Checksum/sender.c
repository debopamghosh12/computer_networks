#include <stdio.h>

int calculate_checksum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return ~sum;
}

int main() {
    int n;
    printf("Enter number of data segments: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the data segments (numbers): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int checksum = calculate_checksum(data, n);

    printf("Generated Checksum: %d\n", checksum);
    printf("Sent Data: ");
    for(int i=0; i<n; i++) printf("%d ", data[i]);
    printf("%d\n", checksum);

    return 0;
}