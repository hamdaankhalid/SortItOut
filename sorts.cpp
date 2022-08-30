void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

/**
 *  12, 45, 34, 2, 4, 23
 * pick one card a t atime left to right and compare it to the subarray on it's left side
 * keep on iterating left to right swapping till we find it's correct position
 * left side is kept sorted and everytime we are just picking one number from the unsorted/right part and iterating left to find it's position
 * this algorithm is O(n) when the array is sorted already and we just need to add it so it takes only one iteration!
 * Worst case is O(n^2) trivially
 **/
void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] >= arr[i-1]) {
      continue;
    }

    while(i >= 0 && arr[i] < arr[i-1]) {
      swap(arr, i, i - 1);
      i--;
    }
  }
}

