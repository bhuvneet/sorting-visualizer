#ifndef QSORT_H
#define QSORT_H

#include "common.h"
#include "../SortingHeaders/visualize.h"

class quickSort : public sort_algo
{
    private:
        Visualize_algo visualize;
        
    public:
        quickSort(/* args */);
        ~quickSort();
        void sort_array(vector<int> &myVector);
        void sort_array(vector<int> &myVector, int start, int end);  // inherited classes will have their implementation
        int partition_array(vector<int> &part_vector, int start, int end);
};

#endif
