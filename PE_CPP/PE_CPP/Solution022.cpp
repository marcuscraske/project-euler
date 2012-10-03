#pragma once
#include "Solution022.h"
#include "SolutionIncludes.h"
#include <stdio.h>

int Solution022::problemNumber()
{
	return 22;
}
string Solution022::title()
{
	return "Total score of ordered names from a file.";
}
void Solution022::execute()
{
	FILE* nFile = fopen("names.txt", "r");
	if(nFile == 0)
	{
		cout << "names.txt file not found - cannot continue solution!";
		return;
	}
	char fileBuffer[47000];
	while(!feof(nFile))
	{
		fgets(fileBuffer, 100, nFile);
	}
	fclose(nFile);
	cout << fileBuffer << endl;
}