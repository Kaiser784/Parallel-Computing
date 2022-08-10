#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 100

int main()
{
    double a[SIZE], b[SIZE], c[SIZE], rand_a, rand_b;
    double start, end, exec;
    int i;

    start = omp_get_wtime();
    #pragma omp parallel shared(c)
    {   
        #pragma omp for
        for (i = 0; i < SIZE; i++)
        {
            rand_a = rand();
            rand_b = rand();

            a[i] = i*rand_a;
            b[i] = i*rand_b;
            
            c[i] = a[i] + b[i];
        }
    }
    end = omp_get_wtime();

    exec = end - start;

    printf("Parallel Exec time - %f\n", exec);

    return 0;
}