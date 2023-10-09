//
// Created by ARA on 2023-10-07.
//

#ifndef THIS_IS_DS_ALGORITHM_CALCULATOR_H
#define THIS_IS_DS_ALGORITHM_CALCULATOR_H

#include <stdio.h>
#include "../03-LinkedListStack/LinkedListStack.h"

typedef enum
{
    LEFT_PARENTHESIS = '(',
    RIGHT_PARENTHESIS = ')',
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
    SPACE = ' ',
    OPERAND
} SYMBOL;

int IsNumber(char cipher);
unsigned int GetNextToken(char* expression, char* token, int* type);
int GetPriority(char operator, int in_stack);
int IsPrior(char operator_in_stack, char operator_in_token);
void GetPostfix(char* infix_expression, char* postfix_expression);
double Calculate(char* postfix_expression);

#endif //THIS_IS_DS_ALGORITHM_CALCULATOR_H
