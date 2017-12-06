#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "shared.h"
#include "macros.h"
#include "menu.h"
#include "game.h"
#include "tools.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define FIRAMONO_PATH "../assets/fonts/firamono.ttf"
#define FONTAWESOME_PATH "../assets/fonts/fontawesome.ttf"

/*
 * IDEAS:
 *  - get rid of everything jauge.{h,c}
 *    - should be rendered when the ship's life/shield changes
 *  - get rid of everything fond.{h,c}
 *    - it should be generated directly from game.c
 *  - are the aliens overkill?
 */

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    /* Init SDL */
    int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int img_init = IMG_Init(img_flags);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || img_init != img_flags || TTF_Init() != 0)
    {
        fprintf(stderr, "/!\\ Could not init SDL: %s\nSDL_image flags: %d/%d\n",
                SDL_GetError(), img_init, img_flags);
        return EXIT_FAILURE;
    }

    // Create window
    window = SDL_CreateWindow("Lighter Than Fast: Unknown Within",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);
    check_SDL(window);

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    check_SDL(renderer);

    // Load font
    // load the same font several times to give if several attributes?
    font = TTF_OpenFont(FIRAMONO_PATH, 22);
    check_TTF(font);

    /* Get user selection */
    /* bool show_menu; */
    /* do */
    /* { */
    /*     #ifdef DEBUG */
    /*     puts("* In main menu"); */
    /*     #endif */
    /*     show_menu = false; */
    /*     switch (menu()) */
    /*     { */
    /*     case PLAY_GAME: */
    /*         // TODO lancer le jeu */
    /*         play_game(&show_menu); */
    /*     case QUIT_GAME: */
    /*     default: */
    /*         break; */
    /*     } */
    /* } while (show_menu); */

    _play_game();

    /* Exit */
    // TODO create goodbye screen
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
