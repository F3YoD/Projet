SHELL=/usr/bin/env bash  # Allow brace expansion

NAME=lighter_than_fast
CFLAGS=-Wall -std=c99 -g
SDLFLAGS=$(shell sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf
O=../obj
B=../bin
A=../assets
FONTS=$(A)/fonts/Inter-UI-Regular.ttf
MIDI_EXAMPLE=$(A)/midi/1\ Space\ Cruise\ (Title).mid
OBJECTS=$(patsubst %.c, $(O)/%.o, $(wildcard *.c))

all: $(O) $(FONTS) $(MIDI_EXAMPLE) $(B) $(OBJECTS)
	gcc $(CFLAGS) -o $(B)/$(NAME) $(OBJECTS) $(SDLFLAGS)

# Necessary folders
$(O) $(B):
	@mkdir $@

# Objects
$(O)/alien.o: alien.c alien.h
	gcc $(CFLAGS) -o $@ -c $< $(SDLFLAGS)

$(O)/battle.o: battle.c $(O)/ships.o battle.h
	gcc $(CFLAGS) -o $@ -c $< $(SDLFLAGS)

$(O)/game.o: game.c $(O)/alien.o
	gcc $(CFLAGS) -o $@ -c $^ $(SDLFLAGS)

$(O)/main.o: main.c $(patsubst $(O)/main.o, , $(OBJECTS))
	gcc $(CFLAGS) -o $@ -c $^ $(SDLFLAGS)

$(O)/%.o: %.c
	gcc $(CFLAGS) -o $@ -c $< $(SDLFLAGS)

$(FONTS):  # Download & extract fonts
	@bash ../get_ressources.sh

# Cleaning
clean:
	rm -rf $(O) $(B) $(A)/fonts $(A)/midi
