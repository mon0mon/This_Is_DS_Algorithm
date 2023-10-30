//
// Created by ARA on 2023-10-30.
//

#include <stdio.h>
#include <string.h>

void InsertionSort(int data_set[], int length);

int main() {
  int data_set[] = {6, 4, 2, 3, 1, 5};
  int length = sizeof data_set / sizeof data_set[0];

  InsertionSort(data_set, length);

  for (int i = 0; i < length; ++i) {
    printf("%d  ", data_set[i]);
  }

  printf("\n");

  return 0;
}

void InsertionSort(int data_set[], int length) {
  int value = 0;

  for (int i = 1; i < length; ++i) {
    if (data_set[i - 1] <= data_set[i]) {
      continue;
    }

    value = data_set[i];

    for (int j = 0; j < i; ++j) {
      if (data_set[j] > value) {
        memmove(&data_set[j+1], &data_set[j], sizeof(data_set[0]) * (i-j));
        data_set[j] = value;
        break;
      }
    }
  }
}