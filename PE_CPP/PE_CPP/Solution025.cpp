#include "Solution025.h"

int Solution025::problemNumber()
{
	return 25;
}
string Solution025::title()
{
	return "First term with 1000 digits in the Fibonacci sequence.";
}
void Solution025::execute()
{
	int digits = 4;
	// Credit: 999+log(sqrt(5)))/log(phi) +1   ~thomasantony (India)
	double answer = (( (pow(10.0, digits - 1) - 1) + log10(sqrt(5.0))) / log10(GOLDEN_RATIO)) + 1;
	cout << "Answer: " << floor(answer) << endl;
}