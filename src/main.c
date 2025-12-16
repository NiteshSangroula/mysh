#include <stdio.h>
#include <string.h>

#include "../include/parser.h"

#define MAX_SIZE 100

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    char command[MAX_SIZE] = "";
    char exit_command[] = "exit";

    while (strcmp(command, exit_command)) {
        printf("mysh> ");
        fgets(command, MAX_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';

        char* args[MAX_ARGS];
        int length = parse_string(command, args);  // this changes the command

        printf("[ ");
        for (int i = 0; i <= length; i++) {
            printf("%s ", args[i]);
        }
        printf("]\n");
    }

    return 0;
}
