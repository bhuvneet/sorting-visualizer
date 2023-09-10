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

        //this->visualize.render_loop(myVector, pIndex, -1);

        // sort left of partition index
        sort_array(myVector, start, pIndex - 1);

        //this->visualize.render_loop(myVector, start, end);

        // sort right of partition index
        sort_array(myVector, pIndex + 1, end);

        //this->visualize.render_loop(myVector, start, end);

        // exit condition --> when element == 1, array is sorted
    }

}

int quickSort::partition_array(vector<int> &myVector, int start, int end)
{
    int pivot = myVector[end];

    int pIndex = start;

    // start comparing from the start index until end index
    for (int i = start; i <= end; i++)
    {      
        //this->visualize.render_loop(myVector, i, pIndex);

        if (myVector[i] < pivot)
        {
            int temp = myVector[pIndex];
            myVector[pIndex] = myVector[i];
            myVector[i] = temp;

            this->visualize.render_loop(myVector, i, pIndex);
            printf("QS i: %d\n", i);
            printf("QS pivot: %d\n", pIndex);
            pIndex++;
        }
        //this->visualize.render_loop(myVector, i, pivot);
    }

    int temp = myVector[pIndex];
    myVector[pIndex] = myVector[end];
    myVector[end] = temp;
    this->visualize.render_loop(myVector, pIndex, end);
    printf("QS pIndex: %d\n", pIndex);
    printf("QS end: %d\n", end);

    return pIndex;
}

 