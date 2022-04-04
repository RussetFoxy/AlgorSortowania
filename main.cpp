#include "array.h"
#include "sortalgorythms.h"
#include "helpful.h"
#include <fstream>

int main()
{
    std::ofstream txtfile("c:\\Sortowanie\\Introsort.txt");
    if(!txtfile) std:: cout << "Dupablada\n";
    array<int> sortedarray(100,10000), sortedarray2(100,50000), sortedarray3(100,100000), sortedarray4(100,500000), sortedarray5(100,1000000);
    array<int> sortedarray7(1,50);
    sortedarray3.filledrandom();
    quicksort(sortedarray3.getarr(0),0,sortedarray3.getarrsize());
    //sortedarray7.showarray();

    txtfile.close();
    return 1;
}

