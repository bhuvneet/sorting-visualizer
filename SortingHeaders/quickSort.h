#ifndef QSORT_H
#define QSORT_H

#include "common.h"

class quickSort : public sort_algo
{
    private:
        /* data */
    public:
        quickSort(/* args */);
        ~quickSort();
        void sort_array(vector<int> &myVector);  // inherited classes will have their implementation
};

#endif
