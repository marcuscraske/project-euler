/*
	File:	PE_CPP.cpp
	The menu and execution handler of solutions.

	Notes:
	***************************************************************************************************
	Add new solutions to Solutions.h and switch-statement in getSolution (within this source-file).
*/

#include "Solutions.h"
#include <iostream>
#include "Utils.h"
#include <time.h>

using namespace std;

SBase*		getSolution(int problemNum);
void		getListOfSolutions();
void		handleSolutionExecution(SBase* solution);
void		executeAllSolutions();

int main()
{
	// Ask for solution number
	char input[3];
	int solutionNumber;
	SBase* solution;
	while(true)
	{
		cout << "Enter a problem number, '?' for a list of solutions, 'e' to execute every solution or 'q' to exit:" << endl;
		cin >> input;
		if(input[0] == 'q')
			break;
		else if(input[0] == '?')
			getListOfSolutions();
		else if(input[0] == 'e')
			executeAllSolutions();
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
	while((solution = getSolution(i)) != 0 && (i++) < INT_MAX)
	{
		cout << "Problem #" << solution->problemNumber() << "\n" << solution->title() << "\n\n";
		delete solution;
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
		case 5:
			return new Solution005();
		default:
			return 0;
	}
}
void executeAllSolutions()
{
	SBase* solution = 0;
	int i = 1;
	int start = clock();
	while((solution = getSolution(i)) != 0 && (i++) < INT_MAX)
	{
		cout << "Problem #" << solution->problemNumber() << "\n" << solution->title() << "\n\n";
		solution->execute();
		delete solution;
	}
	int end = clock();
	cout << "Total of " << --i << " problems executed in " << (end - start) << " ticks (" << ((end - start) / (double)CLOCKS_PER_SEC) << " secs)" << endl << endl;
}