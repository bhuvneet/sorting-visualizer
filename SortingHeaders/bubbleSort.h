#ifndef BBSORT_H
#define BBSORT_H
#include "common.h"

class bubbleSort : public sort_algo
{
    private:
        /* data */
    public:
        bubbleSort(/* args */);
        ~bubbleSort();
        void sort_array(vector<int> &myVector) override;  // inherited classes will have their implementation
};

#endif
