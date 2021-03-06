//https://projecteuler.net/problem=2

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const int max = 4000000;
	int previousTerms[2] = { 1, 2};
	int currentTerm = previousTerms[0] + previousTerms[1];
	int sum = 0;

	//Adds any even starting terms
	for (int i = 0; i < 2; i++) 
	{
		if (previousTerms[i] % 2 == 0) 
		{
			sum += previousTerms[i];
		}
	}

	//tests if the current value exceeds the maximum value
	while (currentTerm < max)
	{

		//adds value if even
		if (currentTerm % 2 == 0) 
		{
			sum += currentTerm;
		}

		//Updates terms
		previousTerms[0] = previousTerms[1];
		previousTerms[1] = currentTerm;
		currentTerm += previousTerms[0];
	}

	//prints answer to console
	cout << "The sum of all even-valued Fibonacci terms below " << max << " is " << sum << ".";

	cin.get();
    return 0;
}