#include <vector>
#include <iostream>
#include <math.h>
#include "SievePrimes.h"
using namespace std;

unsigned char *chunks;
long rangeEnd;
long numChunks;

#define SIEVE_RANGE_START 3

/*
	This class is used to create a cache of prime numbers from 0 to n;
	this should be a lot faster than using mod techniques for large checking
	of primes.

	This works by having an array of unsigned chars, which each char consisting
	of a byte - without a sign; therefore this pretty much acts as a byte. Then
	when this class is created, we fill a vector called "chunks", with each chunk
	being an unsigned character. Using bitwise operators, we can store a boolean
	indicating if a number is a prime at each bit of a series of chunks. Hence:

	Chunk:	|	0			|	1				  |	2					  | n
	Number:	|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23| ...
	Value:  |0|0|0|0|1|0|1|0|1|1|1 |0 |1 |0 |1 |1 |1 |0 |1 |0 |1 |1 |1 |0

	As you can notice, by default all numbers are prime (since a new unsigned
	char is 00000000 or 0; hence the member function "loadPrimes" will set all
	the indexes of the non-primes to 1.

	The number of chunks is:
	ceiling(rangeEnd / 8) + 1

	Edit:
	This no longer stores even numbers.
*/

SievePrimes::SievePrimes(long _rangeEnd, bool preloadPrimes)
{
	rangeEnd = _rangeEnd;
	numChunks = ceil((double)rangeEnd / 16.0) + 1; // We add one because of index zero
	chunks = new unsigned char[numChunks];
	// Initialize each element to zero
	for(int i = 0; i < numChunks; i++)
		chunks[i] = 0;
	// Check if to load the primes
	if(preloadPrimes)
		loadPrimes();
}
SievePrimes::~SievePrimes(void)
{
	delete[] chunks;
}
void SievePrimes::loadPrimes(void)
{
	long limit = sqrt((double)rangeEnd);
	// Go from 2 to rangeEnd, setting each multiple of i to true/prime - but only if the index of i has not been set
	for(long i = SIEVE_RANGE_START; i <= limit; i++)
	{
		if(isPrime(i))
			for(long j = i + i; j <= rangeEnd; j += i)
				if(j % 2 != 0)
					setIndex(j, false);
	}
}
const int indexCache[8] = { 1, 2, 4, 8, 16, 32, 64, 128};
bool SievePrimes::isPrime(long index)
{
	if(index != 2 && index % 2 == 0)
		return false;
	else if(index != 3 && index % 3 == 0)
		return false;
	else if(index != 5 && index % 5 == 0)
		return false;
	long relIndex = (index + 1) / 2;
	long chunkIndex = floor(relIndex / 8.0);
	// Get the bit at the specified column and bitwise AND the flipped chunk; if a one exists at the column, the expression will return true (hence prime)
	return ~chunks[chunkIndex] & indexCache[relIndex % 8];
}
void SievePrimes::setIndex(long index, bool value)
{
	//cout << index << "," << ((index / 2) + 1) << endl;
	long relIndex = (index + 1) / 2;
	long chunkIndex = floor(relIndex / 8.0);
	unsigned char chunk = chunks[chunkIndex];
	// If we are setting a prime i.e. a bit to zero, we will flip each bit (we wil re-flip it later)
	if(value)
		chunk = (~chunk);
	// Now we will grab the pre-cached value with 1 at the specified column, OR it and cause the chunk to have the bit at the column set to one
	chunk |= indexCache[relIndex % 8];
	// Flip the char back if we flipped it earlier
	if(value)
		chunk = (~chunk);
	// Set the new value of the chunk
	chunks[chunkIndex] = chunk;
}