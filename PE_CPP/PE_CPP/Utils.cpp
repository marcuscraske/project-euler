#pragma once
#include "Utils.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

FileData::FileData(char* _data, int _length)
{
	data = _data;
	length = _length;
}
FileData::~FileData()
{
	delete data;
}
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
	long long elementLast = numberLast - (((numberLast - numberFirst) + n) % n);
	long long numberOfElements = 1 + ((elementLast - numberFirst) / n);

	return (numberOfElements * numberFirst) +
		(
			(
			(numberOfElements * (numberOfElements - 1L))
			/
			(2L)
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
double Utils::getGeometricSummation(double firstNumber, double commonRatio, double numberOfElements)
{
	return firstNumber * (
		(1.0 - pow(commonRatio, numberOfElements))
		/
		(1.0 - commonRatio)
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
		r = r * 10 + (value % 10); // Fetch the right most char
		value /= 10; // Int should always round down
	}
	return r == o;
}
/*
	The same as the function "numberIsPalindrome" with support
	for additional bases.
*/
bool Utils::numberIsPalindromeBase(long value, long base)
{
	long o = value, r = 0;
	while(value > 0)
	{
		r = r * base + (value % base);
		value /= base;
	}
	return r == o;
}
/*
	Returns the length, or the number of digits, of the
	provided number.
*/
long Utils::getDigitCount(long value)
{
	long count = 0;
	while(value > 0)
	{
		value /= 10;
		count++;
	}
	return count;
}
/*
	Returns the length, or number of digits, in a number.
*/
long Utils::getDigitsLength(long value)
{
	int dLength = 0;
	while(value > 0)
	{
		value /= 10;
		dLength++;
	}
	return dLength;
}
/*
	Converts a number into an array of digits; returned is a
	pointer to the array - remember to delete it! This has no
	protection and will cause errors if value is less than one.

	The first element states the number of digits in the array.
*/
long* Utils::getDigits(long value)
{
	// Our first run will get the length of the array required/number of digits
	int dLength = 0;
	long cVal = value;
	while(cVal > 0)
	{
		cVal /= 10;
		dLength++;
	}
	// Begin copying the digits to the array
	long* arr = new long[dLength + 1];
	arr[0] = dLength; // We set the first element to the size of the array
	cVal = 0; // This will be our index counter now
	while(value > 0)
	{
		arr[dLength - cVal] = value % 10;
		cVal++;
		value /= 10;
	}
	return arr;
}
/*
	Similar to getDigits, but with sorted elements.
*/
long* Utils::getSortedDigits(long value)
{
	long* arr = Utils::getDigits(value);
	// Use selection sort to sort the digits from 0 to n ordering; this is not
	// wonderfully fast, but our arrays wont be huge
	int smallestIndex;
	long currItem;
	for(int i = 1; i < arr[0]; i++)
	{
		currItem = arr[i];
		smallestIndex = -1;
		for(int j = i + 1; j <= arr[0]; j++)
			if(arr[j] < currItem)
				smallestIndex = j;
		if(smallestIndex != -1)
		{
			arr[i] = arr[smallestIndex];
			arr[smallestIndex] = currItem;
		}
	}
	return arr;
}
/*
	Used to get the number from a digits array passed by the function
	getSortedDigits.
*/
long Utils::getDigitsNumber(long* value)
{
	long number = 0;
	for(int i = 1; i <= value[0]; i++)
	{
		number *= 10;
		number += value[i];
	}
	return number;
}
/*
	Sorts the specified number's digits.
*/
long Utils::getSortedNumber(long value)
{
	long* arr = Utils::getSortedDigits(value);
	value = Utils::getDigitsNumber(arr);
	delete[] arr;
	return value;
}
/*
	Checks if the two numbers are permutations of each other.

	Absolute: if false, any permutation is allowed; if true,
	permutation must be circular.
*/
bool Utils::isPermutation(long value1, long value2, bool absolute)
{
	long* arr;
	if(absolute)
		arr = Utils::getDigits(value2);
	else
	{
		arr = Utils::getSortedDigits(value2);
		value1 = Utils::getSortedNumber(value1);
	}
	bool isPermutation = false;
	long switchElement;
	for(int i = 0; i < arr[0] && !isPermutation; i++)
	{
		switchElement = arr[1];
		for(int k = 2; k <= arr[0]; k++)
			arr[k - 1] = arr[k];
		arr[arr[0]] = switchElement;
		if(Utils::getDigitsNumber(arr) == value1)
			isPermutation = true;
	}
	delete[] arr;
	return isPermutation;
}
/*
	Reads a file and returns a pointer to a char-array to the associated data;
	remember to delete the pointer to the data once finished!
*/
FileData Utils::readFile(string path)
{
	FILE* nFile = fopen("names.txt", "r");
	if(nFile == 0)
		throw new exception("File cannot be accessed!");
	// Skip to the end of the file
	fseek(nFile, 0L, SEEK_END);
	// Gets the position of the end of the file - our length
	long length = ftell(nFile);
	// Create buffer
	char* dataBuffer = new char[length];
	if(dataBuffer == 0)
		throw new exception("Insufficient memory to read file!");
	// Go back to the start of the file
	rewind(nFile);
	// Read the data into our buffer
	if(fread(dataBuffer, length, 1, nFile) != 1)
		throw new exception("Error reading data from file!");
	fclose(nFile);
	return FileData(dataBuffer, length);
}
/*
	Returns an array of divisors of the provided value;
	the first element states the number of elements in the
	array.
*/
long* Utils::getDivisors(long value)
{
	vector<long> divisors;
	divisors.push_back(1);
	for(long i = 2; i <= value / 2; i++)
	{
		if(value % i == 0)
			divisors.push_back(i);
	}
	long* arr = new long[divisors.size() + 1];
	arr[0] = divisors.size();
	for(int i = 1; i <= divisors.size(); i++)
		arr[i] = divisors[i - 1];
	return arr;
}
long Utils::getFactorial(long number)
{
	long sum = 1;
	while(number > 0)
	{
		sum *= number;
		number--;
	}
	return sum;
}