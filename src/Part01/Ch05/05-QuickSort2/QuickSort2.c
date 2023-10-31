//
// Created by ARA on 2023-11-01.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ComparePoint(const void *_elem1, const void *_elem2);

int main() {
  int data_set[] = {6, 4, 2, 3, 1, 5};
  int length = sizeof data_set / sizeof data_set[0];

  qsort((void*) data_set, length, sizeof (int), ComparePoint);

  for (int i = 0; i < length; ++i) {
    printf("%d  ", data_set[i]);
  }

  printf("\n");

  return 0;
}

int ComparePoint(const void *_elem1, const void *_elem2) {
  int* elem1 = (int*) _elem1;
  int* elem2 = (int*) _elem2;

  if (*elem1 > *elem2) {
    return 1;
  } else if (*elem1 < *elem2) {
    return -1;
  } else {
    return 0;
  }
}