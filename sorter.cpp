#include <iostream>
#include "sorter.h"

using namespace std;

sorter::sorter(){

}

sorter::sorter(string fileName){
  //
}

bool sorter::isSorted(double a[]){
  for(int i = 0; i < (arraySize-1); i++){
    if(a[i] > a[i+1]){
      return false;
    }
  }
  return true;
}

void sorter::bubbleSort(double a[]){
  while(isSorted(a) == false){
    for(int i = 0; i < (arraySize-1); i++){
      if(a[i] > a[i+1]){
        double temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
  }
  printArray(a);
}

void sorter::printArray(double a[]){
  for(int i = 0; i < arraySize; i++){
    cout << "[" << a[i] << "]";
  }
  cout << endl;
}



void sorter::debugSorter(){
  double test [5] = {1, 3, 2, 5, 4};
  bubbleSort(test);

}
