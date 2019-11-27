#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

char ** parse_args( char * line ){
    char * token;
    char ** tokens_array;
    tokens_array = malloc(sizeof(token) * 6);
    int i = 0;
    while (line != NULL){
        token = strsep(&line, " ");
        tokens_array[i] = token;
        i++;
    }
    tokens_array[i] = NULL;
    return tokens_array;
}

int main(int argc, char *argv[]){
    char * line;
    char buffer[1000];
    printf("Please enter a program: \n");

    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer)-1] = 0;
    line = buffer;

    char ** arg_array;
    arg_array = parse_args(line);
    execvp(arg_array[0], arg_array);

    for (int i = 0; arg_array[i] != NULL; i++) {
        free(arg_array[i]);
    }

    return 0;
}
