#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
typedef char bool;

struct threadArgs {
    int id;
    int start;
    int end;
};

int sqrt_N;
int currentPrime = 0;
bool* prime;

void usage(char* prog) {
    printf("Usage: %s [positive whole number] [number of threads]\n\n"
            "The number of threads must be less then or equal to the "
            "whole number\n", prog);
    exit(-1);
}

void* sieve(void *tArgs) {
    int i, p;
    struct threadArgs *args;

    args = (struct threadArgs*) tArgs;
    //printf("<%d> (%d, %d)\t", args->id, args->start+2, args->end+2);


    //Set every entry of array as TRUE
    for (i = args->start; i <= args->end; i++) {
        prime[i] = TRUE;
    }

    // clock_t begin = clock();
    for (p = 2; p <= sqrt_N; p++) {
        if (prime[p-2]) {
            if (currentPrime <= args->end && currentPrime >= args->start) {
                if (currentPrime <= p) currentPrime = p;
            } else {
                while(currentPrime < p) pthread_yield();
            }
            i = ceil((args->start+2)/(float)p)*p;
            if(i == p) i += p;
            //printf("<%d> i=%d\n", args->id, i);
            for (; i <= args->end+2; i += p) {
                prime[i-2] = FALSE;
                //printf("<%d> x%d\t", args->id, i);
            }
        }
    }
    // clock_t end = clock();
    // double elapsed_secs = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("<%d> %lf s\n", args->id, elapsed_secs);


    pthread_exit(NULL);
}

int main(int argc, char* argv[0]) {
    int i, idx, p;
    int N;
    int nThreads;
    int nQuo, nRem;
    pthread_t *thread;
    struct threadArgs *tArgs;

    //Wrong arguments handling
    if (argc != 3) {
        usage(argv[0]);
    }

    //Input conversion
    N = (int) atoi(argv[1]);
    nThreads = (int) atoi(argv[2]);
    if (N < 1 || nThreads < 1 || nThreads > N) {
        usage(argv[0]);
    }

    //Set sqrt_N
    sqrt_N = floor(sqrt(N));

    //Allocates array of bools for each number n: 2 <= n <= N
    prime = (bool*) malloc((N-1)*sizeof(bool));

    //Create array of threads
    thread = (pthread_t*) malloc(nThreads*sizeof(pthread_t));

    //Create array of thread args
    //clock_t begin = clock();
    tArgs = (struct threadArgs*) malloc(nThreads*sizeof(struct threadArgs));
    //clock_t end = clock();
    //double elapsed_secs = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%lf\n", elapsed_secs);

    //Load calculations
    nQuo = (N-1) / nThreads;
    nRem = (N-1) % nThreads;

    //Threads creation
    idx = 0; //Index: current position in array of bools
    for(i = 0; i < nThreads; i++) {
        //Attributes id
        tArgs[i].id = i;

        //Sets start point
        tArgs[i].start = idx;

        //Load balancing
        if(i < nRem) {
            idx += nQuo+1;
        } else {
            idx += nQuo;
        }

        //Sets end point
        tArgs[i].end = idx-1;

        //Creates thread
        pthread_create(&thread[i], NULL, sieve, (void*) &tArgs[i]);
    }

    //Join threads
    for (i = 0; i < nThreads; i++) {
        pthread_join(thread[i], NULL);
    }

    //Output printing
    // printf("All prime numbers less then or equal to %d are:\n", N);
    // for (p = 2; p <= N; p++) {
    //     if (prime[p-2]) {
    //         printf("%d\t", p);
    //     } else {
    //         //printf("x%d\t", p);
    //     }
    // }
    // printf("\n");

    // for (p = 2; p <= N; p++) {
    //     if (prime[p-2]) {
    //         printf("%d,", p);
    //     }
    // }

    free(tArgs);
    free(thread);
    free(prime);
    exit(0);
}
