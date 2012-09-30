#include "SBase.h"
#include <string>
#include <iostream>
using namespace std;

int SBase::problemNumber()
{
	return 0;
}
string SBase::title()
{
	return "Unknown solution";
}
void SBase::execute()
{
	cerr << "No statements to be executed; execute method is undefined.";
}