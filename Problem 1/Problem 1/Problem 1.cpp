//https://projecteuler.net/problem=1

#include "stdafx.h"
#include <iostream>
using namespace std;

#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
	const int max = 1000;
	const int denominator[] = { 3, 5 };
	const int sizeOfArray = my_sizeof(denominator) / my_sizeof(denominator[0]);

	int sum = 0;
	bool divisible = false;

	//Does the calculations through iteration of the values
	for (int i = 0; i < max; i++) 
	{
		int j = 0;
		while (j < sizeOfArray && divisible == false)
		{
			if (i % denominator[j] == 0) 
			{
				sum += i;
				divisible = true;
			}
			else 
			{
				j++;
			}
		}
		divisible = false;
	}

	//Prints answer to console
	cout << "The sum of all multiples of ";
	for (int i = 0; i < (sizeOfArray - 1); i++) 
	{
		cout << denominator[i] << " or ";
	}
	cout << denominator[sizeOfArray - 1] << " below " << max << " is " << sum << ".";

	cin.get();
	return 0;
}

