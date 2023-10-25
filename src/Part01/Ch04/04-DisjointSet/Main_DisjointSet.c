//
// Created by ARA on 2023-10-25.
//

#include "DisjointSet.h"

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    DisjointSet* set1 = DS_MakeSet(&a);
    DisjointSet* set2 = DS_MakeSet(&b);
    DisjointSet* set3 = DS_MakeSet(&c);
    DisjointSet* set4 = DS_MakeSet(&d);

    printf("Set1 == Set2 : %s\n", DS_CompareParentSet(set1, set2) ? "True" : "False");

    DS_UnionSet(set1, set3);

    printf("Set1 == Set3 : %s\n", DS_CompareParentSet(set1, set3) ? "True" : "False");

    DS_UnionSet(set3, set4);
    printf("Set3 == Set4 : %s\n", DS_CompareParentSet(set3, set4) ? "True" : "False");

    return 0;
}