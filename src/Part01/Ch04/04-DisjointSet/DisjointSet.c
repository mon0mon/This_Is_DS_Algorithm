//
// Created by ARA on 2023-10-25.
//

#include "DisjointSet.h"

void DS_UnionSet(DisjointSet* set1, DisjointSet* set2)
{
    set2 = DS_FindSet(set2);
    set2->parent = set1;
}

DisjointSet* DS_FindSet(DisjointSet* set)
{
    while (set->parent != NULL) {
        set = set->parent;
    }

    return set;
}

DisjointSet* DS_MakeSet(void* new_data)
{
    DisjointSet* new_node = (DisjointSet*)malloc(sizeof(DisjointSet));
    new_node->data = new_data;
    new_node->parent = NULL;

    return new_node;
}

void DS_DestroySet(DisjointSet* set)
{
    free(set);
}

bool DS_CompareParentSet(DisjointSet* set1, DisjointSet* set2)
{
    set1 = DS_FindSet(set1);
    set2 = DS_FindSet(set2);

    if (set1 == set2) {
        return true;
    }

    return false;
}
