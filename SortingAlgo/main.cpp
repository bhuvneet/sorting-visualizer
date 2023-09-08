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
		// length of array passed as argument to program
		for(int i = 0; i < argc; ++i)
		{
			cout << argv[i] << endl;
		}

		printf(" RANDOM NUMBERS\n");
		for(int i = 0; i < stoi(argv[2]); ++i)
		{
			myArray.myVector.push_back(myArray.elements(myArray.rand));	// add random int elements to vector
			printf("%d\n", myArray.myVector[i]);
		}

		cout << argv[1] << endl;
		cout << stoi(argv[1]) << endl;

		if(stoi(argv[1]) == 1)	// bubble sort
		{
			cout <<  "in bubble sort" << endl;
			bubbleSort bubb_sort;
			bubb_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf(" SORTED ARRAY\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("%d\n", myArray.myVector[i]);
			}
		}
		else if(stoi(argv[1]) == 2)	// bucket sort
		{
			cout <<  "in bucket sort" << endl;
		}
		else if(stoi(argv[1]) == 3)	// selection sort
		{
			cout <<  "in selection sort" << endl;
			SelectionSort select_sort;
			select_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf(" SORTED ARRAY\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("%d\n", myArray.myVector[i]);
			}
		}
		else if(stoi(argv[1]) == 4)	// insertion sort
		{
			cout <<  "in insertion sort" << endl;
			insertionSort insert_sort;
			insert_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf(" SORTED ARRAY\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("%d\n", myArray.myVector[i]);
			}
		}
		else if(stoi(argv[1]) == 5)		// heap sort
		{
			cout <<  "in heap sort" << endl;
		}
		else if(stoi(argv[1]) == 6)	// quick sort
		{
			cout <<  "in quick sort" << endl;
		}
		else if(stoi(argv[1]) == 7)		// merge sort
		{
			cout <<  "in merge sort" << endl;
			mergeSort merge_sort;
			merge_sort.sort_array(myArray.myVector);	// pass random array to selection sort
			printf(" SORTED ARRAY\n");
			
			for(int i = 0; i < myArray.myVector.size(); ++i)
			{
				printf("%d\n", myArray.myVector[i]);
			}
		}
		else
		{
			cout << "Invalid choice of sorting algoritm. Exiting program..." << endl;
		}
	}
	
	return 0;
}