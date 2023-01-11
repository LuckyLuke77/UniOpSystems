#include <stdio.h>
#include <unistd.h>
#define CHILD 0
int main(int argc, char **argv)
{
    printf("Hello, World!\n");

    char message[] = "%s: PID=%d, PPID=%d\n";
    int PrintMessage(char P[]) { printf(message, P, getpid(), getppid()); }
    pid_t pid = fork();
    wait();
    if (pid == CHILD) {
	pid = fork();
	wait();
	if (pid == CHILD) {
		PrintMessage("P3");
	} else {
		PrintMessage("P1");
	}

    } else {
	pid_t pid = fork();
	wait();
	if (pid == CHILD) {
		pid_t pid = fork();
    		wait();
		if (pid == CHILD) {
			PrintMessage("P4");
		} else {
			pid_t pid = fork();
	    		wait();
			if (pid == CHILD) {
				pid_t pid = fork();
				wait();
				if (pid == CHILD) {
					PrintMessage("P6");
				} else {
					PrintMessage("P5");
				}
			} else {
				PrintMessage("P2");
			}
		}
    	} else {	
		PrintMessage("P0");
		printf("\ncat is taking over!\n\n");
		char *argv[] = {"cat", "ex1.c", 0};
        	execvp(argv[0],argv);
	}
    }
    printf("Goodbye World!\n");

    return 0;
}
