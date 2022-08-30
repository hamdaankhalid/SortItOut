#include <iostream>
#include <cstdlib>
#include "sorts.h"

using namespace std;

void displayArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n" ;
}

int main() {
  int n;
  
  while (n != -1) {
    cout << "Enter the size of array to be sorted" << endl;
    cin >> n;

    int randomArr[n];

    for(int i = 0; i < n; i++) {
      randomArr[i] = 1+ (rand() % 100); 
    }

    cout << "Unsorted Array" << endl;

    displayArr(randomArr, n);

    // insertionSort(randomArr, n);
    bubbleSort(randomArr, n);

    cout << "Sorted Array" << endl;

    displayArr(randomArr, n);

    char continueSort;
    cout << "Enter q to quit or c to continue" << endl;
    cin >> continueSort;

    if (continueSort == 'q') {
      break;
    }
  }
}
