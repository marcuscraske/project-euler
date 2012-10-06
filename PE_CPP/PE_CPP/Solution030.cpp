#pragma once
#include "Solution030.h"
#include "SolutionIncludes.h"

int Solution030::problemNumber()
{
	return 30;
}
string Solution030::title()
{
	return "Sum of all numbers that can be written as the sum of their digits as fifth powers.";
}
void Solution030::execute()
{
	long exponent = 5;
	long sum;
	// Generate a cache of the fourth powers
	int powers[10];
	for(int i = 0; i < 10; i++)
		powers[i] = Utils::pow(i, exponent);
	// Get the upper bound
	long boundUpper = 0;
	for(int i = 0; i < exponent - 1; i++)
		boundUpper += powers[9];
	cout << "Upper-bound: " << boundUpper << endl;
	// Begin
	sum = 0;
	long *digits, secSum;
	for(long i = 2; i <= boundUpper; i++)
	{
		// Sum the number's digits
		digits = Utils::getDigits(i);
		secSum = 0;
		for(int j = 1; j <= digits[0]; j++)
			secSum += powers[digits[j]];
		if(secSum == i)
		{
			cout << "Found " << i << endl;
			sum += i;
		}
	}
	cout << "Answer: " << sum << endl;
}