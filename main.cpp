#include <iostream>
#include <cstdlib>
#include "sorts.h"
#include <vector>


void displayVec(std::vector<int> &arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n" ;
}


void displayArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n" ;
}

int main() {
  int n;
  
  while (n != -1) {
    std::cout << "Enter the size of array to be sorted" << std::endl;
    std::cin >> n;

    int randomArr[n];

    for(int i = 0; i < n; i++) {
      randomArr[i] = 1+ (rand() % 100); 
    }

    std::cout << "Unsorted Array" << std::endl;

    displayArr(randomArr, n);

    // insertionSort(randomArr, n);
    // bubbleSort(randomArr, n);
    // mergeSort(randomArr, 0, n-1);
    
    // QUICKSORT
    // std::vector<int> arrToVec(randomArr, randomArr+n);
    // std::vector<int> quickSortedOutput = quickSort(arrToVec);

    // std::cout << "Sorted Array" << std::endl;

    // displayVec(quickSortedOutput, n);

    // countSort(randomArr, n);
    
    radixSort(randomArr, n);
    displayArr(randomArr, n);

    char continueSort;
    std::cout << "Enter q to quit or c to continue" << std::endl;
    std::cin >> continueSort;

    if (continueSort == 'q') {
      break;
    }
  }
}
