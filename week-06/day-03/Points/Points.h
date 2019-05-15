//
// Created by megha on 2019. 05. 15..
//

#ifndef POINTS_POINTS_H
#define POINTS_POINTS_H

#include "math.h"

typedef struct{
    int x;
    int y;
} point_t;

point_t create_point(int, int);

float dist(point_t, point_t);


#endif //POINTS_POINTS_H
