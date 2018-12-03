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

int sorter::calculateShiftPos(double a[], double value){
  for(int i = 0; i < arraySize; i++){
    if((value > a[i]) && (value < a[i+1])){
      return i;
    }
  }
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


void sorter::insertionSort(double a[]){
  double dummyNum = -100000;
  double sortedArray [arraySize];
  for(int j = 0; j < arraySize; j++){
    sortedArray[j] = dummyNum;
  }
  double inserted;
  double highestValue;
  int insertionPoint;
  int shiftPos;

  for(int i = 0; i < arraySize; i++){
    inserted = a[i];
    if(i == 0){
      sortedArray[0] = inserted;
    }else if(inserted < sortedArray[0]){
      shiftPos = -1;
      for(int k = arraySize-1; k > shiftPos; k--){
          if(sortedArray[k] != -100000){
            sortedArray[k+1] = sortedArray[k];
            sortedArray[k] = inserted;
          }
        }
    }else if(inserted > sortedArray[i-1]){
      sortedArray[i] = inserted;
    }else{
      shiftPos = calculateShiftPos(sortedArray, a[i]);
      for(int l = arraySize-1; l > shiftPos; l--){
          if(sortedArray[l] != -100000){
            sortedArray[l+1] = sortedArray[l];
            sortedArray[l] = inserted;
          }
        }
    }
  }


  /*leftShift code(Makes a space at a[shiftPos+1])
  int shiftPos = 2;
  int numbersShifted = 0;
  double sortedArray [arraySize] = {-100000, 2, -100000, 3, -100000};
  for(int k = 5-1; k > shiftPos; k--){
    if(sortedArray[k] != -100000){
      sortedArray[k+1] = sortedArray[k];
      sortedArray[k] = 4;
    }
  }
  */
  printArray(sortedArray);
}









void sorter::printArray(double a[]){
  for(int i = 0; i < arraySize; i++){
    cout << "[" << a[i] << "]";
  }
  cout << endl;
}



void sorter::debugSorter(){
  double test [5] = {5, -4, 12, 1, 2};
  insertionSort(test);

}
