#pragma once
#include "Solution152.h"
#include "SolutionIncludes.h"

int Solution152::problemNumber()
{
	return 152;
}
string Solution152::title()
{
	return "How many ways are there to write the number 1/2 as a sum of inverse squares using distinct integers between 2 and 80 inclusive?";
}
void Solution152::execute()
{
	int expMin = 2;
	int expMax = 80;
	// Generate cache of fractions
	double* fractCache = new double[expMax];
	double val;
	for(double i = expMin; i <= expMax; i++)
	{
		val = 1.0 / pow(i, 2.0);
		cout << val << endl;
		fractCache[(int)i] = val;
		cout << i << "\t" << fractCache[(int)i] << endl;
	}



	// Clean-up
	//delete fractCache; -- throws runtime-error
}