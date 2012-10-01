#pragma once
#include "Solution004.h"
#include "SolutionIncludes.h"

int Solution004::problemNumber()
{
	return 4;
}
string Solution004::title()
{
	return "Largest palindrome from the product of two 3-digit numbers.";
}
void Solution004::execute()
{
	int answer = 0;
	int curr;
	for(int i = 999; i >= 100; i--)
	{
		for(int j = 999; j >= 100; j--)
		{
			if((curr = i * j) > answer && Utils::numberIsPalindrome(curr))
				answer = i * j;
		}
	}
	cout << "Answer: " << answer << endl;
}