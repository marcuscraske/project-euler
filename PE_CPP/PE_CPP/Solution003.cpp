#pragma once
#include "Solution003.h"
#include "SievePrimes.h"

int Solution003::problemNumber()
{
	return 3;
}
string Solution003::title()
{
	return "Find the largest prime factor of 600851475143.";
}
void Solution003::execute()
{
	const long long test = 0x43924903249324;
	const long long number = 600851475143;
	long maxRangeOfFactors = sqrt(number / 2.0);
	SievePrimes sp(maxRangeOfFactors, false); // We only need number / 2 of primes, since x * 2 will be largest factor possible
	sp.loadPrimes();
	// Now we'll check which number is the largest prime
	long answer = 0;
	long i = maxRangeOfFactors;
	while(answer == 0 && i-- > 2)
	{
		if(number % i == 0 && sp.isPrime(i))
			answer = i;
	}
	cout << "Answer: " << answer << endl;
}