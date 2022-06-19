#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "../includes/vm.h"

#define WINDOW_SIZE 255

uint8_t *read_program(const char *program) {
    uint8_t *results = calloc(sizeof(uint8_t), PROGRAM_SIZE);

    FILE *fp = fopen(program, "r");

    if (fp == NULL) {
        printf("File not found or could not be read.");
        exit(1);
    }

    size_t memory_index = 0;
    uint8_t current_character;
    size_t char_index = 0;
    char *current_str_of_characters = malloc(255);

    while (1) {
        current_character = fgetc(fp);

        if (current_character == 'E') {
            break;
        }

        if (isblank(current_character) || isspace(current_character)) {
            if (strlen(current_str_of_characters) != 0) {
                printf("%s\n", current_str_of_characters);

                char *to_copy = malloc(255);
                strncpy(to_copy, current_str_of_characters, strlen(current_str_of_characters));
                results[memory_index] = atoi(to_copy);

                memset(current_str_of_characters, 0, strlen(current_str_of_characters));
                memset(to_copy, 0, strlen(to_copy));

                memory_index++;
                char_index = 0;
            }
        } else {
            current_str_of_characters[char_index] = current_character;
            char_index++;
        }

    }

    fclose(fp);

    return results;
}

int main() {
    uint8_t *program = read_program("test.8bit");

    printf("PRINTING PROGRAM\n");

    for (int i = 0; i < PROGRAM_SIZE; i++) {
        if (program[i] != 0) {
            printf("%d\n", program[i]);
        }
    }

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("8bittersweet",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    255,
    255, 0
    );

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_Quit();
    return 0;
}
