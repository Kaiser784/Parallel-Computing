#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <omp.h>
#define MAX_LENGTH 100;
long long int e[100],d[100],temp[100];
char en[100];

#define PRIME1 31 
#define PRIME2 37

int IsPrime(long long int num)
{
	long long int j;
	long long int k;
	k = sqrt(num);

	for (j=2;j<=k;j++)
	{
		if(num%j==0)
		return 0;
	}
	return 1;
}

long long int prime(long long int num,long long int** primearray)

{
    long long int   count, c;
    long long int i=3;
    long long int *tmp = (long long int*) malloc(num*(sizeof(long long int)));

	#pragma omp parallel 
    
    for ( count = 2 ; count <= num ;  )
    {
        for ( c = 2 ; c <= i - 1 ; c++ ) {
        if ( i%c == 0 )
        break;
		for(int x = 0; i <1000; i++)
		{

		}
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

long long int gcd (long long int a , long long int b)
{	
	long long int i,g;

	#pragma omp parallel 

	for ( i=1;i <= a || i <=b ; ++i)
	{
		if (a%i==0 && b%i==0)
		g=i;
	}

    return g;
}
	


long long int pollard ( long long int n)
{

	long long int bound=50;
    long long int i,j;
    long long int *primearray;
    long long int highestPrime,t;
    long long int x;
    long long int g;
    
    long long int a =2,p,q;
    long long int b,e,c =1;
    long long int power,temp;
    highestPrime = prime(bound, &primearray);  temp = 1;
    bound = highestPrime;
    x= primearray[0];
	
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
                        return g;
                }
		}

        x = primearray[i+1];
    }
  
    return 0;
} 
	
int main()
{
	
	long long int fac1;
	long long int other_factor,after_e,g1;
	long long int p, q, n;
	int flag;
	
	long long int t;
	
	double start, end, time;
	p=PRIME1;
	q=PRIME2;
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
	printf("\nTime taken = %f\n", time);
	
	return 0;
}
