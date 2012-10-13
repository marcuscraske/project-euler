#pragma once
#include "Solution018.h"

int Solution018::problemNumber()
{
	return 18;
}
string Solution018::title()
{
	return "Find the maximum sum travelling from the top of the triangle to the base.";
}
void Solution018::execute()
{
	// Load the triangle from file
	try
	{
		FileData data = Utils::readFile("problem18_triangle.txt");
		// Read through the data to generate the size of the triangle
		long numberOfLines = 0;
		long columns = 0;
		char c;
		for(int i = 0; i < data.length; i++)
		{
			c = data.data[i];
			cout << c;
			if(c == '\n')
			{
				numberOfLines++;
				columns = 0;
			}
			else if(c == ' ')
				columns++;
		}
		cout << endl << endl << numberOfLines << "x" << columns << endl;
	}
	catch(exception ex)
	{
		cout << "Exception occurred: " << ex.what() << endl;
	}
}