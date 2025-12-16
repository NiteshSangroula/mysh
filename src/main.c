#include <stdio.h>
#include <string.h>

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
        printf("%s\n", command);
    }

    return 0;
}
