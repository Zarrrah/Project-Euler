//https://projecteuler.net/problem=3

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

const int64_t TESTVALUE = 600851475143;
vector<int64_t> primes;
int64_t largestFactor;


bool isPrime(int64_t x) 
{
	for (vector<int64_t>::iterator it = primes.begin(); it != primes.end(); it++) 
	{
		if (x % *it == 0) 
		{
			return false;
		}
	}
	return true;
}

int findNextPrime(int64_t lastPrime) 
{
	int x = lastPrime + 1;
	while (x <= largestFactor) 
	{
		if (isPrime(x)) 
		{
			return x;
		}
		else 
		{
			x++;
		}
	}
	return -1;
}

int main()
{
	largestFactor = TESTVALUE;
	int largestPrimeFactor = 0;
	//First prime added manually
	primes.push_back(2);

	//calculates the largest prime factor
	while (largestPrimeFactor < largestFactor) 
	{

		int i = 0;
		bool divided = false;

		while (i < primes.size() && divided == false) 
		{
			if (largestFactor % primes[i] == 0) 
			{
				divided == true;
				largestPrimeFactor = (largestPrimeFactor > primes[i]) ? largestPrimeFactor : primes[i];
				largestFactor = largestFactor / primes[i];
			}
			i++;
		}
		//Finds next prime
		primes.push_back(findNextPrime(primes.back()));
	}

	//Prints results to console
	cout << "The largest prime factor of " << TESTVALUE << " is " << largestPrimeFactor << ".";
	cin.get();
	return 0;
}
