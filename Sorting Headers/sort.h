#ifndef SORT_H
#define SORT_H

#include "common.h"

class sort
{
private:
    SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public:
    sort()  // constructor to create window for sorting
    {
        SDL_CreateWindowAndRenderer(100*10, 100*50, 0, &window, &renderer);
	    SDL_RenderSetScale(renderer, 10, .5);
    }

    void clear_screen(SDL_Renderer* renderer);
    void show_screen(SDL_Renderer* renderer);

    ~sort(){};

    virtual void sort_array(vector<int> myVector);  // inherited classes will have their implementation
    void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue);
};

#endif
