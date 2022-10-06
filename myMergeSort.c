// My C implementation of insertion sort:
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Method that swaps two elements in an array together
 * 
 * @param a pointer to the first  element
 * @param b pointer to the second element
 */
void swap(int* a, int* b){
    if (*a == *b) return;
    int temp = *b; // store value of b in temp
    *b = *a; // overwrite what's in b with a
    *a = temp;  // overwrite what's in a with b
}


void merge(int array[], int left, int midpt, int right){
    // create an empty array and merge both in it then make that the newer array
    int a1size = midpt - left; // size of 1st subarray
    int a2size = right - midpt; // size of second subarray
    int temp_array[a1size + a2size]; // size = right - left
    int i = left; // left subarray 0th index
    int j = midpt;// right subarray 0th index
    int t = 0;
    
    // put the elements of both subarrays in order in a temp array
    while (i < a1size + left && j < a2size + midpt){
        // put smaller element in the new array.
        if (array[i] < array[j]){
            temp_array[t] = array[i];
            i++;
        } else{
            temp_array[t] = array[j];
            j++;
        }
        t++;
    }

    // if elements remain from array 1, copy them
    while (i < a1size + left){
        temp_array[t] = array[i];
        i++;
        t++;
    }

    // if elements remain from array 2, copy them
    while (j < a2size + midpt){
        temp_array[t] = array[j];
        j++;
        t++;
    }

    t = 0;
    for (i = left; i < right; i++){
        array[i] = temp_array[t];
    }
}




void mergeSortHelper(int array[], int left, int right){
    if ( left >= right) return;
    int midpoint = (left + right)/2; // calculate midpoint 
    mergeSortHelper(array, left, midpoint); // split left half of array
    mergeSortHelper(array, midpoint+1, right); // split right half of array
    merge(array, left, midpoint, right);
}


void mergeSort(int array[], int arraySize){
    // split array in half until we reach base case of just one element
    // Then, we merge back
    mergeSortHelper(array, 0, arraySize);
}

/**
 * @brief Method that prints an array
 * 
 * @param array array to print
 * @param arraySize size of the array
 */
void printArray(int array[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}



/**
 * @brief Method that tests the insertion sort implementation with various randomly generated arrays
 * @param maxArraySize the maximum size of the array to be generated.
 * @param minArraySize the minimum size of the array to be generated.
 * @param numTests the number of tests to run.
 */
void testmergeSort(int maxArraySize, int minArraySize, int numTests){
    // loop over array sizes
    for (int i = minArraySize; i < maxArraySize; i++){
        // loop over number of tests
        printf("Testing array of size %d\n", i);
        for (int j = 0; j < numTests; j++){
            // generate random array
            int* array = malloc(i * sizeof(int));
            for (int k = 0; k < i; k++){
                array[k] = rand() % 100;
            }
            printArray(array, i);
            // sort array
            mergeSort(array, i);
            // check if sorted
            for (int k = 0; k < i-1; k++){
                if (array[k] > array[k+1]){
                    printf("Array not sorted correctly!\n");
                    printf("Missorted Array: \n");
                    printArray(array, i);
                    return;
                }
            }
            free(array);
            printf("Array sorted correctly! Test %d/%d passed.\n\n", j+1, numTests);
        }
    }
    printf("All tests passed!\n");
    }

int main(){
    testmergeSort(100, 1, 100);
    return 0;
}