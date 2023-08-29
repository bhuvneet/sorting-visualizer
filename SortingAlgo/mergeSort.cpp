#include "../SortingHeaders/mergeSort.h"

mergeSort::mergeSort(){}
mergeSort::~mergeSort(){}

/*
	Time complexity - O(nlogn) worst case
	not in place
	sorting done recursively
	divide and conquer
*/
void mergeSort::sort_array(vector<int> arr)
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

		sort_array(lVector);
		sort_array(rVector);
		merge(lVector, rVector, arr);
	}
}

void mergeSort::merge(vector<int>arr1, vector<int>arr2, vector<int>& OGarr)
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