#include <iostream>

using namespace std;


class sorter{
  public:
    sorter();
    sorter(string fileName);

    double *unSorted;
    int arraySize;

    bool isSorted(double a[]); //Checks if the array is sorted
    bool subsetSorted(double a[], int start, int end);//Used for quicksort
    int calculateShiftPos(double a[], double value);//Used for insertionSort
    double partition(double a[], int startIndex, int endIndex);//used for partitioning in quicksort;

    //Sorting methods
    void quickSort(double a[]);//Quicksort method
    void bubbleSort(double a[]);//BubbleSort method
    void selectionSort(double a[]); //SelectionSort method
    void insertionSort(double a[]); //InsertionSort method
    void printArray(double a[]); //Prints out the given array
    void timeSorts(); //Main method that runs all sorts and times them

};
