#pragma once
#include "Solution035.h"
#include "SolutionIncludes.h"
#include "SievePrimes.h"
#include <vector>
#include <algorithm>

int Solution035::problemNumber()
{
	return 35;
}
string Solution035::title()
{
	return "Number of circular primes below one million.";
}
void Solution035::execute()
{
	int limit = 1000000;
	SievePrimes sp(limit * 10, true);
	long cPrimes = 0;
	long* digits;
	long num;
	long endElement;
	bool nonPrimeFound;
	// We will cache pre-existing circulars to speed-up the process
	vector<long> circulars;
	vector<long> iterations;
	// Begin iterating up to the limit for primes and check if each prime is circular
	for(int i = 2; i < limit; i++)
	{
		if(sp.isPrime(i) && find(circulars.begin(), circulars.end(), i) == circulars.end())
		{
			if(i < 10) cPrimes++;
			else
			{
				// We need to get the digits and make every permutation of the number
				// and check if it's a prime
				digits = Utils::getDigits(i);
				// Check if the digits have been moved around; if so, we need to check it's prime
				nonPrimeFound = false;
				iterations.clear();
				do
				{
					// Shift the elements to the right by one
					endElement = digits[digits[0]];
					for(int i = digits[0] - 1; i > 0; i--)
						digits[i + 1] = digits[i];
					digits[1] = endElement;
					// Sum the digits
					num = 0;
					for(int i = 1; i <= digits[0]; i++)
						num = (num * 10) + digits[i];
					// Add the iteration to the list
					iterations.push_back(num);
					// Check the number is prime
					if(!sp.isPrime(num))
						break;
				}
				while(num != i);
				if(num == i)
				{
					// Add all the iterations found (since they too are circular)
					cPrimes += iterations.size();
					// Add the iterations to the circular cache
					circulars.insert(circulars.end(), iterations.begin(), iterations.end());
				}
				delete[] digits;
			}
		}
	}
	cout << "Answer: " << cPrimes << endl;
}