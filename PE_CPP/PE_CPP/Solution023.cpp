#pragma once
#include "Solution023.h"
#include "SolutionIncludes.h"
#include <vector>

int Solution023::problemNumber()
{
	return 23;
}
string Solution023::title()
{
	return "Sum of positive integers which cannot be written as the sum of two abundant numbers.";
}
void Solution023::execute()
{
	long limit = 28123;
	// Generate abundant numbers - from 12 since it's the smallest
	vector<long> abundants;
	long* divisors;
	long long sum;
	for(long i = limit; i >= 2; i--)
	{
		sum = 0;
		divisors = Utils::getDivisors(i);
		for(int i = 1; i <= divisors[0]; i++)
			sum += divisors[i];
		if(sum > i)
			abundants.push_back(i);
		delete[] divisors;
	}
	cout << "Abundant numbers: " << abundants.size() << endl;
	// Go through each sum permutation and set a bool array corresponding to the answer
	bool * summable = new bool[limit + 1];
	for(int i = 0; i < limit + 1; i++) summable[i] = false;
	int index;
	for(int i = 0; i < abundants.size(); i++)
		for(int j = i; j < abundants.size(); j++)
		{
			index = abundants[i] + abundants[j];
			if(index <= limit)
				summable[index] = true;
		}
	// Go through bool array and sum the numbers which cannot derive from the sum of two abundant numbers
	sum = 0;
	for(int i = 1; i <= limit; i++)
	{
		if(!summable[i])
			sum += i;
	}
	cout << "Answer: " << sum << endl;
}