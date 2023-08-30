#include "../SortingHeaders/constants.h"
#include "../SortingHeaders/sort.h"
#include "../SortingHeaders/bubbleSort.h"
#include "../SortingHeaders/bucketSort.h"
#include "../SortingHeaders/heapSort.h"
#include "../SortingHeaders/insertionSort.h"
#include "../SortingHeaders/mergeSort.h"
#include "../SortingHeaders/quickSort.h"
#include "../SortingHeaders/selectionSort.h"

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

	// length of array passed as argument to program
	for(int i = 0; i < argc; ++i)
	{
		cout << argv[i] << endl;
	}

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
	}
	else if(stoi(argv[1]) == 2)	// bucket sort
	{
		cout <<  "in bucket sort" << endl;
	}
	else if(stoi(argv[1]) == 3)	// selection sort
	{
		cout <<  "in selection sort" << endl;
		SelectionSort select_sort;
		select_sort.sort_array(myArray.myVector);
	}
	else if(stoi(argv[1]) == 4)	// insertion sort
	{
		cout <<  "in insertion sort" << endl;
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
	}
	else
	{
		cout << "Invalid choice of sorting algoritm. Exiting program..." << endl;
	}

	return 0;
}