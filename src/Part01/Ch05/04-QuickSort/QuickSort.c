//
// Created by ARA on 2023-10-31.
//

#include <stdio.h>

void Swap(int *a, int *b);
int Partition(int data_set[], int left, int right);
void QuickSort(int data_set[], int left, int right);

int main() {
  int data_set[] = {6, 4, 2, 3, 1, 5, 7};
  int length = sizeof data_set / sizeof data_set[0];

  QuickSort(data_set, 0, length - 1);

  for (int i = 0; i < length; ++i) {
    printf("%d  ", data_set[i]);
  }

  printf("\n");

  return 0;
}

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int data_set[], int left, int right) {
  int first = left;
  int pivot = data_set[first];

  ++left;

  while (left <= right) {
    while (data_set[left] <= pivot && left < right) {
      ++left;
    }

    while (pivot <= data_set[right] && left <= right) {
      --right;
    }

    if (left < right) {
      Swap(&data_set[left], &data_set[right]);
    } else {
      break;
    }
  }

  Swap(&data_set[first], &data_set[right]);

  return right;
}

void QuickSort(int data_set[], int left, int right) {
  if (left < right) {
    int index = Partition(data_set, left, right);

    QuickSort(data_set, left, index - 1);
    QuickSort(data_set, index + 1, right);
  }
}