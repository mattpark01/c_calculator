#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Subtract requires exactly two arguments\n");
        return 1;
    }
    int result = atoi(argv[1]) - atoi(argv[2]);
    printf("%d\n", result);
    return 0;
}