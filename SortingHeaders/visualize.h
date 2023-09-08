#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "common.h"

class Visualize_algo
{
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        const int windowHeight = 1920;
        const int windowWidth = 1080;
        bool windowCreated;

    public:
        Visualize_algo();
        ~Visualize_algo();

        void createWindow(int numElements);

        void clear_screen(SDL_Renderer* renderer);
        void show_screen(SDL_Renderer* renderer);
        void render_loop(vector<int>& myVector, unsigned int red, unsigned int blue);
        void visualize_sort(vector<int>& myVector, SDL_Renderer* renderer, unsigned int newMin, unsigned int currMin);
    };

#endif