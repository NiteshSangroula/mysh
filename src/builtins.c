#include "../include/builtins.h"

#include <limits.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/executor.h"

int is_builtin(char* command) {
    const char* builtins[] = {"cd", "exit", "pwd", "echo", NULL};

    for (int i = 0; builtins[i] != NULL; i++) {
        if (strcmp(command, builtins[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int builtin_cd(char** args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing arguments\n");
        return -1;
    }

    if (chdir(args[1]) != 0) {
        perror("cd");
        return -1;
    }

    return 0;
}

int builtin_exit() {
    printf("exit\n");
    exit(0);
}

int builtin_pwd() {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == 0) {
        perror("pwd");
        return -1;
    }

    printf("%s\n", cwd);
    return 0;
}

int builtin_echo(char** args) {
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s", args[i]);
        if (args[i + 1] != NULL) {
            printf(" ");
        }
    }
    if (args[1] != NULL) {
        printf("\n");
    }
    return 0;
}

void execute_builtin(char** args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "cd") == 0) {
        builtin_cd(args);
    } else if (strcmp(args[0], "echo") == 0) {
        builtin_echo(args);
    } else if (strcmp(args[0], "pwd") == 0) {
        builtin_pwd();
    } else if (strcmp(args[0], "exit") == 0) {
        builtin_exit();
    } else {
        execute_command(args);
    }
}
