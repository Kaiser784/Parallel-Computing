#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 100

int main()
{
    double a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], rand_a, rand_b;
    double start, end, exec;

    start = omp_get_wtime();

    for (int i = 0; i < SIZE; i++)
    {   
        for(int j = 0; j < SIZE; j++)
        {
            rand_a = rand();
            rand_b = rand();

            a[i][j] = i*rand_a;
            b[i][j] = i*rand_b;
            
            // for(int k = 0; k < 100000; k++)
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    end = omp_get_wtime();

    exec = end - start;

    printf("Serial Exec time - %f\n", exec);

    return 0;
}