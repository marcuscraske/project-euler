#pragma once
#include "Solution050.h"
#include "SolutionIncludes.h"
#include "SievePrimes.h"

int Solution050::problemNumber()
{
	return 50;
}
string Solution050::title()
{
	return "Prime with most consecutive primes under one-million.";
}
void Solution050::execute()
{
	long limit = 1000000;
	SievePrimes sp(limit, true);
	long maxTerms = 0, maxSum = 0;
	long terms, sum;
	for(int i = 2; i < limit; i++)
	{
		if(sp.isPrime(i))
		{
			terms = sum = 0;
			for(int j = i; j < limit; j++)
			{
				if(i == j || sp.isPrime(j))
				{
					if(sum + j > limit) break;
					sum += j;
					terms++;
				}
				if(sp.isPrime(sum) && terms > maxTerms)
				{
					maxSum = sum;
					maxTerms = terms;
				}
			}
		}
	}
	cout << "Answer: " << maxSum << ", with " << maxTerms << " terms" << endl;
}