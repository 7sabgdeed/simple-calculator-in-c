#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stringy.h"
#include "read_and_validate.h"


void print_start_guideline();
int get_result(double* result, char operator, double num1, double num2);


int main () {

    print_start_guideline();

    while (true) {

        char operator = read_user_input_operator();
    
        if (operator == '\0') {
    
            printf("Failed to read user input operator.\n");
            exit(1);
    
        } else if (operator == 'q' || operator == 'Q') {
    
            printf("Okay, Salam.\n\n");
            exit(0);
        }
    
    
        double num1 = 0.0, num2 = 0.0;
    
    
        if (read_user_input_num(&num1, "first") != 0) {
    
            printf("Failed to read user input num.\n");
            exit(1);
        }
    
        if (read_user_input_num(&num2, "second") != 0) {
    
            printf("Failed to read user input num.\n");
            exit(1);
        }
    
    
        double result = 0.0;
        
    
        if (get_result(&result, operator, num1, num2) != 0) {
    
            printf("Error: Division by zero!\n\n");
            continue;
        }

        printf("%g %c %g = %g\n\n", num1, operator, num2, result);
    }


    return 0;
}


void print_start_guideline () {

    printf("=== Simple C Calculator ===\n");
    printf("Choose an operation:\n");
    printf("  +  Addition\n");
    printf("  -  Subtraction\n");
    printf("  *  Multiplication\n");
    printf("  /  Division\n");
    printf("  q  Quit\n");
    printf("\n");
}

int get_result(double* result, char operator, double num1, double num2) {


    switch (operator) {

        case '+':
            *result = num1 + num2;
            return 0;
            
        case '-':
            *result = num1 - num2;
            return 0;

        case '*':
            *result = num1 * num2;
            return 0;

        case '/':

            if (num2 == 0) {

                return -1;
            }

            *result = num1 / num2;
            return 0;
    }

    return -1;
}