#pragma once
#include "Solution022.h"
#include "SolutionIncludes.h"
#include <stdio.h>
#include <vector>

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
	FileData data = Utils::readFile("names.txt");
	vector<string> names;
	// Iterate through the data and add each name to the array
	int inStart = -1, inEnd = -1;
	char c;
	char* nameBuffer;
	int nameLength;
	for(int i = 0; i < data.length; i++)
	{
		c = data.data[i];
		// Check if the char is a starting/ending point
		if(c == '"')
		{
			if(inStart == -1)
				inStart = i;
			else
			{
				inEnd = i;
				// Process chars into a string and add to the array
				nameLength = inEnd - inStart - 1;
				nameBuffer = new char[nameLength];
				for(int j = 0; j < nameLength; j++)
					nameBuffer[j] = data.data[j + inStart + 1];
				string s(nameBuffer, nameLength);
				names.push_back(s);
				delete nameBuffer;
				// Reset index points
				inStart = inEnd = -1;
			}
		}
	}
	// Sort the names alphabetically using selection-sort; this is slow and needs improvement
	string nameCurr;
	string nameI;
	int smallestIndex;
	for(int i = 0; i < names.size(); i++)
	{
		smallestIndex = -1;
		nameCurr = names[i];
		for(int j = i + 1; j < names.size(); j++)
		{
			nameI = names[j];
			if(nameCurr.compare(nameI) != -1 && (smallestIndex == -1 || nameI.compare(names[smallestIndex]) == -1) )
				smallestIndex = j;
		}
		if(smallestIndex != -1)
		{
			names[i] = names[smallestIndex];
			names[smallestIndex] = nameCurr;
		}
	}
	// Go through each name and generate the sum
	long long sum = 0;
	long long relSum;
	string name;
	for(int i = 0; i < names.size(); i++)
	{
		relSum = 0;
		name = names[i];
		for(int j = 0; j < name.length(); j++)
			relSum += name[j] - 64; // 64 due to A starting at 65 ASCII (char), hence 65-64 for A would yield 1
		relSum *= i + 1;
		sum += relSum;
	}
	cout << "Answer: " << sum << " with " << names.size() << " names" << endl;
}