#include "../SortingHeaders/visualize.h"

Visualize_algo::Visualize_algo()
{
    SDL_CreateWindowAndRenderer(1000, 500, 0, &window, &renderer);
    this->windowCreated = false;
}

Visualize_algo::~Visualize_algo(){};

void Visualize_algo::createWindow(int totalElements)
{

}

void Visualize_algo::render_loop(vector<int>& myVector, unsigned int newMin, unsigned int currMin)
{
    // red is element being swapped
    // blue is the current min element

    // Visualize the sorting process
    visualize_sort(myVector, renderer, newMin, currMin);
}

void Visualize_algo::visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int newMin, unsigned int currMin)
{

    // Calculate the maximum height of the elements in the array
    int maxElementHeight = *std::max_element(myVector.begin(), myVector.end());

    // Calculate the number of elements to visualize at once based on the window width
    int numElements = myVector.size();
    int windowHeight = 500; 
    int windowWidth = numElements * 4; 

    // Calculate the space between bars and the width of each bar
    int spaceBetweenBars = 2; // Set the space between bars
    //int barWidth = (windowWidth - (numElements - 1) * spaceBetweenBars) / numElements;
    int barWidth = (1000 / (numElements + spaceBetweenBars)) - 1;

    // Scale the elements to fit within the window height
    float scale = static_cast<float>(windowHeight) / maxElementHeight;

    // Calculate the starting x-coordinate to center the bars
    //int startX = (windowWidth - (numElements * barWidth + (numElements - 1) * spaceBetweenBars)) / 2;

    // Calculate the total width of all bars including spaces between them
    int totalWidth = numElements * barWidth + (numElements - 1) * spaceBetweenBars;

    // Calculate the starting x-coordinate to center the bars horizontally
    int startX = 0;
    
    int index = 0;
    clear_screen(this->renderer);

    // loop over vector to draw the height of elements
    for (int i : myVector) 
    {
        if (index == newMin) // color sorting bars red
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } 
        else if (index == currMin) 
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        } 
        else 
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        int barHeight = static_cast<int>(i * scale);
        int x =  index * (barWidth + spaceBetweenBars);

        // Draw filled rectangles representing the bars
        SDL_Rect barRect = {x, 0, barWidth, barHeight};
        SDL_RenderFillRect(renderer, &barRect);

        index++;
    }

    show_screen(this->renderer);
}

void Visualize_algo::render_merge_step(const vector<int>& arr, int index1, int index2)
{
    // Clear the screen
    clear_screen(this->renderer);

    // Define colors
    SDL_Color redColor = {255, 0, 0, 255};
    SDL_Color blueColor = {0, 0, 255, 255};
    SDL_Color greenColor = {0, 255, 0, 255};
    SDL_Color whiteColor = {255, 255, 255, 255};

    int windowHeight = 500;
    int windowWidth = arr.size() * 4; // Adjust the width based on your requirements
    int barWidth = 4; // Width of each bar
    int spaceBetweenBars = 2; // Space between bars

    // Scale the elements to fit within the window height
    float scale = static_cast<float>(windowHeight) / *max_element(arr.begin(), arr.end());

    // Calculate the starting x-coordinate to center the bars horizontally
    int startX = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int barHeight = static_cast<int>(arr[i] * scale);
        int x = startX + i * (barWidth + spaceBetweenBars);

        // Set the color based on the indices
        SDL_Color color;
        if (i == index1 || i == index2) // Elements being compared
        {
            color = blueColor;
        }
        else if (i < index1 || i < index2) // Already sorted elements
        {
            color = greenColor;
        }
        else // Elements yet to be compared
        {
            color = whiteColor;
        }

        // Draw filled rectangles representing the bars
        SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
        SDL_Rect barRect = {x, windowHeight - barHeight, barWidth, barHeight};
        SDL_RenderFillRect(renderer, &barRect);
    }

    // Show the updated screen
    show_screen(this->renderer);
}

void Visualize_algo::clear_screen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Visualize_algo::show_screen(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
    SDL_Delay(200);
}