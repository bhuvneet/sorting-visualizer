#ifndef BCSORT_H
#define BCSORT_H
#include "common.h"

class bucketSort : public sort_algo
{
    private:
        /* data */
    public:
        bucketSort(/* args */);
        ~bucketSort();
        void sort_array(vector<int> myVector) override;  // inherited classes will have their implementation

};

#endif