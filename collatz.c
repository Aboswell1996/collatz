#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//Alex Boswell
//301261407

void collatz(){

    int myInt = 0;

    printf("Please enter a positive integer:\n");
    scanf("%d", &myInt);

    while(myInt <= 0){
               printf("Sorry, the integer you entered is not valid, please try again:\n");
            scanf("%d", &myInt);
    }

    printf("\nPID is: %d \t Username: %s\n", getpid(), getlogin());

    pid_t pid;
    pid = fork();


    //Following the examplefrmo the proffesor's notes
    if (pid < 0 ){
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }

    else if (pid == 0){  //child process will have pid = 0 
    //computes the sequence of numbers and prints the sequence to the screen and exits.

        //printf("Entered Child Process\n");

        printf("%d\n", myInt);

        while(myInt != 1){

            if(myInt % 2 == 0){ //checking if myInt is even

            myInt= myInt/2;

            }
            else{   //myInt must be odd

            myInt = (myInt*3) + 1;

            }

            printf("%d\n", myInt);
        }

         //printf("Finished Child Process\n");
        return NULL;

    }
    else {              // the parent process will execute this case
    //have the initial process wait until the second process completes.
        /* parent will wait for child to complete */
        //printf ("Calling Wait() to wait for child process to execute\n");
		wait (NULL);
		printf ("Child %d Completed\n", pid);
		//exit(0);

    }



    //printf("Finished collatz\n");
}






int main (int argc, char *argv[]) {
 
collatz();


//printf("Finished Main\n");
return 0;
}
