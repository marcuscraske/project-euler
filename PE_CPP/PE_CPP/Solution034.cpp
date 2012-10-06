#pragma once
#include "Solution034.h"
#include "SolutionIncludes.h"

int Solution034::problemNumber()
{
	return 34;
}
string Solution034::title()
{
	return "Sum of numbers which are equal to the sum of their digits as factorials.";
}
void Solution034::execute()
{
	long sum = 0, *digits, secSum;
	for(int i = 3; i < 9999999; i++)
	{
		digits = Utils::getDigits(i);
		secSum = 0;
		for(int i = 1; i <= digits[0]; i++)
			secSum += Utils::getFactorial(digits[i]);
		if(secSum == i)
			sum += i;
		delete[] digits;
	}
	cout << "Answer: " << sum << endl;
}