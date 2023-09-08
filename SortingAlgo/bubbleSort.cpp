#include "../SortingHeaders/bubbleSort.h"
#include "../SortingHeaders/visualize.h"

bubbleSort::bubbleSort()
{ // constructor

}

bubbleSort::~bubbleSort(){}

void bubbleSort::sort_array(vector<int> &myVector)
{
	int len = myVector.size();
	// Time 
	//	-- for already sorted array - best case: O(n)
	//  -- for average case - O(n^2)
	//  -- for worst case - O(n^2)
	// Stability -- bubble sort is a stable sorting algorithm because swap only takes place when right element is less that left,
	//				maintaining the order
	// start from the beginning of the array
	// compare two consecutive elems each time
	// swap if needed
	// otherwise, increment the pointers

	Visualize_algo visualize;
	bool swapped;
	
	// the outer loop goes through the whole array once
	for (int j = 0; j < len - 1; j++)
	{
		swapped = false;
		// the inner loop goes through the array until n-1 , compares 2 elements and swap is needed before continue traversing

		// *** after the first iteration, the last element in array will be sorted
		// the inner loop doesn't need to check the last elements as iterations increase 
		// because one more element (last elements) will be sorted. Hence, len - i in inner loop condition. ***

		for (int i = 0; i < len - j - 1; i++)	// len - 1 to ensure right is not out of bounds - 
												// last element will not be compared to the next element as there is no next element
		{
			int left = i;
			int right = i + 1;
			if (myVector[right] < myVector[left])
			{
				// swap left and right
				int temp = myVector[left];
				myVector[left] = myVector[right];
				myVector[right] = temp;

				swapped = true;	// this will ensure optimization when no sorting was rqd in the first place
								// if swapped is never set to true, that means that array must already be sorted
				
				visualize.render_loop(myVector, left, right);
			}
			
		}
		// If no two elements were swapped in the inner loop, the array is already sorted.
		if (!swapped) {
			break;
		}
	}

				
	for(int i = 0; i < myVector.size(); ++i)
	{
		printf("INSIDE %d\n", myVector[i]);
	}

}