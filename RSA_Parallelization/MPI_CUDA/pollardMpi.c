#include<stdio.h>
#include<stdlib.h>
#include <mpi.h>
#include<omp.h>
#include<math.h>

#define BOUND 5000
#define PRIME1 31 
#define PRIME2 37
long long int prime(long long int num,long long int** primearray)
{
    long long int   count, c;
    long long int i=3;
    long long int *tmp = (long long int*) malloc(num*(sizeof(long long int)));
    for ( count = 2 ; count <= num ;  )
    {
        for ( c = 2 ; c <= i - 1 ; c++ ) {
        if ( i%c == 0 )
        break;
        }
        if ( c == i )
        {
		tmp[0]=2;
                tmp[count-1]=i;
		*primearray=tmp;
		  count++;
        }
        i++;
 }
    return tmp[count-2];
 }
        long long int gcd (long long int u , long long int v)
        {
        
long long  int shift;
long long int diff;
    if (u == 0 || v == 0)
        return u | v;

    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0)
        u >>= 1;

    do {
        while ((v & 1) == 0)
            v >>= 1;

        if (u < v) {
            v -= u;

        } else {
             diff = u - v;
            u = v;
            v = diff;
        }
        v >>= 1;
    } while (v != 0);

return u<<shift;
}
long long int pollard(long long int *d_primearray,long long int bound, long long int p, long long int n)
{
long long int i,j,highestPrime;
long long int maxE;
long long int a =2;
long long int x,g,e,c =1;
long long int power,temp;
maxE=0;
// printf("\nEntered Pollard Function\n");
	for(i=0;i<bound/p;i++)
	{	
	if(d_primearray[i] > maxE )
		maxE = d_primearray[i];
	}
	bound = maxE;
	x = d_primearray[0];
   	for(i=0;x<bound;i++)
    	{
 		power=(long long int)(log10(bound)/log10(x));
		if(power!=0)
            {
                temp =(long long int)pow(x,power);

            for(j=1;j<=temp;j++)
                {
                  c= (c*2)%n;
                }
                a=c;
		 g = gcd(a-1,n); 
                if((1 < g) && (g < n))
                {
                      
                        break;
                }
	  }

        x = d_primearray[i+1];
    }
return g;
}

int main (int argc, char **argv)
{
	int id, p;

	long long int *h_primearray,*in;
	long long int bound= BOUND;
	long long int n = (PRIME1*PRIME2);
        long long int h_highestPrime , res;
        double start, end;
       	MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &id);
       	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Barrier(MPI_COMM_WORLD);
	start=omp_get_wtime();
	if(id==0)
	{
		 h_highestPrime = prime(bound, &h_primearray);

	}
    
    MPI_Bcast(&bound, 1, MPI_LONG_LONG,0, MPI_COMM_WORLD);
	if( bound%p != 0)
	{
		printf("unevenly distributed \n");
		MPI_Finalize();
		return 0;
	}
	 in = (long long int *) malloc((bound/p) *sizeof(long long int));
	MPI_Scatter(h_primearray,(bound/p), MPI_LONG_LONG, in, (bound/p), MPI_LONG_LONG, 0, MPI_COMM_WORLD);
	res = pollard(in,bound,p,n);
	if( res> 1 && res!=n)
	{
	// end=omp_get_wtime();
	}
        MPI_Finalize();
    end=omp_get_wtime();
	if(id==0)
        printf("Total time taken =%f\n",(end-start));    
	fflush(stdout);	
	return 0;

}
