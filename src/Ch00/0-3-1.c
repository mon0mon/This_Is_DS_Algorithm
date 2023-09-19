//
// Created by ARA on 2023-09-20.
//
#include <stdio.h>

int main() {
    int* ptr = (int *) 0xFF000000;

    int a = 123;
    ptr = &a;

    ptr = (int *) 0x1004;
    printf("%X\n", ptr);
    printf("%X\n", --ptr);
    printf("%X\n", ++ptr);

    int arr[5] = {0, 1, 2, 3, 4};
    ptr = arr;

    printf("%s\n", ptr == arr ? "true" : "false");

    printf("%d\n", *ptr);

    ptr++;
    printf("%d\n", *ptr);

    ptr--;
    printf("%d\n", *ptr);
}
