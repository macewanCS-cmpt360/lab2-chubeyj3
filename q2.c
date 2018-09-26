#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// ** THE TEXT ANSWERS ARE AT THE BOTTOM OF THE PAGE

int main(int argc, char *argv[]) {
    close(STDOUT_FILENO);
    open("./q2_assignment_output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    int new_fork = fork();
    printf("\n\n");
    if (new_fork < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(new_fork == 0){
        printf("This is text from the child\n\n");
    }
    else{
        printf("This is text from the parent\n\n");
    }

    return 0;
}



/*
Answer: Yes, both the child and parent can access the file descriptor
returned by open. This makes sense because when the child is being
created, it copies all of the parents memory to its own memory, including
the file descriptor. When they are writing concurrently it appears from the
output that one process writes first, however this may have just been because
one process ran faster. I think if both processes ran at exactly the same time
their outputs may be mixed together.
*/
