// https://projecteuler.net/problem=6

#include "stdafx.h"
#include <iostream>
using namespace std;

const int desiredPrime = 10001;
int primes[desiredPrime] = { 0 };


bool isPrime(int64_t x)
{
	int i = 0;
	while (primes[i] != 0) {
		if (x % primes[i] == 0)
		{
			return false;
		}
		i++;
	}
	return true;
}

void findNthPrime(int n)
{
	int primesFound = 1;
	int potentialPrime = primes[0] + 1;
	while (primesFound < n)
	{
		if (isPrime(potentialPrime))
		{
			primes[primesFound] = potentialPrime;
			primesFound++;
		}
		else
		{
			potentialPrime += 2;
		}
	}
}

int main()
{
	//First prime added manually
	primes[0] = 2;

	findNthPrime(desiredPrime);

	cout << "Prime #" << desiredPrime << " is " << primes[desiredPrime - 1];
	cin.get();
}