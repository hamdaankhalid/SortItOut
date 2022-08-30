#include <iostream>
#include <cstdlib>
#include "sorts.h"

using namespace std;

void displayArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int n;

  cout << "Enter the size of array to be sorted" << endl;
  cin >> n;
  
  while (n != -1) {
    int randomArr[n];

    for(int i = 0; i < n; i++) {
      randomArr[i] = 1+ (rand() % 100); 
    }

    insertionSort(randomArr, n);

    displayArr(randomArr, n);
    cout << "\n" ;

    cout << "Enter the size of array to be sorted" << endl;
    cin >> n;
  }
}
