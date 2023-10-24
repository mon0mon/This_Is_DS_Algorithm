//
// Created by ARA on 2023-10-24.
//

#ifndef THIS_IS_DS_ALGORITHM_EXPRESSIONTREE_H
#define THIS_IS_DS_ALGORITHM_EXPRESSIONTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagETNode
{
    struct tagETNode* left;
    struct tagETNode* right;

    ElementType data;
} ETNode;

ETNode* ET_CreateNode(ElementType new_data);
void ET_DestroyNode(ETNode* node);
void ET_DestroyTree(ETNode* node);

void ET_PreorderPrintTree(ETNode* node);
void ET_InorderPrintTree(ETNode* node);
void ET_PostorderPrintTree(ETNode* node);
void ET_BuildExpressionTree(char* postfix_expression, ETNode** node);
double ET_Evaluate(ETNode* tree);

#endif //THIS_IS_DS_ALGORITHM_EXPRESSIONTREE_H
