#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read_and_validate.h"
#include "stringy.h"

char read_user_input_operator () {

    while (true) {

        char* user_input_operator = NULL;
        size_t user_input_size = 0;
    
        printf("Enter an operator (+, -, *, /) or q to quit: ");
    
    
        if (getline(&user_input_operator, &user_input_size, stdin) == -1) {
    
            free(user_input_operator);
            return '\0';
        }
    
        
        trim(user_input_operator);


        if (user_input_operator[1] != '\0') {

            free(user_input_operator);
            printf("Invalid operator.\n\n");
            continue;
        }
    
    
        char op = user_input_operator[0];

        if (op == '+' || op == '-' ||
            op == '*' || op == '/' ||
            op == 'q' || op == 'Q')
        {
            free(user_input_operator);
            return op;

        } else if (op == '\0') {

            free(user_input_operator);
            continue;
        }

        printf("Invalid operator.\n");
        printf("\n");
        free(user_input_operator);
    }
}


int read_user_input_num (double* user_input_num, const char* nth_num) {

    while (true) {

        char* user_input = NULL;
        size_t user_input_size = 0;

        printf("Enter the %s", strcmp(nth_num, "first") == 0 ? "first number : " : "second number: ");


        if (getline(&user_input, &user_input_size, stdin) == -1) {

            free(user_input);
            return -1;
        }

        trim(user_input);
        
        char* end;
        double result = strtod(user_input, &end);


        if (*end != '\0' || end == user_input) {

            free(user_input);
            printf("Enter a valid number.\n");
            continue;
        }


        *user_input_num = result;
        free(user_input);
        return 0;
    }
}