//
// Created by ARA on 2023-10-07.
//

#include "Calculator.h"

int main() {
    char infix_expression[100];
    char postfix_expression[100];

    double result = 0.0;

    memset(infix_expression, 0, sizeof(infix_expression));
    memset(postfix_expression, 0, sizeof(postfix_expression));

    printf("Enter Infix Expression:");
    scanf("%s", infix_expression);

    GetPostfix(infix_expression, postfix_expression);

    printf("Infix:%s\nPostfix:%s\n", infix_expression, postfix_expression);

    result = Calculate(postfix_expression);

    printf("Calculation Result : %f\n", result);

    return 0;
}