#ifndef _MENU_
#define _MENU_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tools.h"
#include "shared.h"
#include "macros.h"

// NB_CHOICES allows to know the boundary of the enum
typedef enum menu_choice { CONTINUE_GAME, NEW_GAME, QUIT_GAME, NB_CHOICES } menu_choice_t;

menu_choice_t menu(bool);

#endif
