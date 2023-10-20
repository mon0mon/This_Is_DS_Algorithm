//
// Created by ARA on 2023-10-20.
//

#ifndef THIS_IS_DS_ALGORITHM_LCRSTREE_H
#define THIS_IS_DS_ALGORITHM_LCRSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode* left_child;
    struct tagLCRSNode* right_sibling;

    ElementType data;
} LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType new_data);

void LCRS_DestroyNode(LCRSNode* node);

void LCRS_DestroyTree(LCRSNode* root);

void LCRS_AddChildNode(LCRSNode* parent_node, LCRSNode* child_node);

void LCRS_PrintTree(LCRSNode* node, int depth);

void LCRS_PrintNodesAtLevel(LCRSNode* node, int current, int level);

#endif //THIS_IS_DS_ALGORITHM_LCRSTREE_H
