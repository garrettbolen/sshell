#include <cstdio>
#include <cstdlib>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)

{
char *args[MAX_LINE / 2 + 1]; /* max of 40 arguments */
    int should_run = 1;
    int i, upper;
    char command[MAX_LINE + 1];
    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        /** fork a child to execute command (using one of the exec calls)
        Break out of loop if user types ‘quit’ or ‘exit’ then exit
        program **/

        // read user input
        scanf("%[^\n]s", command);
        printf("%s\n", command);

        // fork
        int pid = fork();

        if (pid < 0) {
            printf("Fork failure.\n");
            exit(1);
        }

        if (pid == 0) {
            
        }

        break;






   }

return 0;
}
