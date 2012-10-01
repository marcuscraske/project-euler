#pragma once
class SievePrimes
{
public:
	SievePrimes(long rangeEnd, bool preloadPrimes);
	~SievePrimes(void);
	bool SievePrimes::isPrime(long index);
	void SievePrimes::setIndex(long index, bool value);
	void SievePrimes::loadPrimes(void);
};