#include "Utils.h"
#include <string>
#include <math.h>

using namespace std;

/*
	Checks the specified data consists of numeric characters; this does not check the value
	will parse as a number.
*/
bool Utils::isNumeric(char data[])
{
	for(int i = 0; i < sizeof(data) - 1; i++) // We ignore the last element because it's the end of sequence char
		if(!isdigit(data[i])) return false;
	return true;
}
/*
	Generates a random number between a range.
*/
int Utils::rand(int min, int max)
{
	if(min >= max) return 0;
	max -= min; // If our max is 600 and min is 400 and we add min later, we only want to generate a number between 0 to 200 (since +min/+400) will be 600
	return min + (std::rand() % (max + 1)); // max % max = 0, therefore we do max + 1
}
/*
	Converts a char-array to a number; this assumes the input has been validated.
*/
int Utils::atoi(char data[])
{
	int number = 0;
	for(int i = 0; data[i] >= '0' && data[i] <= '9'; i++)
	{
		if(data[i] < '0' && data[i] > '9') return 0; // Invalid char
		number = number * 10 + (data[i] - '0');
	}
	return number;
}
/*
	Attempts to parse character data and returns a boolean, indicating if the operation
	was successful or not.
*/
bool Utils::tryParse(char data[], int* output)
{
	if(sizeof(data) < 2) return false; // No data
	// Go through each index, try to parse it until we reach the end/non-numeric char
	int i = 0, number = 0;
	while(data[i] >= '0' && data[i] <= '9')
	{
		number = number * 10 + (data[i] - '0');
		i++;
	}
	// Check the last index was the end of sequence/null char, else it was an invalid char and hence invalid
	*output = number;
	return data[i] == '\0';
}
/*
	Calculates the exponential of a number.
*/
long Utils::pow(long number, long exponent)
{
	if(exponent == 0)
		return 1;
	else if(exponent == 1)
		return number;

	long halfExp = Utils::pow(number, exponent / 2);
	if(exponent % 2 == 0)
		return halfExp * halfExp;
	return number * halfExp * halfExp;
}
/*
	Rounds a double up or down, removing the mantissa.
*/
double Utils::round(double number)
{
	double nFloor;
	double mantissa = number - (nFloor = floor(number));
	if(mantissa > 0.5)
		return nFloor + 1;
	else
		return nFloor;
}
/*
	Gets the summation of an arithmetic sequence between two ranges. The numberLast
	parameter does not need to be a multiple in the sequence; instead the closest
	multiple before it will be used.
*/
long Utils::getArithmeticSummation(long numberFirst, long numberLast, long n)
{
	long elementLast = numberLast - (((numberLast - numberFirst) + n) % n);
	long numberOfElements = 1 + ((elementLast - numberFirst) / n);

	return (numberOfElements * numberFirst) +
		(
			(
			(numberOfElements * (numberOfElements - 1))
			/
			(2)
			)
			* n
		);
}
/*
	Gets the summation of a geometric series.

	Parameters:
	First number		- the first number in the sequence.
	Common ratio		- term 2 / term 1 = common ratio i.e. 3 6 12 24, 6 / 3 = 2
	Number of elements	- the number of elements in the sequence to sum.
*/
long Utils::getGeometricSummation(long firstNumber, long commonRatio, long numberOfElements)
{
	return firstNumber * (
		(1 - pow(commonRatio, numberOfElements))
		/
		(1 - commonRatio)
		);
}
/*
	Checks a numer is a palindrome; a palindrome is a number
	that reads the same when reversed.
*/
bool Utils::numberIsPalindrome(int value)
{
	int r = 0, o = value; // r = reversed, o = original
	while(value > 0)
	{
		r = r*10 + (value % 10); // Fetch the right most char
		value = value / 10; // Int should always round down
	}
	return r == o;
}