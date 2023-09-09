#include "../SortingHeaders/quickSort.h"
#include "../SortingHeaders/visualize.h"

quickSort::quickSort(){};
quickSort::~quickSort(){};

void quickSort::sort_array(vector<int> &myVector)
{

}

void quickSort::sort_array(vector<int> &myVector, int start, int end)
{
    if (start < end)
    {
        // partition array --> array, start and end
        int pIndex = partition_array(myVector, start, end);

        // sort left of partition index
        sort_array(myVector, start, pIndex - 1);

        // sort right of partition index
        sort_array(myVector, pIndex + 1, end);

        // exit condition --> when element == 1, array is sorted
    }

}

int quickSort::partition_array(vector<int> &myVector, int start, int end)
{
    int pivot = myVector[end];

    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (myVector[i] <= pivot)
        {
            int temp = myVector[pIndex];
            myVector[pIndex] = myVector[i];
            myVector[i] = temp;

            pIndex++;
        }
    }

    int temp = myVector[pIndex];
    myVector[pIndex] = myVector[end];
    myVector[end] = temp;

    return pIndex;
}

 