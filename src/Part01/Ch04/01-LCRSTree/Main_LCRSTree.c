//
// Created by ARA on 2023-10-20.
//

#include "LCRSTree.h"

int main() {
    LCRSNode* root = LCRS_CreateNode('A');
    LCRSNode* b = LCRS_CreateNode('B');
    LCRSNode* c = LCRS_CreateNode('C');
    LCRSNode* d = LCRS_CreateNode('D');
    LCRSNode* e = LCRS_CreateNode('E');
    LCRSNode* f = LCRS_CreateNode('F');
    LCRSNode* g = LCRS_CreateNode('G');
    LCRSNode* h = LCRS_CreateNode('H');
    LCRSNode* i = LCRS_CreateNode('I');
    LCRSNode* j = LCRS_CreateNode('J');
    LCRSNode* k = LCRS_CreateNode('K');

    LCRS_AddChildNode(root, b);
        LCRS_AddChildNode(b, c);
        LCRS_AddChildNode(b, d);
            LCRS_AddChildNode(d, e);
            LCRS_AddChildNode(d, f);

    LCRS_AddChildNode(root, g);
        LCRS_AddChildNode(g, h);

    LCRS_AddChildNode(root, i);
        LCRS_AddChildNode(i, j);
            LCRS_AddChildNode(j, k);

    LCRS_PrintTree(root, 0);

    printf("\n\n");
    LCRS_PrintNodesAtLevel(root, 0, 3);

    LCRS_DestroyTree(root);

    return 0;
}