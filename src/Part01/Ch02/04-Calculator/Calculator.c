//
// Created by ARA on 2023-10-07.
//

#include "Calculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

int IsNumber(char cipher)
{
    int array_length = sizeof(NUMBER);

    for (int i = 0; i < array_length; ++i)
    {
        if (cipher == NUMBER[i])
        {
            return 1;
        }
    }

    return 0;
}

unsigned int GetNextToken(char* expression, char* token, int* type)
{
    unsigned int i = 0;
    for (i = 0; 0 != expression[i]; ++i)
    {
        token[i] = expression[i];

        if (IsNumber(expression[i]) == 1)
        {
            *type = OPERAND;

            if (IsNumber(expression[i + 1]) != 1)
                break;
        }
        else
        {
            *type = expression[i];
            break;
        }
    }
    token[++i] = '\0';
    return i;
}

int GetPriority(char operator, int in_stack)
{
    int priority = -1;

    switch (operator)
    {
    case LEFT_PARENTHESIS :
        if (in_stack)
            priority = 3;
        else
            priority = 0;
        break;

    case MULTIPLY :
    case DIVIDE :
        priority = 1;
        break;

    case PLUS:
    case MINUS :
        priority = 2;
        break;
    }

    return priority;
}

int IsPrior(char operator_in_stack, char operator_in_token)
{
    return (GetPriority(operator_in_stack, 1) > GetPriority(operator_in_token, 0));
}

void GetPostfix(char* infix_expression, char* postfix_expression)
{
    LinkedListStack* stack;

    char token[32];
    int type = -1;
    unsigned int position = 0;
    unsigned int length = strlen(infix_expression);

    LLS_CreateStack(&stack);

    while (position < length)
    {
        position += GetNextToken(&infix_expression[position], token, &type);

        if (type == OPERAND)
        {
            strcat(postfix_expression, token);
            strcat(postfix_expression, " ");
        }
        else if (type == RIGHT_PARENTHESIS)
        {
            while (!LLS_IsEmpty(stack))
            {
                Node* popped = LLS_Pop(stack);

                if (popped->data[0] == LEFT_PARENTHESIS)
                {
                    LLS_DestroyNode(popped);
                    break;
                }
                else
                {
                    strcat(postfix_expression, popped->data);
                    LLS_DestroyNode(popped);
                }
            }
        }
        else
        {
            while (!LLS_IsEmpty(stack) && !IsPrior(LLS_Top(stack)->data[0], token[0]))
            {
                Node* popped = LLS_Pop(stack);

                if (popped->data[0] != LEFT_PARENTHESIS)
                {
                    strcat(postfix_expression, popped->data);
                }

                LLS_DestroyNode(popped);
            }

            LLS_Push(stack, LLS_CreateNode(token));
        }
    }

    while (!LLS_IsEmpty(stack))
    {
        Node* popped = LLS_Pop(stack);

        if (popped->data[0] != LEFT_PARENTHESIS)
            strcat(postfix_expression, popped->data);

        LLS_DestroyNode(popped);
    }

    LLS_DestroyStack(stack);
}

double Calculate(char* postfix_expression)
{
    LinkedListStack* stack;
    Node* result_node;

    double result;
    char token[32];
    int type = -1;
    unsigned int read = 0;
    unsigned int length = strlen(postfix_expression);

    LLS_CreateStack(&stack);

    while (read < length)
    {
        read += GetNextToken(&postfix_expression[read], token, &type);

        if (type == SPACE)
            continue;

        if (type == OPERAND)
        {
            Node* new_node = LLS_CreateNode(token);
            LLS_Push(stack, new_node);
        }
        else
        {
            char result_string[32];
            double operand1, operand2, temp_result;
            Node* operator_node;

            operator_node = LLS_Pop(stack);
            operand2 = atof(operator_node->data);
            LLS_DestroyNode(operator_node);

            operator_node = LLS_Pop(stack);
            operand1 = atof(operator_node->data);
            LLS_DestroyNode(operator_node);

            switch (type)
            {
            case PLUS:
                temp_result = operand1 + operand2;
                break;
            case MINUS:
                temp_result = operand1 - operand2;
                break;
            case MULTIPLY :
                temp_result = operand1 * operand2;
                break;
            case DIVIDE :
                temp_result = operand1 / operand2;
                break;
            }

            gcvt(temp_result, 10, result_string);
            LLS_Push(stack, LLS_CreateNode(result_string));
        }
    }

    result_node = LLS_Pop(stack);
    result = atof(result_node->data);

    LLS_DestroyNode(result_node);
    LLS_DestroyStack(stack);

    return result;
}


