#include <iostream>
#include <fstream>
#include "sorter.h"

using namespace std;

sorter::sorter(){

}

sorter::sorter(string fileName){
  ifstream a;
  string currentLine;


  a.open(fileName);
  a >> currentLine;
  arraySize = stoi(currentLine.c_str());
  unSorted = new double[arraySize];
  for(int i = 0; i < arraySize; i++){
    a >> currentLine;
    unSorted[i] = stod(currentLine);
  }

  double largestNum = -100000;
  int largestNumLoc = 0;
  for(int l = 0; l < arraySize; l++){
    if(unSorted[l] > largestNum){
      largestNum = unSorted[l];
      largestNumLoc = l;
    }
  }
  for (int k = largestNumLoc+1; k < arraySize; k++){
    unSorted[k-1] = unSorted[k];
  }
  unSorted[arraySize-1] = largestNum;
}

bool sorter::isSorted(double a[]){
  for(int i = 0; i < (arraySize-1); i++){
    if(a[i] > a[i+1]){
      return false;
    }
  }
  return true;
}


bool sorter::subsetSorted(double a[], int start, int end){
  for(int i = start; i < (end); i++){
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


void sorter::selectionSort(double a[]){
  double lowestNum;
  double sortedArray [arraySize];
  int lowestNumPos;
  for(int i = 0; i < arraySize; i++){
    lowestNum = 1000000000;
    for(int j = 0; j < arraySize; j++){
      if(a[j] != 1000000000){
        if(a[j] < lowestNum){
          lowestNum = a[j];
          lowestNumPos = j;
        }
      }
    }
    sortedArray[i] = lowestNum;
    a[lowestNumPos] = 1000000000;
  }
  printArray(sortedArray);
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



double sorter::partition(double a[], int startIndex, int endIndex){
  double pivot = a[endIndex-1];
  bool partitioning [(endIndex-startIndex)-1];
  double aCopy[(endIndex-startIndex)-1];
  int rightSub;
  int leftSub;
  int currI = 0;

  for(int i = startIndex; i < endIndex; i++){
    if(a[i] < pivot){
      partitioning[i] = false;
      aCopy[i] = a[i];
    }else{
      partitioning[i] = true;
      aCopy[i] = a[i];
    }
  }

  for(int k = 0; k < ((endIndex-startIndex)); k++){
    if(partitioning[k] == false){
      a[currI] = aCopy[k];
      currI++;
    }
  }
  a[currI] = pivot;
  currI++;


  for(int l = 0; l < ((endIndex-startIndex)); l++){
    if(partitioning[l] == true){
      a[currI] = aCopy[l];
      currI++;
      }
    }

    return pivot;
}



void sorter::quickSort(double a[]){
  int pivotIndex;
  int n = 1;


  double pivot = partition(a, 0, arraySize);
  double permPivotIndex;
  double oldPivot;
  int oldIndex;
  double permPivot;
  double pivotIndexR;
  for(int i = 0; i < arraySize; i++){
    if(a[i] == pivot){
      pivotIndex = i;
      pivotIndexR = i;
      permPivotIndex = i;
      permPivot = a[i];
    }
  }
  while(pivotIndex > 1){
  oldPivot = pivot;
  oldIndex = pivotIndex;
  pivot = partition(a, 0, pivotIndex);
  a[oldIndex] = oldPivot;
  for(int j = 0; j < pivotIndex; j++){
    if(a[j] == pivot){
      pivotIndex = j;
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
  quickSort(unSorted);

}
