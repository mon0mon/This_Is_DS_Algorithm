//
// Created by ARA on 2023-11-01.
//

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

#define LENGTH 30000
#define WINNING 14142

int ComparePoint(const void * elem1, const void * elem2);

int main() {
  qsort((void*)DataSet, LENGTH, sizeof(Point), ComparePoint);

  printf("[ID] : %d\n[Point]: %lf\n", DataSet[WINNING].id, DataSet[WINNING].point);

  return 0;
}

int ComparePoint(const void * _elem1, const void * _elem2) {
  Point* elem1 = (Point*) _elem1;
  Point* elem2 = (Point*) _elem2;

  if (elem1->point > elem2->point) {
    return -1;
  } else if (elem1->point < elem2->point) {
    return 1;
  } else {
    return 0;
  }
}