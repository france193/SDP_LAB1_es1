/**
 * Name:    Francesco
 * Surname: Longo
 * ID:      223428
 * Lab:     1
 * Ex:      1
 *
 * Write a C program that takes two arguments from the command line, n and k, creates a subdirectory data,
 * and creates in that directory n files, named f00, f01, ..., fnn, respectively, each including a variable
 * number (random in range [1-k]) of random integers.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRandomNumber(int seed, int min, int max);

int main(int argc, char **argv) {
    int n, k;
    char *subdirname = "data";
    FILE *fp;

    if (argc != 3) {
        fprintf(stdout, "Expected 3 argument: <prog_name> <n> <k>\n");
        exit(-1);
    }

    // take n,k from command line
    n = atoi(argv[1]);
    k = atoi(argv[2]);

    // initialize a string for command
    char cmd[20];
    strcpy(cmd, "mkdir ");
    strcat(cmd, subdirname);

    if (system(cmd) == -1) {
        fprintf(stdout, "Error executing system\n");
        exit(-2);
    }

    char path[20], pathTemp[20];
    strcpy(path, "./");
    strcat(path, subdirname);
    strcat(path, "/");

    for (int i = 0; i < n; i++) {
        sprintf(pathTemp, "%s%s%i%s", path, "f0", i, ".txt");

        if ((fp = fopen(pathTemp, "wt")) == NULL) {
            fprintf(stdout, "Error creating file\n");
            exit(-3);
        }

        int nums = getRandomNumber(0, 1, k);
        for (int j = 0; j < nums; j++) {
            fprintf(fp, "%d\n", rand());
        }

        fclose(fp);

        strcpy(pathTemp, "/0");
    }

    return 0;
}

int getRandomNumber(int seed, int min, int max) {
    //srand(seed);
    int num = rand() % (max - min + 1) + min;
    return num;
}
