#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820

//Need to ask for memory, if not the string will only be local to this fuction
char *string_clone(const char *str, size_t length) {
    if (!str)
        return NULL;

    //Ask for memory
    char *output = malloc(length + 1);
    if (!output) {
        fprintf(stderr, "malloc error");
        return NULL;
    }

    for (size_t i=0; i<length;i++) {
        output[i] = str[i];
    }
    output[length] = '\0';
    return output;
}


int main(void) {
    char original[]=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         ANSI_BRGOLD
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                           Episode II \n\n"
         "                      ATTACK OF THE CLONES\n\n"
         "                There is  unrest in the Galactic\n"
         "                Senate. Several  thousand  solar\n"
         "                systems  have   declared   their\n"
         "                intentions to leave the Republic.\n\n"
         "                This      separatist     movement,\n"
         "                under  the   leadership   of  the\n"
         "                mysterious   Count   Dooku,   has\n"
         "                made it difficult for the limited\n"
         "                number   of   Jedi   Knights   to\n"
         "                maintain   peace   and  order  in\n"
         "                the galaxy.\n\n"
         "                Senator   Amidala,   the   former\n"
         "                Queen   of  Naboo,  is  returning\n"
         "                to  the  Galactic  Senate to vote\n"
         "                on the critical issue of creating\n"
         "                an    ARMY    OF   THE   REPUBLIC\n"
         "                to    assist    the   overwhelmed\n"
         "                Jedi....\n" ANSI_WHITE;

    //Clone original string using string clone modified
    char *copy=NULL;

    copy = string_clone(original, sizeof(original)/sizeof(*original));

    printf("Original:\n" ANSI_CYAN
            " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
           " %s\n", copy);

    free(copy);
    return EXIT_SUCCESS;
}

/*
    We where using a function with a pointer without asking for memory. That's
    ok on local functions but in output we have the clone of original but when
    the function ends that memory dissappear because we is not managed by us.
    To solve that just ask memory for output.

    Length value is 1812, we can also see this in char original.
*/