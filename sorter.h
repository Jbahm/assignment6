#include <iostream>

using namespace std;


class sorter{
  public:
    sorter();
    sorter(string fileName);

    double *unSorted;
    int arraySize;

    bool isSorted(double a[]);
    bool subsetSorted(double a[], int start, int end);
    int calculateShiftPos(double a[], double value);
    double partition(double a[], int startIndex, int endIndex);

    //Sorting methods
    void quickSort(double a[]);
    void bubbleSort(double a[]);
    void selectionSort(double a[]);
    void insertionSort(double a[]);
    void printArray(double a[]);
    void debugSorter();

};
