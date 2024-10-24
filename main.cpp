/*
Main program for parallel pi approximation
Your task is to parallelize two sections of this code:
1. Computing partial sums
2. Combining the partial sums into the final result
*/

#include "main.h"

int main()
{
    // DO NOT MODIFY THESE VARIABLE DECLARATIONS
    int i, nthreads = NUM_THREADS;
    double pi = 0.0, sum[NUM_THREADS][PAD];
    double start1, end1, start2, end2;

    // Calculate step size for the Riemann sum
    step = 1.0 / (double)num_steps;

    // Start timing for Section 1
    start1 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    
    // ##### START OF SECTION 1 #####
    // TODO: Parallelize the computation of partial sums
    // HINTS:
    // 1. Create a vector of threads
    // 2. Launch NUM_THREADS threads using single_sum_thread
    // 3. Wait for all threads to complete
    // ##### END OF SECTION 1 #####
    end1 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();

    // Start timing for Section 2
    start2 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    
    // ##### START OF SECTION 2 #####
    // TODO: Parallelize this code using pi_sum_thread
    // Current serial version (comment out when implementing parallel version):
    for (i = 0, pi = 0.0; i < nthreads; i++)
    {
        pi += sum[i][0] * step;
        sleep(1); // simulate a long running task
    }

    // HINTS for parallel version:
    // 1. Create a vector of threads
    // 2. Launch NUM_THREADS threads using pi_sum_thread
    // 3. Wait for all threads to complete
    // 4. The sleep(1) is already in pi_sum_thread
    
    // ##### END OF SECTION 2 #####
    end2 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    
    // Print results - DO NOT MODIFY
    printf("Number of threads: %i\nCache padding for coherency: %i bytes\n---\n", nthreads, PAD * 8);
    printf("Pi approximation: %f\nTime to complete part 1: %f seconds\nTime to complete part 2: %f seconds\n", 
           pi, (end1 - start1) * 1e-9, (end2 - start2) * 1e-9);
    return 0;
}