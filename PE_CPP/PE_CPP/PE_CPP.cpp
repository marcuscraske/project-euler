/*
	File:	PE_CPP.cpp
	The menu and execution handler of solutions.

	Notes:
	***************************************************************************************************
	Add new solutions to Solutions.h and switch-statement in getSolution (within this source-file).
*/

#define EULER_PROBLEMS 397

#include "Solutions.h"
#include <iostream>
#include "Utils.h"
#include <time.h>
#include "SievePrimes.h"

using namespace std;

SBase*		getSolution(int problemNum);
void		getListOfSolutions();
void		handleSolutionExecution(SBase* solution);
void		executeAllSolutions();
void		primesTest();

int main()
{
	// Ask for solution number
	char input[3];
	int solutionNumber;
	SBase* solution;
	while(true)
	{
		cout << "Enter a problem number, '?' for a list of solutions, 'e' to execute every solution, 'p' for a primes test or 'q' to exit:" << endl;
		cin >> input;
		if(input[0] == 'q')
			break;
		else if(input[0] == '?')
			getListOfSolutions();
		else if(input[0] == 'e')
			executeAllSolutions();
		else if(input[0] == 'p')
			primesTest();
		else if((solutionNumber = Utils::atoi(input)) != 0)
		{
			// Fetch the solution object
			solution = getSolution(solutionNumber);
			if(solution == 0)
				cout << "Solution " << solutionNumber << " does not exist." << endl << endl;
			else
			{
				handleSolutionExecution(solution);
				delete solution; // Free the memory used by the solution
			}
		}
		else
			cout << "Invalid menu selection, try again." << endl << endl;
	}
	return 0;
}
void getListOfSolutions()
{
	SBase* solution = 0;
	int i = 1;
	while(i++ <= EULER_PROBLEMS)
	{
		solution = getSolution(i);
		if(solution != 0)
		{
			cout << "Problem #" << solution->problemNumber() << "\n" << solution->title() << "\n\n";
			delete solution;
		}
	}
}
void handleSolutionExecution(SBase* solution)
{
	cout << "Executing: Problem #" << solution->problemNumber() << endl << solution->title() << endl << "*************************************************************************" << endl;
	// Begin timer
	int begin = clock();
	// Execute solution
	solution->execute();
	// End timer
	int end = clock();
	cout << "Executed in " << (end - begin) << " ticks / " << ((double)(end - begin) / CLOCKS_PER_SEC) << " secs." << endl << endl;
}
SBase* getSolution(int problemNum)
{
	switch(problemNum)
	{
		case 1:
			return new Solution001();
		case 2:
			return new Solution002();
		case 3:
			return new Solution003();
		case 4:
			return new Solution004();
		case 18:
			return new Solution018();
		case 22:
			return new Solution022();
		case 23:
			return new Solution023();
		case 25:
			return new Solution025();
		case 28:
			return new Solution028();
		case 30:
			return new Solution030();
		case 34:
			return new Solution034();
		case 35:
			return new Solution035();
		case 36:
			return new Solution036();
		case 49:
			return new Solution049();
		case 50:
			return new Solution050();
		case 152:
			return new Solution152();
		default:
			return 0;
	}
}
void executeAllSolutions()
{
	SBase* solution = 0;
	int i = 1;
	int start = clock();
	int solutionsExecuted = 0;
	while(i++ <= EULER_PROBLEMS)
	{
		solution =getSolution(i);
		if(solution != 0)
		{
			cout << "Problem #" << solution->problemNumber() << "\n" << solution->title() << "\n\n";
			solution->execute();
			delete solution;
			solutionsExecuted++;
		}
	}
	int end = clock();
	cout << "Total of " << solutionsExecuted << " problems executed in " << (end - start) << " ticks (" << ((end - start) / (double)CLOCKS_PER_SEC) << " secs)" << endl << endl;
}
void primesTest()
{
	int upperBound = 30000000;//INT_MAX * 0.95;
	cout << "Finding primes within range of 1 to " << upperBound << "..." << endl;;
	int start = clock();
	SievePrimes sp(upperBound, true);
	int end = clock();
	cout << "Finished in " << (end - start) << " ticks (" << ((double)(end - start) / CLOCKS_PER_SEC) << " secs)!" << endl << endl;
	cout << "Safety test (range 1 to 120):" << endl;
	for(int i = 1; i <= 120; i++)
		if(sp.isPrime(i))
			cout << i << "\t";
	cout << endl << endl;
}