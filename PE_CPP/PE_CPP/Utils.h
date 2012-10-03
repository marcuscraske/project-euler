#pragma once
#include <string>
using namespace std;

/*
	The Golden Ratio number (constant), also known as Phidias or Phi; more information:
	http://en.wikipedia.org/wiki/Golden_ratio
*/
#define GOLDEN_RATIO 1.61803398875

/*
	Pi number (constant); more information:
	http://en.wikipedia.org/wiki/Pi
*/
#define PI 3.14159265359

class Utils
{
public:
	static bool Utils::isNumeric(char data[]);
	static int	Utils::rand(int min, int max);
	static int Utils::atoi(char data[]);
	static bool Utils::tryParse(char data[], int* output);
	static long Utils::pow(long number, long exponent);
	static double Utils::round(double number);
	static long Utils::getArithmeticSummation(long numberFirst, long numberLast, long n);
	static double Utils::getGeometricSummation(double firstNumber, double commonRatio, double numberOfElements);
	static bool Utils::numberIsPalindrome(int value);
};