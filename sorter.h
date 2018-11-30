#include <iostream>

using namespace std;


class sorter{
  public:
    sorter();
    sorter(string fileName);

    double **unSorted;
    int arraySize = 5;

    //Sorting methods
    bool isSorted(double a[]);
    void bubbleSort(double a[]);
    void printArray(double a[]);
    void debugSorter();

};
