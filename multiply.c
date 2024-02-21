#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: Too few arguments for multiplication\n");
        return 1;
    }
    int product = 1;
    for (int i = 1; i < argc; i++) {
        product *= atoi(argv[i]);
    }
    printf("%d\n", product);
    return 0;
}