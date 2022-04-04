#ifndef SORTOWANIEV2_SORTALGORYTHMS_H
#define SORTOWANIEV2_SORTALGORYTHMS_H

#include <iostream>
#include "helpful.h"
#include "array.h"


template <typename datatype>
void swaparray (datatype array[], int i, int j)
{
    datatype temp;
    temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}

//__________________________________________--MERGE SORT--___________________________________________________________
template <typename datatype>
void merge(datatype array[], int left, int mid, int right)
{

    int const subarr1 = mid - left + 1;
    int const subarr2 = right - mid;

    //Utworzenie tymczasowych tablic
    auto *leftarr = new datatype[subarr1], *rightarr = new datatype[subarr2];
    //Kopiowanie wartości do tymczasowych tablic
    for (int i = 0; i < subarr1; i++) leftarr[i] = array[left + i];
    for (int j = 0; j < subarr2; j++) rightarr[j] = array[mid + 1 + j];
    int indsubarr1 = 0, // Początek pierwszej podtablicy
    indsubarr2 = 0; // Poczatek drugiej podtablicy
    int indofmerarr = left; // Poczatek scalanej tablicy

    // Scalanie tymczasowych tablic do jednej tablicy
    while (indsubarr1 < subarr1 && indsubarr2 < subarr2)
        {
            if (leftarr[indsubarr1] <= rightarr[indsubarr2])
            {
                array[indofmerarr] = leftarr[indsubarr1++];
            }
            else
            {
                array[indofmerarr] = rightarr[indsubarr2]; indsubarr2++;
            }
            indofmerarr++;
        }
   //Kopiowanie pozostalych elementow lewej tablicy jesli sa jakies
    while (indsubarr1 < subarr1)
    {
        array[indofmerarr] = leftarr[indsubarr1]; indsubarr1++; indofmerarr++;
    }
    //Kopiowanie pozostalych elementow prawej tablicy jesli istnieja
    while (indsubarr2 < subarr2)
    {
        array[indofmerarr] = rightarr[indsubarr2]; indsubarr2++; indofmerarr++;
    }
    //zwolnienie pamieci
    delete [] leftarr;
    delete [] rightarr;
}


template <typename datatype>
void mergesort(datatype array[], int left, int right)
{
    if (right <= left) return; //rekursywny powrót
    int mid = (right+left)/2;

    mergesort(array,left, mid);
    mergesort(array, mid+1, right);

    merge(array,left, mid, right);
}


//________________________-HEAP SORT-________________________________
void heapify(int arr[], int n, int i)
{
    int largest = i; //inicjalizacja indeksu najnizszego rodzica
    int l = 2 * i + 1; //indeks potomka 1 najnizszego rodzica
    int r = 2 * i + 2; //indeks potomek 2 najnizszego rodzica

    // Jesli dziecko 1 jest wieksze od rodzica zamiana indeksow
    if (l < n && arr[l] > arr[largest]) largest = l;

    // Jesli dziecko 2 jest wieksze od rodzica zamiana indeksow
    if (r < n && arr[r] > arr[largest]) largest = r;

    // Jesli najnizszy nie jest rodzicem nastepuje zamiana
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest); //rekursywnie tworzy kopiec
    }
}


void heapsort(int arr[], int n)
{
    //Tworzenie kopca
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    // Wyciaganie kolejnych elementow z kopca
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


//_______________________Insert Sort___________________________________________________________
template <typename datatype>
void insertsort(datatype array[], int n)
{
    int i, j;
    datatype element;
    for (i = 1; i < n; i++)//pętla badająca elementy od drugiego, do ostatniego w tablicy
    {
        element = array[i];//zapisanie wartości wstawianego elementu
        j = i - 1;//indeks elementu o 1 wcześniej od badanego
        while (j>= 0 && array[j] > element){ //petla realizująca porównanie poprzednich elementów do momentu napotkania mniejszego elementu
            //lub konca tablicy
            array[j+1]=array[j];//przesuniecie emelemntu
            j = j-1;//cofniecie indeksu o 1 element w lewo
        }
       array[j+1] = element;//wstawienie elementu badanego w wolne miejsce
    }
}


//_______________________Quick Sort______________________________________

template <typename datatype>
int partition(datatype array[], int left, int right)
{
    datatype pivot = array[right];//pivot po skrajnie prawej stronie
    int i = left - 1; //indeks mniejszego elementu znalezionego do tej pory
    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] < pivot) {i++; swaparray(array, i,j);};
    }
        swaparray(array, i+1, right);
        return (i + 1);
}

template <typename datatype>
void quicksort(datatype array[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot-1 );//stworzenie prawej tablicy wzgledem piwota i rekurencyjne wywolanie
        quicksort(array, pivot+1, right);//stworzenie lewej tablicy wzgledem piwota i rekurencyjne wywolanie
    }
}



//_____________________Intro Sort_______________________________________
template <typename datatype>
void medianofthree (datatype array[], long &left, long &right)
{
    if (array[++left - 1]>array[--right]) swaparray(array,left - 1,right);
    if (array[left - 1]>array[right/2]) swaparray(array,left - 1,right/2);
    if (array[right/2]>array[right]) swaparray(array,right/2,right);
    swaparray(array,right/2,right-1);
}


template <typename datatype>
long Partition (datatype array[], long left, long right)
{
    long i, j;
    if (right>=3)
        medianofthree(array,left,right);
    for (i=left, j=right-2; ; )
    {
        for ( ; array[i]<array[left-1]; ++i);
        for ( ; j>= left && array[j]>array[right-1]; --j);
        if (i<j)
            swaparray(array,i++,j--);
        else break;
    }
    swaparrau(array,i,right - 1);
    return i;
}

template <typename datatype>
void introsort (datatype array, int N, int M)
{
    long i;
    if (M<=0)
    {
        heapsort(array,N);
        return;
    }
    i = Partition(array,0,N);
    if (i>9)
        introsort(array,i,M - 1);
    if (N-1-i>9)
        introsort(array + i + 1, N - 1 - i , M - 1);
}

template <typename datatype>
void introspectivesort (datatype array[], int N)
{
    introsort(array,N,(int)floor(2*log(N)/M_LN2));
    insertsort(array,N);
}
#endif //SORTOWANIEV2_SORTALGORYTHMS_H
