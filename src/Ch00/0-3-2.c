//
// Created by ARA on 2023-09-20.
//
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

typedef struct tagPoint
{
    int x;
    int y;
} Point;

int main()
{
    struct Point MyPoint = { 30, 40 };
    printf("x : %d, y : %d\n", MyPoint.x, MyPoint.y);

    struct Point* ptr = &MyPoint;
    printf("x : %d, y : %d\n", ptr->x, ptr->y);

    Point MyPoint2 = { 30, 40 };
    Point* ptr2 = &MyPoint2;
}
