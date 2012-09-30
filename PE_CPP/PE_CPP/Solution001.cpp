#include "SolutionIncludes.h"
#include "Solution001.h"

using namespace std;

int Solution001::problemNumber()
{
	return 1;
}
string Solution001::title()
{
	return "Sum of natural numbers divisible by 3 and 5.";
}
void Solution001::execute()
{
	// Get total of arithmetic series for 3, 5 and 15
	long sumOfThree = Utils::getArithmeticSummation(3, 999, 3);
	long sumOfFive = Utils::getArithmeticSummation(5, 999, 5);
	long sumOfFifteen = Utils::getArithmeticSummation(15, 999, 15);
	// Answer (series of 3 and 5 added together with 15 subtracted since the series of 3 and 5 both have the same numbers - multiples of 15)
	cout << "Answer: " << (sumOfThree + sumOfFive - sumOfFifteen) << endl;
}