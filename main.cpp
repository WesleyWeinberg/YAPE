#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>
int main(int argc, char *args[]) {
  int SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

  SDL_Window *window =
      SDL_CreateWindow("Testing", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 600, 800, SDL_WINDOW_SHOWN);

  SDL_Renderer *render =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  while (true) {
    // e is an SDL_event,
    SDL_Event e;
    if (SDL_WaitEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }
    }

    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
  }

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
