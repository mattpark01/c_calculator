#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    while (1) {
        printf("Calculator> ");
        fflush(stdout);

        char command[256];
        if (!fgets(command, sizeof(command), stdin)) {
            // if fgets fails, continue to prompt for input
            continue;
        }

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = 0;

        // Exit the shell if the user types "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Fork a child process to handle the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process: execute the command
            // Prepare the arguments for `execlp`
            char *argv[10] = {NULL}; // Support up to 9 arguments + NULL terminator
            int argc = 0;
            char *token = strtok(command, " ");
            while (token != NULL && argc < 9) {
                argv[argc++] = token;
                token = strtok(NULL, " "); // Update token to the next word
            }
            argv[argc] = NULL;

            // Determine which program to execute based on the command
            char *program;

            if (strcmp(argv[0], "A") == 0) {
                program = "add";
                argv[0] = program;
            } else if (strcmp(argv[0], "S") == 0) {
                program = "subtract";
                argv[0] = program;
            } else if (strcmp(argv[0], "M") == 0) {
                program = "multiply";
                argv[0] = program;
            } else if (strcmp(argv[0], "D") == 0) {
                program = "divide";
                argv[0] = program;
            } else {
                fprintf(stderr, "Unknown command\n");
                exit(EXIT_FAILURE);
            }

            // Execute the arithmetic operation program
            execvp(program, argv);
            // If execvp returns, it must have failed
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process: wait for the child to complete
            wait(NULL);
        }
    }
    return 0;
}