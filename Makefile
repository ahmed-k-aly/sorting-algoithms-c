CC = gcc -g

all: Sorting

Sorting: 
	$(CC) -o sorting Sorting.c 

sortAlgorithms.o: 
	$(CC) -c sortAlgorithms.c

insertionSort: 
	$(CC) -o myInsertionSort sort.c

selectionSort: 
	$(CC) -o sort mySelectionSort.c

mergeSort: 
	$(CC) -o sort myMergeSort.c

clean:
	rm -f *.o sort sorting