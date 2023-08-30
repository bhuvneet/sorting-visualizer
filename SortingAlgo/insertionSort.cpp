#include "../SortingHeaders/insertionSort.h"

insertionSort::insertionSort(){};
insertionSort::~insertionSort(){};

/*
	Time Complexity - best case: O(n)
	average case: O(n^2)
	# of comparisons are lesser than bubble/selection sort
*/
void insertionSort::sort_array(vector<int> myVector)
{
    int len = myVector.size();

	// sorted subset starts from the 0th index
	for (int i = 1; i < len; i++)
	{
		int valToSort = myVector[i];
		int valIndex = i;	// from 0 to ith index, elements are sorted

		// shift all elements in sorted subset to the right one time
		while (valIndex > 0 && myVector[valIndex - 1] > valToSort)
		{
			myVector[valIndex] = myVector[valIndex - 1];	// new values being shifted to right
			valIndex--;	// move to left index
		}
		// once the while loop is exited, this will be the place where valToSort should be added
		myVector[valIndex] = valToSort;
		}
}