#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"

class heapSort : public sort
{
private:
    /* data */
public:
    heapSort(/* args */);
    ~heapSort();
    void sort_array();  // inherited classes will have their implementation
};

#endif