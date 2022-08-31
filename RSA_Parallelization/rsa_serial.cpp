#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <omp.h>

using namespace std;

#define MESSAGE_SIZE 1000

// In order to determine whether two numbers are co-prime (relatively prime), we can check
// whether their gcd (greatest common divisor) is greater than 1. The gcd can be calculated by Euclid's algorithm:
unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int x;
	while (b)
	{
		x = a % b;
		a = b;
		b = x;
    }
    return a;
}

int main()
{
	unsigned int message[MESSAGE_SIZE];
	long double encryptedMessage[MESSAGE_SIZE];

    ifstream fInput("./input1.txt");
    
    // Checking whether the input file exists in the directory or not
    if (!fInput)
	{
		printf("Error opening the input file.\n");
		return -1;
	}

	unsigned int iP, iQ, iD, iE, iN, iTotientN;

	fInput >> iP >> iQ;

	int i = 0;
	char cItem;

	while(fInput >> cItem)
	{
		message[i] = cItem - '0';
		i++;
	}

	// Done reading from the file
	fInput.close();

	cout << "P: " << iP << endl;
	cout << "Q: " << iQ << endl;

	// Print plain text
	cout << "------ Plaintext message -------" << endl;
	for (i = 0; i < MESSAGE_SIZE; i++)
		cout << message[i] << ' ';
	cout << endl;

	double start = omp_get_wtime();
	
	//Compute iN, iE, and iD
	iN = iP * iQ;
	iP -= 1;
	iQ -= 1;
	iTotientN = iP * iQ;
	
	iE = 7;
	i = 1;
	while(i < (iN - 1))
	{
		if(gcd(iE, iTotientN) == 1)
			break;
			
		i++;
	}

	i = 1;
	while(i < iN)
	{
		iD = (iE * i - 1) % iTotientN;
		if(!iD)
		{
			iD = i;
			break;
		}
		i++;
	}

	// RSA Encryption
	cout << "------ Encrypted message -------" << endl;
	cout << "E: " << iE << endl;
	cout << "N: " << iN << endl;
	for(i = 0; i < MESSAGE_SIZE; i++)
	{
		encryptedMessage[i] = 1;
		for (int j = 1; j <= iE; j++)
			encryptedMessage[i] = encryptedMessage[i] * message[i];
		
		encryptedMessage[i] = fmod(encryptedMessage[i], iN);

		cout << encryptedMessage[i]  << ' ';
	}
	cout << endl;

	double end = omp_get_wtime();
	double exec = end - start;

	cout << "Execution Time - " << exec << endl;

	// RSA Decryption
	cout << "------ Decrypted message -------" << endl;
	cout << "D: " << iD << endl;
	cout << "N: " << iN << endl;
	long double decryptedText;

	for(i = 0; i < MESSAGE_SIZE; i++)
	{
		decryptedText = 1;
		for (int j = 1; j <= iD; j++)
			decryptedText = decryptedText * encryptedMessage[i];
		
		decryptedText = fmod(decryptedText, iN);

		cout << decryptedText << ' ';
	}
	cout << endl;

    return 0;
}