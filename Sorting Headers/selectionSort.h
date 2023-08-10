#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "common.h"

class SelectionSort
{
private:
    SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
public:
    SelectionSort();
    ~SelectionSort();

    //void clear_screen(SDL_Renderer* renderer);
    //void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue);
    void sort_array(vector<int> myVector);
    //void show_screen(SDL_Renderer* renderer);
};

#endif // SELECTIONSORT_H

