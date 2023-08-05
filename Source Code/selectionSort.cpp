#include "../Sorting Headers/selectionSort.h"

SelectionSort::SelectionSort()
{
    this->window = nullptr;
	this->renderer = nullptr;
	SDL_CreateWindowAndRenderer(100*10, 100*50, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 10, .5);
}

SelectionSort::~SelectionSort()
{
}


/* slow sorting algorithm - 
*	selection sort algorithm sort the array in-place, which means that no
*	additional memory is used - O(1)
*	sorting of elements takes O(n^2) because of nested for loops
*	average case: O(n^2)
*	- one for current minimum value
*	- one for finding new min value
*/
void SelectionSort::sort_array(vector<int> myVector)
{
    int len = myVector.size();

	for (int i = 0; i < len - 1; i++)
	{
		int min = i;	// ith element is the min
		for (int j = i+1; j < len; j++)
		{
			if (myVector[j] < myVector[min])
			{
				min = j;	// update index of min val to j element
			}
		}
		int temp = myVector[i];	// keep track of old min value
		myVector[i] = myVector[min];	// swap prev min with new min
		myVector[min] = temp;	// store prev old min value in min index after swap

        // call visualizer
        
        visualize_sort(myVector, this->renderer, i, min);
        
	}
}

void SelectionSort::visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, 
unsigned int red, unsigned int blue)
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

void SelectionSort::clear_screen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SelectionSort::show_screen(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}