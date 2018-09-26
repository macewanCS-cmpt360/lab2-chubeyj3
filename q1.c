#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// ** THE TEXT ANSWERS ARE AT THE BOTTOM OF THE PAGE

int main(int argc, char *argv[]) {
    int new_fork = fork();
    int x = 100;
    printf("\n\n");
    printf("at the start of the program x = 100\n\n");
    if (new_fork < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
    }
    else if(new_fork == 0){
        printf("value of x in child:%d\n", x);
        x = 37;
        printf("new value of x in child(should be 37): %d\n", x);
    }
    else{
        printf("value of x in parent:%d\n", x);
        x = 114;
        printf("new value of x in parent(should be 114):%d\n", x);
    }
    printf("\n\n");

    return 0;
}


/*
Answer: After the fork the value stored in the variable x in the child process
matched the value stored in x in the parent process, namely 100. This is because
when a child forks from its parent it copies most values stored in memory of the
parent process.

The values of x after the child forked from the parent are changed for each
respective process. This is because although the child may have copied all
the values stored in the parent's memory, it is now a separate process and
has its own separate memory to store data.
*/
