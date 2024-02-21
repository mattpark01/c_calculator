#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Divide requires exactly two arguments\n");
        return 1;
    }
    if (atoi(argv[2]) == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        return 1;
    }
    double quotient = (double)atoi(argv[1]) / atoi(argv[2]);
    printf("%f\n", quotient);
    return 0;
}