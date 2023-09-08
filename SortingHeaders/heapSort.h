#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"

class heapSort : public sort_algo
{
    private:
        /* data */
    public:
        heapSort(/* args */);
        ~heapSort();
        void sort_array(vector<int> &myVector);  // inherited classes will have their implementation
};

#endif