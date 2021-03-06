// https://projecteuler.net/problem=6

#include "stdafx.h"
#include <iostream>
using namespace std;

static int upperBound = 100;

int main()
{
	int sumOfSquares = 0;
	int squareOfSum = 0;
	int difference = 0;

	//Calculates sum of all the squares
	for (int i = 1; i <= upperBound; i++) {
		sumOfSquares += i * i;
	}

	//Calculates square of sum
	squareOfSum = (upperBound * (upperBound + 1)) / 2;
	squareOfSum = squareOfSum * squareOfSum;

	difference = squareOfSum - sumOfSquares;

	//Prints reults
	cout << "The difference between the square of the sum of all numbers up to " << upperBound << " and the sum of all squares up to " << upperBound << " is " << difference;
	cin.get();
}

