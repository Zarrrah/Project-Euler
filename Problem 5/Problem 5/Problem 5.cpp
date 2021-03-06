// https://projecteuler.net/problem=5

#include "stdafx.h"
#include <iostream>
using namespace std;

int64_t args[2] = { 200, 205 };

bool isDivisible(int64_t x)
{
	for(int64_t i = args[0]; i <= args[1]; i++)
	{
		if (x % i != 0LL) 
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int64_t x = 0LL;
	while (!isDivisible(x = args[0] + x));
	cout << x;
	cin.get();
    return 0;
}