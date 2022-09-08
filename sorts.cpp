#include <iostream>
#include <cmath>
#include <vector>

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

// Merge sort utiltity func
void merge(int arr[], int left, int mid, int right) {
  int leftCounter = left;
  int rightCounter = mid+1;

  int tempArrSize = right - left + 1;
  int tempArr[tempArrSize];
  int insertPosition = 0;
  
  while (leftCounter < mid + 1 || rightCounter < right +1) {
    int leftContender = leftCounter == mid + 1? NULL : arr[leftCounter];
    int rightContender = rightCounter == right +1 ? NULL : arr[rightCounter];
    
    if (leftContender != NULL && rightContender != NULL) {
      if (leftContender > rightContender) {
        tempArr[insertPosition] = rightContender;
        rightCounter++;
      } else {
        tempArr[insertPosition] = leftContender;
        leftCounter++;
      }
    } else if (leftContender == NULL && rightContender != NULL) {
        tempArr[insertPosition] = rightContender;
        rightCounter++;
    } else {
        tempArr[insertPosition] = leftContender;
        leftCounter++;
    }

    insertPosition++;
  }

  // copy vals from temp array to the one that was passed in the args
  for (int offset = 0 ; offset < tempArrSize; offset++) {
    arr[left+offset] = tempArr[offset];
  }
}

void mergeSort(int arr[], int left, int right) {
  // more than 1 element exists in subarray
  if (left < right) {
    int mid = (int) std::floor((left+right)/2);

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
  } else {
    // Explicitly defining else for better understanding
    // only one element exists so do a return
    // and let the caller merge
    return;
  }
}


// pick a pivoty randomly or however and put all elements smaller than it to it's left and all greater on right
// call algorithm recursively on left and right
// base case for end of recursion is when there is none or one element left at that point we need to begin merging
// for merging we just take all elements on left and put them on the left and all right and put them on the right
std::vector<int> quickSort(std::vector<int>& arr) {  
  int arrSize = arr.size();

  if (arrSize <= 1) {
    return arr;
  }

  int lastElementInVector = arrSize-1;
  int pivot = arr[lastElementInVector];
  std::vector<int> left;
  std::vector<int> right;
  for (int i = 0; i < lastElementInVector; i++) {
    if (arr[i] <= pivot) {
      left.push_back(arr[i]);
    } else {
      right.push_back(arr[i]);
    }
  }

  std::vector<int> sortedLeft = quickSort(left);
  std::vector<int> sortedRight = quickSort(right);

  // merge left, pivot, right
  std::vector<int> mergedArr;

  int sortedLeftSize = sortedLeft.size();
  int sortedRightSize = sortedRight.size();

  // std::cout << sortedLeftSize << sortedRightSize << std::endl;
  for (int i = 0; i < sortedLeftSize; i++) {
    mergedArr.push_back(sortedLeft[i]);
  }
  mergedArr.push_back(pivot);
  for(int j = 0; j < sortedRightSize; j++) {
    mergedArr.push_back(sortedRight[j]);
  } 
  return mergedArr;
}


int findMax(int arr[], int size) {
  int maxInArr = -100;
  for (int i = 0; i < size; ++i) {
    maxInArr = std::max(maxInArr, arr[i]);
  }
  return maxInArr;
}

void countSort(int arr[], int size){
  int output[size];
  for(int i = 0; i < size; ++i)
    output[i] = 0;

  int maxInArr = findMax(arr, size);
  int counts[maxInArr+1];
  for(int i = 0; i < maxInArr + 1; ++i)
    counts[i] = 0;

  for(int i = 0; i < size; i++) {
      counts[arr[i]]++;
  }

  // build accumulated sum
  for(int i = 1; i < maxInArr+1; ++i) {
    counts[i] = counts[i]+counts[i-1];
  }

  /**
	output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
  **/
  // here we go through the input array backwards findingi
  // the right place to place it in our outputs array
  for (int i = size-1; i >= 0; i--) {
    output[counts[arr[i]]-1] = arr[i];
    counts[arr[i]]--;
  }
  
  // copy output into input array  
  for(int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}


/**
recursively call a function that takes an array and sorts it at an index
start from sorting by the bins of the 0th index, till end of the max index
**/
int getHighestDigitPlace(int arr[], int size) {
  int highestDig = -1;
  for (int i = 0; i < size; i++) { 
   int currNum = arr[i];
   int places = 1;
   while(10^places != currNum) {
     places++;
   }
   highestDig = highestDig > places ? highestDig : places;
  }
  return highestDig;
}

void _radixSorted(int arr[], int size, int digitToSort) {
  // preserve the order unless the bins change bins 0-9
  
}

void radixSort(int arr[], int size) {
  int highestDigitPlace = getHighestDigitPlace(arr, size);  
  for(int i = 0; i < highestDigitPlace + 1; i++) {
    _radixSorted(arr, size, i);
  }
}

