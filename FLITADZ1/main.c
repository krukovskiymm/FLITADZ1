#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int bynary_to_decimal (int sum, int number, int element, char error){
    number = 0, sum = 0;
    while (element > 2){
        sum = sum + pow(2, number) * (element % 10);
        number = number + 1;
        if (element % 10 != 1 && element % 10 != 0) {
            break;
        }
        element = element / 10;
    }
    if (element % 10 != 1 && element % 10 != 0) {
        error = '-';
        return error;
    }
    else {
        sum = sum + pow(2, number) * (element);
        return sum;
    }
}

int main() {
    int length, i, result, element, number, sum;
    char error;
    printf("Enter the length of a set of numbers:\n");
    scanf("%d", &length);
    int binary[length], decimal[length];
    printf("Enter %d elements:\n", length);

    for (i = 0; i <= length - 1; i++) {
        scanf("%d", &binary[i]);
        if (binary[i] < 0) {
            printf("The values you entered cannot be letters and be less than zero!\n");
            exit(EXIT_FAILURE);
        }
        decimal[i] = 0;
    }
    for (i = 0; i <= length - 1; i++){
        element = binary[i];
        result = bynary_to_decimal(sum, number, element, error);
        decimal[i] = result;
    }
    printf("Data array in the bynary system:\n");
    for (i = 0; i <= length - 1; i++) {
        printf("%d\t", binary[i]);
    }
    printf("\nData array in the decimal system:\n");
    for (i = 0; i <= length - 1; i++) {
        if (decimal[i] == '-') {
            printf("%c\t", decimal[i]);
        }
        else {
            printf("%d\t", decimal[i]);
        }
    }
}