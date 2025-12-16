#include "../include/parser.h"

#include <string.h>

int parse_string(char* command, char** args) {
    int i = 0;
    char* token = strtok(command, " ");

    while (token && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return i;
}
