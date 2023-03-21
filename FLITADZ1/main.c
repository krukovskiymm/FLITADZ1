#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int bynary_to_decimal(int sum, int number, int element, char *error) {
    number = 0, sum = 0;
    while (element > 2) {
        sum = sum + pow(2, number) * (element % 10);
        number = number + 1;
        if (element % 10 != 1 && element % 10 != 0) {
            *error = '-';
            return -1;
        }
        element = element / 10;
    }
    if (element % 10 != 1 && element % 10 != 0) {
        *error = '-';
        return -1;
    } else {
        sum = sum + pow(2, number) * (element);
        return sum;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s binary1 binary2 ... binaryN\n", argv[0]);
        return -1;
    }

    int length = argc - 1, i, result, element, number, sum;
    char error;
    int binary[length], decimal[length];

    for (i = 1; i <= length; i++) {
        char *str = argv[i];
        int j = 0;
        while (str[j]) {
            if (!isdigit(str[j]) || (str[j] != '0' && str[j] != '1')) {
                printf("Error: '%s' is not a binary number!\n", str);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        binary[i-1] = atoi(str);
        decimal[i-1] = 0;
    }

    for (i = 0; i < length; i++) {
        element = binary[i];
        result = bynary_to_decimal(sum, number, element, &error);
        if (result < 0) {
            decimal[i] = error;
        } else {
            decimal[i] = result;
        }
    }

    printf("Data array in the binary system:\n");
    for (i = 0; i < length; i++) {
        printf("%d\t", binary[i]);
    }
    printf("\nData array in the decimal system:\n");
    for (i = 0; i <= length - 1; i++) {
        printf("%d\t", decimal[i]);
    }
}