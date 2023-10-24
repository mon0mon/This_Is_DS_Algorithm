//
// Created by ARA on 2023-10-24.
//

#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType new_data)
{
    SBTNode* new_node = (SBTNode*)malloc(sizeof(SBTNode));
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void SBT_DestroyNode(SBTNode* node)
{
    free(node);
}

void SBT_DestroyTree(SBTNode* node)
{
    if (node == NULL) {
        return;
    }

    SBT_DestroyTree(node->left);
    SBT_DestroyTree(node->right);

    SBT_DestroyNode(node);
}

void SBT_PreorderPrintTree(SBTNode* node)
{
    if (node == NULL) {
        return;
    }

    printf("  %c", node->data);
    SBT_PreorderPrintTree(node->left);
    SBT_PreorderPrintTree(node->right);
}

void SBT_InorderPrintTree(SBTNode* node)
{
    if (node == NULL) {
        return;
    }

    SBT_InorderPrintTree(node->left);
    printf("  %c", node->data);
    SBT_InorderPrintTree(node->right);
}

void SBT_PostorderPrintTree(SBTNode* node)
{
    if (node == NULL) {
        return;
    }

    SBT_PostorderPrintTree(node->left);
    SBT_PostorderPrintTree(node->right);
    printf("  %c", node->data);
}
