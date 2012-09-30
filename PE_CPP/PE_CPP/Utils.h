#pragma once
#include <string>
using namespace std;

#define GOLDEN_RATIO 1.6180339887

class Utils
{
public:
	static bool Utils::isNumeric(char data[]);
	static int	Utils::rand(int min, int max);
	static int Utils::atoi(char data[]);
	static bool Utils::tryParse(char data[], int* output);
	static long Utils::pow(long number, long exponent);
	static double Utils::pow(double number, double exponent);
	static double Utils::floor(double number);
	static double Utils::ceil(double number);
	static double Utils::round(double number);
	static double Utils::mod(double number, double multiple);
	static long Utils::getArithmeticSummation(long numberFirst, long numberLast, long n);
	static long Utils::getGeometricSummation(long firstNumber, long commonRatio, long numberOfElements);
};

