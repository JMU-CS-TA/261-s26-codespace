/*
 * CS 261 Example
 *
 * Demonstrates shared-memory parallelism (based on CS 470 assignment)
 */

#include <sys/time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL_DARTS 200000000

int thread_count;               // global thread count
long darts_in_circle = 0;       // global dart tracker
pthread_mutex_t mutex;          // mutex to protect global dart tracker

void* throw_darts(void* rank)
{
    unsigned long seed = (long)rank;
    long local_darts = TOTAL_DARTS; // TODO: fix this!

    for (long i = 0; i < local_darts; i++) {

        // throw a dart (generate random numbers for x,y coordinates)
        seed = (1103515245*seed + 12345) % (1<<31);
        double x = ((double)seed / ULONG_MAX)*2.0 - 1.0;
        seed = (1103515245*seed + 12345) % (1<<31);
        double y = ((double)seed / ULONG_MAX)*2.0 - 1.0;
        double dist_sq = x*x + y*y;

        // update global dart tracker (TODO: fix this!)
        if (dist_sq <= 1.0) {
            darts_in_circle++;
        }
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    // check and parse command-line arguments
    if (argc != 2) {
        printf("Usage: %s <num-threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    thread_count = strtol(argv[1], NULL, 10);

    // initialize threading
    pthread_t *thread_handles = (pthread_t*)malloc(thread_count *
                                                   sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    // start timing
    struct timeval tv;
    double start, end;
    gettimeofday(&tv, NULL);
    start = tv.tv_sec+(tv.tv_usec/1000000.0);

    // spawn threads
    for(long t = 0; t < thread_count; t++) {
        pthread_create(&thread_handles[t], NULL,
                throw_darts, (void*)t);
    }

    // wait for threads to finish
    for(long t = 0; t < thread_count; t++) {
        pthread_join(thread_handles[t], NULL);
    }

    // calculate pi using results of simulation
    double pi_est = 4 * darts_in_circle / ((double)TOTAL_DARTS);
    printf("Estimated pi: %f", pi_est);

    // end timing
    gettimeofday(&tv, NULL);
    end = tv.tv_sec+(tv.tv_usec/1000000.0);
    printf(" (%.6lf seconds elapsed)\n", end-start);

    // clean up
    pthread_mutex_destroy(&mutex);
    free(thread_handles);
    return EXIT_SUCCESS;
}


