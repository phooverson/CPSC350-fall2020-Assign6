#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

class ManageSort {
public:
  ManageSort(); //default constructor
  ~ManageSort(); //default destructor

  //general methods
  void ReadFile(string usersFile);
  void runSort();
private:
  //arrays of doubles to store the data
  double *arrayForQuickSort;
  double *arrayForMergeSort;
  double *arrayForSelectionSort;
  double *arrayForInsertionSort;
  double *arrayForBubbleSort;

  //Sorting methods
  void QuickSort();
  void MergeSort();
  void SelectionSort();
  void InsertionSort();
  void BubbleSort();

  //general helper methods
  int Partition(int lowIndex, int highIndex);
  void Merge(int i, int j, int k);
  void recMergeSort(int i, int k);
  void recSelectionSort(int size);
  void recInsertionSort(int numbersSize);
  void recBubbleSort(int size);
  void recQuickSort(int lowIndex, int highIndex);
  int partition (int low, int high);
  void printStats();
  void deleteArrays();
};
