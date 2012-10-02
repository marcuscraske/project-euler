#pragma once
#include "Solution002.h"

int Solution002::problemNumber()
{
	return 2;
}
string Solution002::title()
{
	return "Sum of even Fibonacci terms between one to four-million.";
}
void Solution002::execute()
{
	// Each third term in the fibonacci sequence is even and the common ratio between each common index is the golden ratio;
	// therefore we could use geometric series, but we don't know the last element - hence we'll generate terms until we hit over 4 million

	long currTerm = 2;
	long sum = 2;
	const int limit = 4000000;
	double ratio = Utils::pow(GOLDEN_RATIO, 3);
	while((currTerm = Utils::round(currTerm * ratio)) + sum < limit)
		sum += currTerm;
	cout << "Answer: " << sum << endl;
}