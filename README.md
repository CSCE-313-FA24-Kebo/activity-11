# Parallel Pi Approximation using Threading

In this activity, you will parallelize a program that approximates π (pi) using the Riemann sum method. The program splits the computation into two main sections that need to be optimized using multiple threads.

## Learning Objectives
- Implement parallel computing concepts using C++ threads
- Understand and handle thread synchronization
- Optimize performance through parallel execution
- Practice working with shared resources in a multi-threaded environment

## Algorithm Background
The program approximates π using the Leibniz formula, which states that:
$π/4 = 1 - 1/3 + 1/5 - 1/7 + ...$

We compute this using a Riemann sum approximation, dividing the work among multiple threads for better performance.

You can read about it here: https://dotink.co/posts/pi-by-riemann-sum.

## Task 1: Parallelizing the Initial Computation
### main.cpp - Section 1
Your task is to parallelize the computation of individual terms using multiple threads. Each thread will compute a portion of the total sum.

1. Create a vector of threads (`std::vector<thread>`)
2. Launch `NUM_THREADS` threads that use the `single_sum_thread` function
3. Pass appropriate arguments to each thread:
  - id: Thread identifier (0 to NUM_THREADS-1)
  - nthreads: Total number of threads
  - sum: Array to store partial results
4. Join all threads with the main thread

Key Points:
- The id parameter ensures each thread works on its designated portion of the computation.
- All threads must complete (join) before moving to the next section.
- The single_sum_thread function is already implemented for you.

## Task 2: Parallelizing the Final Summation
### main.cpp - Section 2
Your task is to parallelize the final summation of results while ensuring **thread safety**.

1. Replace the serial summation code with a parallel implementation.
2. Use the provided `pi_sum_thread` function.
3. Implement proper synchronization in `pi_sum_thread` to prevent race conditions.
4. Create and join threads similar to Task 1.

Key Points:
The pi_sum_thread function includes a sleep(1) to simulate a long-running task.
The target execution time for this section should be approximately 1 second.
Critical sections should be kept as small as possible.
Shared variables must be passed by reference.

## Expected Output
For a configuration with two threads:

```
Number of threads: 2
Cache padding for coherency: 64 bytes
---
Pi approximation: 3.141593
Time to complete part 1: ~3.4 seconds
Time to complete part 2: ~1.0 seconds
```

## Notes
1. Remember, you want the critical section to be as small as possible.
1. No argument is passed to the program. Just make and run it.
1. You can complete part 1 and run it first without doing part 2.
1. Your program will be manually tested for correctness with additional test cases.
1. Your program should compile with no errors and warnings.

## Submission
Submit your files:
- main.cpp
- main.h
