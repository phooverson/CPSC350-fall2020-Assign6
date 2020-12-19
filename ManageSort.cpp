#include "Assign6.h"
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

ManageSort::ManageSort(){
  cout << fixed << setprecision(7);
  //constructor for Sort
}

ManageSort::~ManageSort(){
  deleteArrays(); //manual garbage collecting
}

void ManageSort::runSort(){
  QuickSort();
  MergeSort();
  SelectionSort();
  InsertionSort();
  BubbleSort();
}

void ManageSort::ReadFile(string usersFile){
  fstream inputFile;
  string line;
  bool isLineOne = true;
  int sizeOfArray;
  int currArrayIndex = 0;
  double currentData;

  inputFile.open(usersFile);
  if (inputFile.is_open()){
    while(getline(inputFile, line)){
      if (isLineOne){ //line 1 has the size of the data input, needed for creating arrays
        sizeOfArray = stoi(line);
        arrayForQuickSort = new double[sizeOfArray];
        arrayForMergeSort = new double[sizeOfArray];
        arrayForSelectionSort = new double[sizeOfArray];
        arrayForInsertionSort = new double[sizeOfArray];
        arrayForBubbleSort = new double[sizeOfArray];
        isLineOne = false;
      }
      else{ //add the data to the arrays
        currentData = stod(line);
        arrayForQuickSort[currArrayIndex] = currentData;
        arrayForMergeSort[currArrayIndex] = currentData;
        arrayForSelectionSort[currArrayIndex] = currentData;
        arrayForInsertionSort[currArrayIndex] = currentData;
        arrayForBubbleSort[currArrayIndex] = currentData;
        currArrayIndex++;
      }
    }
  }
  else {
    cout << "File " << usersFile << " could not be found. Please reload program with correct file name." << endl;
  }
}

void ManageSort::QuickSort(){
  clock_t time;

  time = clock(); //start time
  int highIndex = sizeof(arrayForQuickSort);
  recQuickSort(0, highIndex-1); //enter recursion
  time = clock() - time; //end time

  cout << "Quick Sort: " << (double)time/CLOCKS_PER_SEC << endl; //print total time
}

void ManageSort::recQuickSort(int lowIndex, int highIndex){ //use recursion to partition and quick sort each section
  int pivotPoint;
  if (lowIndex < highIndex){
    pivotPoint = partition(lowIndex, highIndex);
    recQuickSort(lowIndex, pivotPoint-1);
    recQuickSort(pivotPoint+1, highIndex);
  }
}

int ManageSort::partition(int low, int high){
  int pivot = arrayForQuickSort[high];
  int newPivot = low;
  double temp;
  for (int j = low; j <= high - 1; j++){
    if (arrayForQuickSort[j] <= pivot){
      temp = arrayForQuickSort[newPivot];
      arrayForQuickSort[newPivot] = arrayForQuickSort[j];
      arrayForQuickSort[j] = temp;
      newPivot++;
    }
  }
  temp = arrayForQuickSort[newPivot];
  arrayForQuickSort[newPivot] = arrayForQuickSort[high];
  arrayForQuickSort[high] = temp;
  return newPivot;
}

void ManageSort::MergeSort(){
  clock_t time;

  time = clock(); //start time
  int size = sizeof(arrayForMergeSort);
  recMergeSort(0, size - 1); //enter recursion
  time = clock() - time; //end time

  cout << "Merge Sort: " << (double)time/CLOCKS_PER_SEC << endl; //print total time
}

void ManageSort::recMergeSort(int i, int k){
  int j = 0;
  if (i < k){
    j = (i + k) / 2; //Find the midpoint in the partition
    recMergeSort(i, j); //Recursively sort left patrition
    recMergeSort(j + 1, k); //Recursively sort right partition
    Merge(i, j, k); //Merge left and right partition in sorted order
  }
}

void ManageSort::Merge(int i, int j, int k){
  int mergedSize = k - i + 1; //Size of merged partition
  int mergePos = 0; //Position of insert merged number
  int leftPos = 0; //position of elements in left partition
  int rightPos = 0; //position of elements in right partition
  double *mergedNumbers = new double[mergedSize]; //dynamically allocates temporary array for merged numbers

  leftPos = i; //Initialize left partition position
  rightPos = j + 1; //Initialize right partition position

  while (leftPos <= j && rightPos <= k){ //Add smallest element from left or right partition to merged numbers
    if (arrayForMergeSort[leftPos] <= arrayForMergeSort[rightPos]){
      mergedNumbers[mergePos] = arrayForMergeSort[leftPos];
      ++leftPos;
    }
    else{
      mergedNumbers[mergePos] = arrayForMergeSort[rightPos];
      ++rightPos;
    }
    ++mergePos;
  }

  while (leftPos <= j){ //If left partition is not empty, add remaining elements to merged numbers
    mergedNumbers[mergePos] = arrayForMergeSort[leftPos];
    ++leftPos;
    ++mergePos;
  }

  while (rightPos <= k){ //If right partition is not empty, add remaining elements to merged numbers
    mergedNumbers[mergePos] = arrayForMergeSort[rightPos];
    ++rightPos;
    ++mergePos;
  }

  // Copy merge number back to numbers
  for(mergePos = 0; mergePos < mergedSize; ++mergePos)
    arrayForMergeSort[i + mergePos] = mergedNumbers[mergePos];
}

void ManageSort::SelectionSort(){
  clock_t time;

  time = clock(); //start time
  int arraySize = sizeof(arrayForSelectionSort);
  recSelectionSort(arraySize); //enter recursion
  time = clock() - time; //end time

  cout << "Selection Sort: " << (double)time/CLOCKS_PER_SEC << endl; //print total time
}

void ManageSort::recSelectionSort(int numbersSize){
  int indexSmallest;
  double temp;
  for (int i = 0; i < numbersSize-1; ++i){
    indexSmallest = i; //find index of smallest remaining element
    for (int j = i + 1; j < numbersSize; ++j){
      if (arrayForSelectionSort[j] < arrayForSelectionSort[indexSmallest])
        indexSmallest = j;
    }
  //swaping
  temp = arrayForSelectionSort[i];
  arrayForSelectionSort[i] = arrayForSelectionSort[indexSmallest];
  arrayForSelectionSort[indexSmallest] = temp;
  }
}

void ManageSort::InsertionSort(){
  clock_t time;

  time = clock(); //start time
  int arraySize = sizeof(arrayForInsertionSort);
  recInsertionSort(arraySize); //enter recursion
  time = clock() - time; //end time

  cout << "Insertion Sort: " << (double)time/CLOCKS_PER_SEC << endl; //print total time
}

void ManageSort::recInsertionSort(int numbersSize){
  int j;
  double temp;
  for (int i = 1; i < numbersSize; ++i){
    j = i;
    while ((j > 0) && (arrayForInsertionSort[j] < arrayForInsertionSort[j-1])){
      //swaping
      temp = arrayForInsertionSort[j];
      arrayForInsertionSort[j] = arrayForInsertionSort[j-1];
      arrayForInsertionSort[j-1] = temp;
      --j;
    }
  }
}

void ManageSort::BubbleSort(){
  clock_t time;

  time = clock(); //start time
  int arraySize = sizeof(arrayForBubbleSort);
  recBubbleSort(arraySize); //enter recursion
  time = clock() - time; //end time

  cout << "Bubble Sort: " << (double)time/CLOCKS_PER_SEC << endl; //print total time
}

void ManageSort::recBubbleSort(int size){
  int temp;
  for (int i = 0; i < size-1; i++){
    for (int j = 0; j < size-i-1; j++){
      if (arrayForBubbleSort[j] > arrayForBubbleSort[j+1]){
        //swaping
        temp = arrayForBubbleSort[j];
        arrayForBubbleSort[j] = arrayForBubbleSort[j+1];
        arrayForBubbleSort[j+1] = temp;
      }
    }
  }
}

void ManageSort::deleteArrays(){
  delete arrayForQuickSort;
  delete arrayForMergeSort;
  delete arrayForSelectionSort;
  delete arrayForInsertionSort;
  delete arrayForBubbleSort;
}
