#include "array.h"
#include <algorithm>


template <typename datatype>
array<datatype>::array()
{
    this -> numberofarrays = 0;
    this -> arrsize = 0;
    this -> arr2d = NULL;
}

template <typename datatype>
datatype* array<datatype>:: getarr(int row)
{
    return arr2d[row];
}

template <typename datatype>
array<datatype>::array(int numofarr, int size)
{
    this -> numberofarrays = numofarr;
    this -> arrsize = size;
    this -> arr2d = new datatype *[numberofarrays];
    for (int i = 0; i < this->numberofarrays; i++) arr2d[i] = new datatype[arrsize];
};


template <typename datatype>
void array<datatype>::showarray()
{
    for (int i = 0; i < numberofarrays; i++) {
        for (int j = 0; j < arrsize; j++) {
            std::cout << arr2d[i][j] << " ";
        };
        std:: cout << '\n';
    };
}

template <typename datatype>
int array<datatype>:: getnumofarr()
{
    return this->numberofarrays;
}

template <typename datatype>
int array<datatype>:: getarrsize()
{
    return this->arrsize;
}

template <typename datatype>
datatype& array<datatype>::get(int tabnum, int column)
{
    if (tabnum < 0 || column < 0 || tabnum >= this->numberofarrays || column >= this ->arrsize)
        throw "Index error!\n";
    else return this -> arr2d[tabnum][column];
}


template <typename datatype>
void array<datatype>::put(const datatype &element, int index1, int index2)
{
    this -> arr2d[index1][index2] = element;
}


template <typename datatype>
array<datatype>::~array()
{
    for (int i = 0; i < this-> numberofarrays; i++) delete [] arr2d[i];
    delete[] arr2d;
};

//________________________ARRAY FILLERS__________________________
template <typename datatype>
void array<datatype>::invfill(){
    for (int i = 0; i < numberofarrays; i++) {
        for (int j = 0; j < this-> arrsize; j++) {
            int temporary = this-> arrsize - j;
            this -> arr2d[i][j] = temporary;
        }
    }
};


template <typename datatype>
void array<datatype>::filledrandom()
{
    for (int i = 0; i < this->numberofarrays; i++) {
        for (int j = 0; j < this->arrsize; j++) {
            this->arr2d[i][j] = rand();
        }
    }
}

template <typename datatype>
void array<datatype>:: filled25()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][arrsize/4], &arr2d[i][arrsize],g);
    }
};

template <typename datatype>
void array<datatype>:: filled50()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][arrsize/2], &arr2d[i][arrsize],g);
    }
};


template <typename datatype>
void array<datatype>:: filled75()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][3*arrsize/4], &arr2d[i][arrsize],g);
    }
};

template <typename datatype>
void array<datatype>:: filled95()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][95*arrsize/100], &arr2d[i][arrsize],g);
    }
};

template <typename datatype>
void array<datatype>:: filled99()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][99*arrsize/100], &arr2d[i][arrsize],g);
    }
};

template <typename datatype>
void array<datatype>:: filled997()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i<this->numberofarrays; i++)
    {
        for (int j = 0;  j < this->arrsize; j++)
        {
            arr2d[i][j] = j;
        }
        std::shuffle(&arr2d[i][997*arrsize/1000], &arr2d[i][arrsize],g);
    }
};

template <typename datatype>
bool array<datatype>::ifsorted()
{
    for (int i = 0; i < this->numberofarrays; i++)
    {
        for (int j = 0; j < this -> arrsize - 1; j++)
        {
            if (this->arr2d[i][j+1] < this -> arr2d[i][j]) return false;
        }
    }
    return true;
}

