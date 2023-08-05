#ifndef VISUALIZE_H
#define VISUALIZE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

class Visualize
{
private:
    /* data */
public:
    Visualize(/* args */);
    ~Visualize();
    void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue);
};

#endif VISUALIZE_H


