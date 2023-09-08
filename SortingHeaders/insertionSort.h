#ifndef INSORT_H
#define INSORT_H

#include "common.h"

class insertionSort : public sort_algo
{
    private:
        /* data */
    public:
        insertionSort(/* args */);
        ~insertionSort();
        void sort_array(vector<int> &myVector) override;  // inherited classes will have their implementation
};

#endif 