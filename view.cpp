#include <SDL2/SDL.h>

#define width 900
#define height 600

int main (){
    // Window or canvas frame initialization and attributes
    SDL_Window  *window = SDL_CreateWindow(
        "MandelBrot Set",
        SDL_WINDOWPOS_CENTERED ,
        SDL_WINDOWPOS_CENTERED,
        width ,
        height ,
        0 );

    // Window error handling
    if(!window){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Renderer initialization 
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED);
        
    // Renderer error handling
    if(!renderer){
        SDL_Log("Renderer error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int application_running = 1 ;
    while (application_running){
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                application_running = 0;
            }

            

        }
    }







}