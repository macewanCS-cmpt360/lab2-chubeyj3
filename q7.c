#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// ** THE TEXT ANSWERS ARE AT THE BOTTOM OF THE PAGE

int main(int argc, char *argv[]) {
    int new_fork = fork();
    printf("\n\n");
    if (new_fork < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(new_fork == 0){
        close(STDOUT_FILENO);
        printf("This is text written after file descriptor is closed");
    }
    else{
        printf("");
    }

    return 0;
}

/*
Answer: It appears the program doesn't print anywhere! There is no output
printed and no file created so it appears the printf() function just runs
and doesn't output anywhere. This is because there the STDOUT_FILENO is now
available, however the child process isn't being assigned the output stream
so the process doesn't have an output.
*/
