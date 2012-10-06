#pragma once
#include "Solution049.h"
#include "SolutionIncludes.h"
#include "SievePrimes.h"

int Solution049::problemNumber()
{
	return 49;
}
string Solution049::title()
{
	return "Finding the arithmetic sequence with three four-digit prime and permutated numbers.";
}
void Solution049::execute()
{
	SievePrimes s(9999, true);
	// Go through each possible sequence
	bool found = false;
	long a = 1489, b = 0, c = 0;
	while(!found && a < 10000 && b < 10000 && c < 10000)
	{
		b = a + 3330;
		c = a + 6660;
		if(s.isPrime(a) && s.isPrime(b) && s.isPrime(c) && Utils::isPermutation(a, b, false) && Utils::isPermutation(b, c, false))
		{
			cout << "Answer: " << a << b << c << endl;
			found = true;
		}
		a += 2; // We'll try each odd number
	}
	if(!found)
		cout << "Answer: (not found) ;_;" << endl;
}