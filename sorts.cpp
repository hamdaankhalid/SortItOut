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
 * O(1) SC
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

/**
 * left to right swapping the maximum value as we iterate and then placing it towards the end.
 * then go again left to right picking the maximum value as we iterate placing it one before the end.
 * keep doing this for all numbers.
 * 
 * In the worst case scenario we need to iterate over the loop for each element and then inside the element
 * giving us a time complexity of O(n^2) TC
 * In best case all the elements are sorted in ascending order we will do one iteration and have no swaps,
 * and short circuit giving us an O(n) TC
 * O(1) SC
 * */
void bubbleSort(int arr[], int size) {
  int sortedTill = size;
  
  while(sortedTill > -1) {
    bool swapped = false;
    for(int i = 1; i < sortedTill; i++) {
      // the one on the left is heavier than the one on the right then swap
      if(arr[i-1] > arr[i]) {
        swapped = true;
        swap(arr, i , i - 1);
      }

      // if no swaps were made short circuit!
      if(!swapped) {
        return;
      }
    }
    sortedTill--;
  }
}
