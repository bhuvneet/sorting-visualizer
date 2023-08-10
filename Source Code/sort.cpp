#include "../Sorting Headers/sort.h"

void sort::visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int red, unsigned int blue)
{

    // Calculate the maximum height of the elements in the array
    int maxElementHeight = *std::max_element(myVector.begin(), myVector.end());

    // Calculate the number of elements to visualize at once based on the window width
    int numElements = myVector.size();
    int windowWidth = 1000; // Adjust this based on your desired window width
    int barWidth = windowWidth / numElements;

    // Scale the elements to fit within the window height
    float scale = 500.0f / maxElementHeight;

    clear_screen(this->renderer);
    
	// loop over vector to draw the height of elements
	int index = 0;
	for(int i : myVector)
	{
        if(index == red)    // color sorting bars red
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        }
        else if (index == blue)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
		else
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
		
        SDL_RenderDrawLine(renderer, index, 1000, index, i);
		index++;
	}

    show_screen(this->renderer);
}

void clear_screen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void show_screen(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}