#include "../SortingHeaders/insertionSort.h"
#include "../SortingHeaders/visualize.h"

insertionSort::insertionSort(){};
insertionSort::~insertionSort(){};

/*
	Time Complexity - best case: O(n)
	average case: O(n^2)
	# of comparisons are lesser than bubble/selection sort
*/
void insertionSort::sort_array(vector<int> &myVector)
{
	Visualize_algo visualize;
    int len = myVector.size();

	// start from 1st index until the last index
	for (int i = 1; i < len; i++)
	{
		int valToSort = myVector[i];
		int valIndex = i;	// from 0 to ith index, elements are sorted

		// shift all elements in sorted subset to the right one time
		// while this index is greater than 0 AND ith element is less than the value of its left side
		while (valIndex > 0 && myVector[valIndex - 1] > valToSort)
		{
			myVector[valIndex] = myVector[valIndex - 1];	// new values being shifted to right
			// Visualize the swap with red and blue colors
			valIndex--;	// move to left index
			visualize.render_loop(myVector, valIndex + 1, i);
			printf("I is %d\n", i);
		}

		// once the while loop is exited, this will be the place where valToSort should be added
		myVector[valIndex] = valToSort;
	}
}