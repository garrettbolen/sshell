#include <cstdio>
#include <cstdlib>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)

{
    char *args[MAX_LINE / 2 + 1]; /* max of 40 arguments */
    int should_run = 1;
    int parentWaits = 0;
    int i, upper;
    // char command[MAX_LINE + 1];
    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        /** fork a child to execute command (using one of the exec calls)
        Break out of loop if user types ‘quit’ or ‘exit’ then exit
        program **/

        char command[MAX_LINE + 1];
        
        // read user input
        scanf("%[^\n]s", command);
        // printf("%s\n", command);

        char * token = strtok(command, " ");
        int i = 0;

        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        args[i] = NULL;

        if (strcmp(args[0], "&") == 0) parentWaits = 1;
        if ((strcmp(args[0], "exit") == 0) || (strcmp(args[0], "quit") == 0)) break;

        // fork
        int pid = fork();

        if (pid < 0) {
            printf("Error: could not fork.\n");
            exit(1);
        }

        if (pid == 0) {
            execvp(args[0], args);
        } else {
            // we are the parent
            // wait to finish
            // if & ignore this, don't wait
            if (parentWaits) wait(NULL);
        }

   }

return 0;
}
