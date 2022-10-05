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


void selectionSort(int array[], int arraySize){
    // selection sort works by finding the smallest ith element in an array by only searching in the elements between i, ..., n where n is the highest index in the array
    for (int i = 0; i < arraySize - 1; i++){
        // find the smallest ith element
        int min = array[i];
        for (int j = i; j < arraySize; j++){
            if (array[j] < min) min = array[j];
        }
        swap(&min, &array[i]);
    }
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
void testSelectionSort(int maxArraySize, int minArraySize, int numTests){
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
            selectionSort(array, i);
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
    testSelectionSort(100, 1, 100);
    return 0;
}