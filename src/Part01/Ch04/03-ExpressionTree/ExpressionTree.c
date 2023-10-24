//
// Created by ARA on 2023-10-24.
//

#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType new_data)
{
    ETNode* new_node = (ETNode*)malloc(sizeof(ETNode));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = new_data;

    return new_node;
}

void ET_DestroyNode(ETNode* node)
{
    free(node);
}

void ET_DestroyTree(ETNode* node)
{
    if (node == NULL)
    {
        return;
    }

    ET_DestroyTree(node->left);
    ET_DestroyTree(node->right);

    ET_DestroyNode(node);
}

void ET_PreorderPrintTree(ETNode* node)
{
    if (node == NULL)
    {
        return;
    }

    printf("  %c", node->data);

    ET_PreorderPrintTree(node->left);
    ET_PreorderPrintTree(node->right);
}

void ET_InorderPrintTree(ETNode* node)
{
    if (node == NULL)
    {
        return;
    }

    printf("( ");
    ET_InorderPrintTree(node->left);
    printf("%c", node->data);
    ET_InorderPrintTree(node->right);
    printf(" )");
}

void ET_PostorderPrintTree(ETNode* node)
{
    if (node == NULL)
    {
        return;
    }

    ET_PostorderPrintTree(node->left);
    ET_PostorderPrintTree(node->right);
    printf("  %c", node->data);
}

void ET_BuildExpressionTree(char* postfix_expression, ETNode** node)
{
    int len = strlen(postfix_expression);
    char token = postfix_expression[len - 1];
    postfix_expression[len - 1] = '\0';

    switch (token)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        (*node) = ET_CreateNode(token);
        ET_BuildExpressionTree(postfix_expression, &(*node)->right);
        ET_BuildExpressionTree(postfix_expression, &(*node)->left);
        break;
    default:
        (*node) = ET_CreateNode(token);
        break;
    }
}

double ET_Evaluate(ETNode* tree)
{
    char temp[2];

    double left = 0;
    double right = 0;
    double result = 0;

    if (tree == NULL) {
        return 0;
    }

    switch (tree->data)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        left = ET_Evaluate(tree->left);
        right = ET_Evaluate(tree->right);

        if (tree->data == '+') result = left + right;
        else if (tree->data == '-') result = left - right;
        else if (tree->data == '*') result = left * right;
        else if (tree->data == '/') result = left / right;

        break;

    default:
        memset(temp, 0, sizeof (temp));
        temp[0] = tree->data;
        result = atof(temp);
        break;
    }

    return result;
}
