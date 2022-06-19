CC = gcc
FLAGS = -std=c11 -pedantic -Wall -Wextra
FILES = src/vm.c src/main.c
SDL_FLAGS = -lSDL2 -lSDL2main

all:
	$(CC) $(FILES) $(FLAGS) $(SDL_FLAGS) -o main