//
// Created by megha on 2019. 05. 15..
//

#include "Points.h"

point_t create_point(int x, int y)
{
    point_t point;
    point.x = x;
    point.y = y;
    return point;
}

float dist(point_t point1, point_t point2)
{
    float dist = sqrt((abs(point1.x - point2.x) * abs(point1.x-point2.x)) + (abs(point1.y - point2.y) * abs(point1.y - point2.y)));
    return dist;
}
