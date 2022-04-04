//
// Created by Kacper on 25.03.2022.
//
#include "helpful.h"


double timetaken(clock_t time1, clock_t time2)
{
    return ((time2-time1)/(CLOCKS_PER_SEC / (double) 1000.0));
}
