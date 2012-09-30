#include "Utils.h"
#include <string>
#include <math.h>

using namespace std;

bool Utils::isNumeric(char data[])
{
	for(int i = 0; i < sizeof(data) - 1; i++) // We ignore the last element because it's the end of sequence char
		if(!isdigit(data[i])) return false;
	return true;
}
int Utils::rand(int min, int max)
{
	if(min >= max) return 0;
	max -= min; // If our max is 600 and min is 400 and we add min later, we only want to generate a number between 0 to 200 (since +min/+400) will be 600
	return min + (std::rand() % (max + 1)); // max % max = 0, therefore we do max + 1
}
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
double Utils::pow(double number, double exponent)
{
	return powf(number, exponent);
}
double Utils::floor(double number)
{
	return floorf(number);
}
double Utils::ceil(double number)
{
	return ceilf(number);
}
double Utils::mod(double number, double multiple)
{
	return number * (number - floor(number / multiple));
}
double Utils::round(double number)
{
	double nFloor;
	double mantissa = number - (nFloor = floor(number));
	if(mantissa > 0.5)
		return nFloor + 1;
	else
		return nFloor;
}
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
long Utils::getGeometricSummation(long firstNumber, long commonRatio, long numberOfElements)
{
	return firstNumber * (
		(1 - pow(commonRatio, numberOfElements))
		/
		(1 - commonRatio)
		);
}
