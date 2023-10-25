//
// Created by ARA on 2023-10-25.
//

#ifndef THIS_IS_DS_ALGORITHM_DISJOINTSET_H
#define THIS_IS_DS_ALGORITHM_DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagDisjointSet
{
    struct tagDisjointSet* parent;
    void* data;
} DisjointSet;

void DS_UnionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* DS_FindSet(DisjointSet* set);
DisjointSet* DS_MakeSet(void* new_data);
void DS_DestroySet(DisjointSet* set);
bool DS_CompareParentSet(DisjointSet* set1, DisjointSet* set2);

#endif //THIS_IS_DS_ALGORITHM_DISJOINTSET_H
