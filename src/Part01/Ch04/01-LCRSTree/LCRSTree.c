//
// Created by ARA on 2023-10-20.
//

#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType new_data)
{
    LCRSNode* new_node = (LCRSNode*)malloc(sizeof(LCRSNode));
    new_node->left_child = NULL;
    new_node->right_sibling = NULL;

    new_node->data = new_data;

    return new_node;
}

void LCRS_DestroyNode(LCRSNode* node)
{
    free(node);
}

void LCRS_DestroyTree(LCRSNode* root)
{
    if (root->right_sibling != NULL)
    {
        LCRS_DestroyTree(root->right_sibling);
    }

    if (root->left_child != NULL)
    {
        LCRS_DestroyTree(root->left_child);
    }

    root->right_sibling = NULL;
    root->left_child = NULL;

    LCRS_DestroyNode(root);
}

void LCRS_AddChildNode(LCRSNode* parent_node, LCRSNode* child_node)
{
    if (parent_node->left_child == NULL)
    {
        parent_node->left_child = child_node;
    }
    else
    {
        LCRSNode* temp_node = parent_node->left_child;
        while (temp_node->right_sibling != NULL)
        {
            temp_node = temp_node->right_sibling;
        }

        temp_node->right_sibling = child_node;
    }
}

void LCRS_PrintTree(LCRSNode* node, int depth)
{
    for (int i = 0; i < depth - 1; ++i)
    {
        printf("   ");
    }

    if (depth > 0)
    {
        printf("+--");
    }

    printf("%c\n", node->data);

    if (node->left_child != NULL)
    {
        LCRS_PrintTree(node->left_child, depth + 1);
    }

    if (node->right_sibling != NULL)
    {
        LCRS_PrintTree(node->right_sibling, depth);
    }
}

void LCRS_PrintNodesAtLevel(LCRSNode* node, int current, int level)
{
    if (current < level)
    {
        if (node->left_child != NULL)
        {
            LCRS_PrintNodesAtLevel(node->left_child, current + 1, level);
        }

        if (node->right_sibling != NULL)
        {
            LCRS_PrintNodesAtLevel(node->right_sibling, current, level);
        }
        return;
    }

    printf("%c\n", node->data);
    if (node->right_sibling != NULL)
    {
        LCRS_PrintNodesAtLevel(node->right_sibling, current, level);
    }
}
