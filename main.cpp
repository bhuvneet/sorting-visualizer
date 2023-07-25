#include <stdio.h>
#include <iostream>
#include <stdbool.h>	// for boolean data type
#include <vector>
using namespace std;

// O(n^2) in average case
void selection_sort(int arr[], int len);
void bubble_sort(int arr[], int len);
void insertion_sort(int arr[], int len);

// O(nlogn)
void merge_sort(vector<int>& arr);	// O(nlogn) - worst case
void merge(vector<int>arr1, vector<int>arr2, vector<int>& OGarr);

// divide and conquer
/* O(nlogn) - avg case
*  0(n^2) - worst case
*/
void quicksort(vector<int>arr, int start, int end);


int main()
{
	int arr[] = { 2,8,4,6,3,7,1,9,0 };
	int len = sizeof(arr) / sizeof(int);

	//selection_sort(arr, len);

	int arr1[] = { 2,7,1,4,5,3 };
	int len1 = sizeof(arr1) / sizeof(int);
	//bubble_sort(arr1, len1);
	//insertion_sort(arr1, len1);

	vector<int> myVec{ 2,8,4,6,3,7,1,9,0 };
	merge_sort(myVec);

	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

	//for (int i = 0; i < len1; i++)
	//{
	//	printf("sorted array element %d: %d\n", i, arr1[i]);
	//}

	return 0;
}

/* slow sorting algorithm - 
*	selection sort algorithm sort the array in-place, which means that no
*	additional memory is used - O(1)
*	sorting of elements takes O(n^2) because of nested for loops
*	average case: O(n^2)
*	- one for current minimum value
*	- one for finding new min value
*/
void selection_sort(int arr[], int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		int min = i;	// ith element is the min
		for (int j = i+1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;	// update index of min val to j element
			}
		}
		int temp = arr[i];	// keep track of old min value
		arr[i] = arr[min];	// swap prev min with new min
		arr[min] = temp;	// store prev old min value in min index after swap
	}
}

void bubble_sort(int arr[], int len)
{
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
	
	bool swapped = false;
	
	// the outer loop goes through the whole array once
	do{
		bool swapped = false;
		// the inner loop goes through the array until n-1 , compares 2 elements and swap is needed before continue traversing

		// *** after the first iteration, the last element in array will be sorted
		// the inner loop doesn't need to check the last elements as iterations increase 
		// because one more element (last elements) will be sorted. Hence, len - i in inner loop condition. ***

		for (int i = 0; i < len - 1 - i; i++)	// len - 1 to ensure right is not out of bounds - 
												// last element will not be compared to the next element as there is no next element
		{
			int left = i;
			int right = i + 1;
			if (arr[right] < arr[left])
			{
				// swap left and right
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;

				swapped = true;	// this will ensure optimization when no sorting was rqd in the first place
								// if swapped is never set to true, that means that array must already be sorted
			}
		}
	} while (swapped);	// continue going through the array if there was a swap
}


/*
	Time Complexity - best case: O(n)
	average case: O(n^2)
	# of comparisons are lesser than bubble/selection sort
*/
void insertion_sort(int arr[], int len)
{
	// sorted subset starts from the 0th index
	for (int i = 1; i < len; i++)
	{
		int valToSort = arr[i];
		int valIndex = i;	// from 0 to ith index, elements are sorted

		// shift all elements in sorted subset to the right one time
		while (valIndex > 0 && arr[valIndex - 1] > valToSort)
		{
			arr[valIndex] = arr[valIndex - 1];	// new values being shifted to right
			valIndex--;	// move to left index
		}
		// once the while loop is exited, this will be the place where valToSort should be added
		arr[valIndex] = valToSort;
		}
}

/*
	Time complexity - O(nlogn) worst case
	not in place
	sorting done recursively
	divide and conquer
*/
void merge_sort(vector<int>& arr)
{
	// get length of array to be sorted
	if (arr.size() > 1)	// if len is less than 2, array is already sorted
	{
		int len = arr.size();
		int mid = arr.size() / 2;

		vector<int> lVector(mid);
		vector<int> rVector(len - mid);

		// fill left side of the array to a new array
		for (int i = 0; i < mid; i++)
		{
			lVector[i] = arr[i];
		}

		int indx = 0;
		// fill right side of the array to a new array
		for (int j = mid; j < len; j++)
		{
			rVector[indx++] = arr[j];
		}

		merge_sort(lVector);
		merge_sort(rVector);
		merge(lVector, rVector, arr);
	}
}

void merge(vector<int>arr1, vector<int>arr2, vector<int>& OGarr)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] <= arr2[j])
		{
			OGarr[k] = arr1[i];
			i++;
		}
		else
		{
			OGarr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < arr1.size())
	{
		OGarr[k] = arr1[i];
		i++;
		k++;
	}
	while (j < arr2.size())
	{
		OGarr[k] = arr2[j];
		j++;
		k++;
	}
}

void quicksort(vector<int>arr, int start, int end)
{

}

void partition(vector<int>arr, int start, int end)
{

}