#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 100

int main()
{
    double a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], rand_a, rand_b;
    double start, end, exec;
    int i, j;

    start = omp_get_wtime();
    int thread;
    
    #pragma omp parallel private(j) shared(c)
    {   
        thread = omp_get_num_threads();
        #pragma omp for
        for (i = 0; i < SIZE; i++)
        {      
            for(j = 0; j < SIZE; j++)
            {
                rand_a = rand();
                rand_b = rand();

                a[i][j] = i*rand_a;
                b[i][j] = i*rand_b;
                
                for(int k = 0; k < 100000; k++)
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }

    end = omp_get_wtime();

    exec = end - start;
    printf("%d, %f\n", thread, exec);

    return 0;
}