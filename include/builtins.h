#ifndef BUILTINS_H
#define BUILTINS_H

int is_builtin(char* command);
void execute_builtin(char** args);

int builtin_cd(char** args);
int builtin_exit();
int builtin_pwd();
int builtin_echo(char** args);

#endif
