#include<stdio.h>
#include "pollard.h"
#include <omp.h>
#define MAX_LENGTH 100;
long long int e[100],d[100],temp[100];
char en[100];
#define PRIME1 31 
#define PRIME2 37

int Isprime (long long int);

int IsPrime(long long int num)
{
	long long int j;
	long long int k;
	k = sqrt(num);
	
	for (j=2;j<=k;j++)
	{
		//printf("\nHere");
		if(num%j==0)
		return 0;
	}
	return 1;
}


	
int main()
{
	
	long long int fac1;
	long long int other_factor,after_e,g1;
	long long int p, q, n;
	int flag;
	
	long long int t;
	
	double start, end, time;
	p = PRIME1;
	q = PRIME2;
	// printf("Enter the prime number\n");
	// scanf("%lld",&p);
	
	// flag = IsPrime(p);
	// if( flag == 0)
	// {
	// 	printf("wrong input");
	// 	exit(0);
	// }
	// printf("Enter another prime number\n");
	// scanf("%lld",&q);
	// flag = IsPrime(q);
	// if(flag ==0 || p==q)
	// {
	// 	printf("wrong input");
	// 	exit(0);
	// }
	
	start=omp_get_wtime();

	n= p*q;
	t = (p-1)*(q-1);
	
	//decrypt(after_e);
	g1 = gcd( p, q);
    fac1 = pollard(n);
	printf("Factor is : %lld", fac1);
	other_factor = n/ fac1;
	
	after_e = (fac1-1)*(other_factor-1);
	
    end=omp_get_wtime();
	time = (double) (end-start);
	printf("\nTime taken = %f\n", time*1000);
	
	return 0;
}
