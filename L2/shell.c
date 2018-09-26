#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, new_fork;
	char *args[10];

    while(1){
        cmdline = calloc(1, 1024);
        i = 0;

        printf("prompt> ");
        fgets(cmdline, 1024, stdin);
        //fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);

        token = strtok(cmdline, "\n ");
        while (token != NULL) {
            //printf("%s\n", token);x
            args[i++] = strdup(token);
            token = strtok(NULL, "\n ");
        }
        args[i] = NULL;

        new_fork = fork();
        if (new_fork < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if(new_fork == 0){
            execvp(args[0], args);
        }
        else{
            wait(NULL);
        }

        free(cmdline);
    }

	return 0;

}
