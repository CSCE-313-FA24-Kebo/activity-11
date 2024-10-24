/*
Parallel Pi Approximation using the Leibniz formula

Key Concepts to Implement:
1. Thread-safe computation using mutex synchronization
2. Parallel computation of partial sums
3. Thread-safe combination of results

Mathematical basis:
Pi is approximated using the formula: π/4 = ∫(1/(1+x²))dx from 0 to 1
This is computed using a Riemann sum with parallel computation
*/

#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Configuration constants - DO NOT MODIFY
#define NUM_THREADS 2   // Number of parallel threads to use
#define PAD 8          // Padding to prevent false sharing between threads
                       // This ensures each sum[i] is on its own cache line

// Problem size - DO NOT MODIFY
static long long int num_steps = 1000000000;
double step;           // Width of each rectangle in the Riemann sum

// TODO: Add synchronization primitive(s) here
// HINT: You'll need this to prevent race conditions in pi_sum_thread

/**
 * DO NOT MODIFY THIS FUNCTION
 * Computes partial sums for pi approximation
 * This function is thread-safe without explicit synchronization because each thread
 * writes to its own separate memory location in the sum array
 */
inline void single_sum_thread(int id, int num_threads, double sum[NUM_THREADS][PAD])
{
    double x;
    sum[id][0] = 0.0;
    for (long long int i = id; i < num_steps; i = i + num_threads)
    {
        x = (i + 0.5) * step;
        sum[id][0] += 4.0 / (1.0 + x * x);
    }
}

/**
 * TODO: Implement this function
 * This function must combine partial sums into the final pi approximation
 * 
 * HINTS:
 * 1. Think about what parameters you need:
 *    - You need to know which partial sum this thread handles (id)
 *    - You need access to the step size
 *    - You need access to the final pi value (needs to be shared between threads)
 *    - You need access to the array of partial sums
 * 2. This function must be thread-safe as multiple threads update the shared pi variable
 * 3. Keep the critical section as small as possible
 * 4. DO NOT remove the sleep(1) call - it simulates a long-running task
 */
inline void pi_sum_thread(/* TODO: add necessary parameters here */)
{
    // TODO: Implement thread-safe summation
    
    sleep(1); // DO NOT REMOVE THIS LINE
}