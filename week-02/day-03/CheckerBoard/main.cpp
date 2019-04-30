#include <iostream>
#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void draw();
bool init();
void close();

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

void draw()
{
    SDL_SetRenderDrawColor(gRenderer, 255 /*R*/, 255 /*G*/, 0 /*B*/, 0xFF /*A*/);

    SDL_Rect negyzet = {0, 0, 50, 50};

    for (int i = 0; i < SCREEN_WIDTH/50 + 1; i++){
        for (int j = 0; j < SCREEN_HEIGHT/50 + 1; j++){
            if (((i + 1) % 2 != 0) && ((j + 1) % 2 != 0)){
                SDL_Rect negyzet = {i*50, j*50, 50, 50};
                SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
                SDL_RenderDrawRect(gRenderer, &negyzet);
                SDL_RenderFillRect(gRenderer, &negyzet);
            } else if (((i + 1) % 2 == 0) && ((j + 1) % 2 == 0)){
                SDL_Rect negyzet = {i*50, j*50, 50, 50};
                SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0 /*B*/, 0xFF /*A*/);
                SDL_RenderDrawRect(gRenderer, &negyzet);
                SDL_RenderFillRect(gRenderer, &negyzet);
            } else {
                SDL_Rect negyzet = {i*50, j*50, 50, 50};
                SDL_SetRenderDrawColor(gRenderer, 255 /*R*/, 255 /*G*/, 255 /*B*/, 0xFF /*A*/);
                SDL_RenderDrawRect(gRenderer, &negyzet);
                SDL_RenderFillRect(gRenderer, &negyzet);
            }
        }
    }
}

bool init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }
    bool quit = false;

    SDL_Event e;

    while( !quit ) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        SDL_RenderPresent(gRenderer);
    }
    close();

    return 0;
}