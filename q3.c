#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int new_fork = fork();
    printf("\n\n");
    if (new_fork < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(new_fork == 0){
        printf("hello\n\n");
    }
    else{
        sleep(1);
        printf("goodbye\n\n");
    }

    return 0;
}
