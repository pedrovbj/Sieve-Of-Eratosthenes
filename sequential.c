#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
typedef char bool;

void usage(char* prog) {
    printf("Usage: %s [positive whole number]\n", prog);
    exit(-1);
}

int main(int argc, char *argv[]) {
    int i, p;
    int N;
    bool* prime;

    //Wrong arguments handling
    if (argc != 2) {
        usage(argv[0]);
    }

    //Input conversion
    N = (int) atoi(argv[1]);
    if (N < 1) {
        usage(argv[0]);
    }

    //Allocates array of bool for each number n: 2 <= n <= N
    prime = (bool*) malloc((N-1)*sizeof(bool));

    //Set every entry of array as TRUE
    for (i = 0; i < N-1; i++) {
        prime[i] = TRUE;
    }

    //Set numbers multiple of p as not prime
    int sqrt_N = floor(sqrt(N));
    for (p = 2; p <= sqrt_N; p++) {
        if (prime[p-2]) {
            for (i = 2*p; i <= N; i += p) {
                prime[i-2] = FALSE;
            }
        }
    }

    //Output printing
    // printf("All prime numbers less then or equal to %d are:\n", N);
    // for (p = 2; p <= N; p++) {
    //     if (prime[p-2]) {
    //         printf("%d\t", p);
    //     }
    // }
    // printf("\n");

    //Cleaning up
    free(prime);
    exit(0);
}
