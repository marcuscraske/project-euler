#pragma once
#include "Solution036.h"
#include "SolutionIncludes.h"

int Solution036::problemNumber()
{
	return 36;
}
string Solution036::title()
{
	return "Base 10 and 2 palindromes below one million.";
}
void Solution036::execute()
{
	long limit = 1000000;
	long sum = 0;
	for(long i = 1; i < limit; i++)
		if(Utils::numberIsPalindrome(i) && Utils::numberIsPalindromeBase(i, 2))
			sum += i;
	cout << "Answer: " << sum << endl;
}