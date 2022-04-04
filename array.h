#ifndef ALGORYTMSORTOWANIA_ARRAY_H
#define ALGORYTMSORTOWANIA_ARRAY_H

#include <iostream>
#include <random>


template <typename datatype>
class array
{
    int numberofarrays;
    int arrsize;
    datatype **arr2d;
public:
    array();
    array(int numofarr, int size);
    ~array();
    datatype& get(int tabnum, int column);
    void put (const datatype &element, int index1, int index2);
    datatype *getarr(int row);
    int getnumofarr();
    int getarrsize();
    void showarray();
    void filledrandom();
    void filled25();
    void filled50();
    void filled75();
    void filled95();
    void filled99();
    void filled997();
    void invfill();
    bool ifsorted();
};
template class array<int>;
template class array<double>;
template class array<float>;
#endif
