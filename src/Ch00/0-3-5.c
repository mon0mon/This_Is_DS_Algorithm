//
// Created by ARA on 2023-09-20.
//
#include <stdio.h>
#include <malloc.h>

typedef struct tagPoint
{
    int x;
    int y;
} Point;

int main()
{
    Point* ptr = (Point*)malloc(sizeof(Point));
    free(ptr);
}