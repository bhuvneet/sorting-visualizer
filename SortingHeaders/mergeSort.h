#ifndef MERGESORT_H
#define MERGESORT_H
#include "common.h"

class mergeSort : public sort_algo
{
    private:
        /* data */
    public:
        mergeSort(/* args */);
        ~mergeSort();
        void sort_array(vector<int> arr) override;  // inherited classes will have their implementation
        void merge(vector<int>arr1, vector<int>arr2, vector<int>& OGarr);
};
#endif
