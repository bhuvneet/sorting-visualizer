#include "Sorting Headers/visualize.h"

Visualize::Visualize()
{
	this->window = nullptr;
	this->renderer = nullptr;
	SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 10, 10);
}

Visualize::~Visualize()
{
}


void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue)
{
	// loop over vector to draw the height of elements
	int index = 0;
	for(int i : myVector)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, index, 1000, index, i);
		index++;
	}
}