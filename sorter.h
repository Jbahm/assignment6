#include <iostream>

using namespace std;


class sorter{
  public:
    sorter();
    sorter(string fileName);

    double *unSorted;
    int arraySize;

    bool isSorted(double a[]);
    int calculateShiftPos(double a[], double value);

    //Sorting methods
    void bubbleSort(double a[]);
    void selectionSort(double a[]);
    void insertionSort(double a[]);
    void printArray(double a[]);
    void debugSorter();

};
