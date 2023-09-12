#include "../SortingHeaders/constants.h"
#include "../SortingHeaders/sort.h"
#include "../SortingHeaders/bubbleSort.h"
#include "../SortingHeaders/bucketSort.h"
#include "../SortingHeaders/heapSort.h"
#include "../SortingHeaders/insertionSort.h"
#include "../SortingHeaders/mergeSort.h"
#include "../SortingHeaders/quickSort.h"
#include "../SortingHeaders/selectionSort.h"
#include "../SortingHeaders/visualize.h"

struct randomElements
{
	random_device rand;
	uniform_int_distribution<int> elements{5, 1000};
	vector<int> myVector;
};

bool isFalse = false;

int main(int argc, char* argv[])
{
	randomElements myArray;

	if (argc == 1)
	{
		printf("ERROR: Pass appropriate arguments\n");
	}
	else
	{
		printf("\n\tRANDOM ARRAY:\n\n");
		for(int i = 0; i < stoi(argv[2]); ++i)
		{
			myArray.myVector.push_back(myArray.elements(myArray.rand));	// add random int elements to vector
			printf("\t%*d ", 3, myArray.myVector[i]);

			// Check if we've printed the desired number of elements per line
			if ((i + 1) % 10 == 0) {
				printf("\n"); // Start a new line
			}
		}
		printf("\n"); // Start a new line

		if(stoi(argv[1]) == 1)	// bubble sort
		{
			bubbleSort bubb_sort;
			bubb_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf("\tBUBBLE SORT: SORTED ARRAY\n\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("\t%*d ", 3, myArray.myVector[i]);

				// Check if we've printed the desired number of elements per line
				if ((i + 1) % 10 == 0) {
					printf("\n"); // Start a new line
				}
			}
		}
		else if(stoi(argv[1]) == 2)	// bucket sort
		{
			cout <<  "in bucket sort" << endl;
		}
		else if(stoi(argv[1]) == 3)	// selection sort
		{
			SelectionSort select_sort;
			select_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf("\tSELECTION SORT: SORTED ARRAY\n\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("\t%*d ", 3, myArray.myVector[i]);

				// Check if we've printed the desired number of elements per line
				if ((i + 1) % 10 == 0) {
					printf("\n"); // Start a new line
				}
			}
		}
		else if(stoi(argv[1]) == 4)	// insertion sort
		{
			insertionSort insert_sort;
			insert_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf("\tINSERTION SORT: SORTED ARRAY\n\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("\t%*d ", 3, myArray.myVector[i]);

				// Check if we've printed the desired number of elements per line
				if ((i + 1) % 10 == 0) {
					printf("\n"); // Start a new line
				}
			}
		}
		else if(stoi(argv[1]) == 5)		// heap sort
		{
			cout <<  "in heap sort" << endl;
		}
		else if(stoi(argv[1]) == 6)	// quick sort
		{
			quickSort quick_sort;
			int len = myArray.myVector.size();
			quick_sort.sort_array(myArray.myVector, 0, len - 1);	// pass random array to selection sort
			printf("\tQUICKSORT SORTED ARRAY\n\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("\t%*d ", 3, myArray.myVector[i]);

				// Check if we've printed the desired number of elements per line
				if ((i + 1) % 10 == 0) {
					printf("\n"); // Start a new line
				}
			}
		}
		else if(stoi(argv[1]) == 7)		// merge sort
		{
			mergeSort merge_sort;
			merge_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf("\tMERGE SORT: SORTED ARRAY\n\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("\t%*d ", 3, myArray.myVector[i]);

				// Check if we've printed the desired number of elements per line
				if ((i + 1) % 10 == 0) {
					printf("\n"); // Start a new line
				}
			}
		}
		else
		{
			cout << "Invalid choice of sorting algoritm. Exiting program..." << endl;
		}
		printf("\n"); // Start a new line
	}
	
	return 0;
}