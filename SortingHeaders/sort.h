#ifndef SORT_H
#define SORT_H

#include "common.h"

class sort_algo
{
    private:
        //SDL_Window* window = nullptr;
        //SDL_Renderer* renderer = nullptr;

    public:
        sort_algo();
        ~sort_algo();

        //void clear_screen(SDL_Renderer* renderer);
        //void show_screen(SDL_Renderer* renderer);

        virtual void sort_array(vector<int> &myVector) = 0;  // inherited classes will have their implementation
        //void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue);
    };

#endif
