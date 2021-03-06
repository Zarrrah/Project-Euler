//https://projecteuler.net/problem=4

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> digits;
int largestPaledrome;
int digitsInStartingValues = 3;


void breakIntoDigits(int x)
{
	if (x >= 10) 
	{
		breakIntoDigits(x / 10);
	}

	digits.push_back(x % 10);
}

bool isPaledromic(int x) 
{
	digits.clear();
	breakIntoDigits(x);
	for (int i = 0; i < digits.size() / 2; i++) 
	{
		if (!((digits[i]) == digits[(digits.size() - 1) - i])) 
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int firstNumber = (int)pow(10.0, digitsInStartingValues - 1);
	int finalNumber = (int)pow(10.0, digitsInStartingValues) - 1;

	for (int i = firstNumber; i <= finalNumber; i++) 
	{
		for (int j = firstNumber; j <= finalNumber; j++) 
		{
			largestPaledrome = (i*j > largestPaledrome && isPaledromic(i*j)) ? i * j : largestPaledrome;
		}
	}
	cout << largestPaledrome;
	cin.get();
    return 0;
}