#ifndef BCSORT_H
#define BCSORT_H
#include "common.h"

class bucketSort : public sort
{
private:
    /* data */
public:
    bucketSort(/* args */);
    ~bucketSort();
    void sort_array();  // inherited classes will have their implementation

};

#endif