//
// Created by ARA on 2023-10-24.
//

#ifndef THIS_IS_DS_ALGORITHM_BINARYTREE_H
#define THIS_IS_DS_ALGORITHM_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode* left;
    struct tagSBTNode* right;

    ElementType data;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType new_data);
void SBT_DestroyNode(SBTNode* node);
void SBT_DestroyTree(SBTNode* node);

void SBT_PreorderPrintTree(SBTNode* node);
void SBT_InorderPrintTree(SBTNode* node);
void SBT_PostorderPrintTree(SBTNode* node);

#endif //THIS_IS_DS_ALGORITHM_BINARYTREE_H
