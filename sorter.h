#include <iostream>

using namespace std;


class sorter{
  public:
    sorter();
    sorter(string fileName);

    double **unSorted;
    int arraySize = 5;

    bool isSorted(double a[]);
    bool finishedInsertion(bool a[]);

    //Sorting methods
    void bubbleSort(double a[]);
    void insertionSort(double a[]);
    void printArray(double a[]);
    void debugSorter();

};
