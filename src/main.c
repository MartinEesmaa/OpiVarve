#include <stdio.h>
#include "color.h"

#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#define SOUND_COMMAND "PlaySound"

#elif defined(__APPLE__)
    #define SOUND_COMMAND "afplay"
#elif defined(__linux__)
    #define SOUND_COMMAND "aplay"
#endif

const char* PlayMusic(const char* filename) {
    static char command[256];

    #ifdef _WIN32
        PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
        snprintf(command, sizeof(command), "PlaySound(\"%s\")", filename);
    #elif defined(__APPLE__) || defined(__linux__)
        snprintf(command, sizeof(command), "%s \"%s\" &", SOUND_COMMAND, filename);
        system(command);
    #else
        snprintf(command, sizeof(command), "Unsupported OS");
    #endif

    return command;
}

void valivarv(){

    int valik = 0;

    while(1) {
    printf("\nMillise sa tahad valida varvi?\n");
    printf(ANSI_COLOR_BLUE "1: Sinine\n" ANSI_COLOR_RESET);
    printf("2: Roosa\n");
    printf(ANSI_COLOR_GREEN "3: Roheline\n");
    printf(ANSI_COLOR_RED "4: Punane\n");
    printf(ANSI_COLOR_YELLOW "5: Kollane\n");
    printf(ANSI_COLOR_BGW ANSI_COLOR_BLACK "6: Must\n" ANSI_COLOR_RESET);
    printf("7: Oranz\n");
    printf("8: Valge\n");
    printf("9: Pruun\n");
    printf(ANSI_COLOR_MAGENTA "10: Lilla\n");
    printf(ANSI_COLOR_GRAY "11: Hall\n");
    printf(ANSI_COLOR_CYAN "12: Helesinine\n" ANSI_COLOR_RESET);
    printf("Voite valjuda klahviga CTRL + C klaviatuuris voi sisesta null\n");

    if (scanf("%d", &valik) != 1) {
        while (getchar() != '\n');
        continue;
    }

    if (valik == 0) {
        printf("Valjumine...\n");
        break;
    }

    switch (valik) {
        case 1:
            printf(ANSI_COLOR_BLUE "\nSinine\n" ANSI_COLOR_RESET);
            PlayMusic("sound/sinine.wav");
            break;
        default:
            break;
        }
    }
}

int main(){
    printf("Opi varve (terminaal versioon)\n");
    printf("(C) 2025 Martin Eesmaa\n");
    valivarv();
    return 0;
}