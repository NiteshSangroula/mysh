#include <stdio.h>
#include <string.h>

#include "../include/builtins.h"
#include "../include/parser.h"

#define MAX_SIZE 100

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    char command[MAX_SIZE] = "";

    while (1) {
        printf("mysh> ");
        fgets(command, MAX_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';

        char* args[MAX_ARGS];

        // parse the command
        parse_string(command, args);

        // check if the command is built in
        is_builtin(command);

        // executes the command
        execute_builtin(args);
    }

    return 0;
}
