//
// Created by ARA on 2023-10-24.
//
#include "ExpressionTree.h"

int main() {
    ETNode* root = NULL;

    char postfix_expression[20] = "71*52-/";
    ET_BuildExpressionTree(postfix_expression, &root);

    printf("Preorder...\n");
    ET_PreorderPrintTree(root);
    printf("\n\n");

    printf("Inorder...\n");
    ET_InorderPrintTree(root);
    printf("\n\n");

    printf("Postorder...\n");
    ET_PostorderPrintTree(root);
    printf("\n\n");

    printf("Evaluate Result : %f\n", ET_Evaluate(root));

    ET_DestroyTree(root);

    return 0;
}