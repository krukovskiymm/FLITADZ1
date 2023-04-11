#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_binary(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

int binary_to_decimal(const char *binary) {
    int decimal = 0;
    for (int i = 0; binary[i]; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

int main() {
    const int max_input_size = 100;
    const int max_elements = 20;
    char input[max_input_size];
    char *elements[max_elements];
    int num_elements = 0;

    printf("Enter the elements separated by space:\n");
    fgets(input, max_input_size, stdin);

    char *token = strtok(input, " \n");
    while (token && num_elements < max_elements) {
        elements[num_elements++] = token;
        token = strtok(NULL, " \n");
    }

    printf("The entered array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s\t", elements[i]);
    }

    printf("\nArray of binary numbers:\n");
    for (int i = 0; i < num_elements; i++) {
        if (is_binary(elements[i])) {
            printf("%s\t", elements[i]);
        } else {
            printf("-\t");
        }
    }

    printf("\nArray of decimal numbers:\n");
    for (int i = 0; i < num_elements; i++) {
        if (is_binary(elements[i])) {
            printf("%d\t", binary_to_decimal(elements[i]));
        } else {
            printf("-\t");
        }
    }

    printf("\n");
    return 0;
}