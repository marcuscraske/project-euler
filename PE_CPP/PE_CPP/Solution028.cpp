#include "Solution028.h"

int Solution028::problemNumber()
{
	return 28;
}
string Solution028::title()
{
	return "Sum of diagonals in a 1001x1001 spiral matrix.";
}
void Solution028::execute()
{
	// sum				8			20     - 20/8 = 2.5 common ratio
	//                   4           4
	// nth diff		2  2  2  2   4  4   4   4           6   6   6   6
 	// n			1, 3, 5, 7, 9, 13, 17, 21, 25    31  37  43   49
	//				  |      24  |        76       |    160

	/*
	    2 2 2 2		4 4 4 4		6 6 6 6		8 8 8 8		10 10 10 10		12 12 12 12
		8			16			24			32			40				48
			8			8			8			8				8
	*/
	long long sideLength = 1001;
	long long limit = sideLength * sideLength;
	long long sum = 1;
	long add = 2;
	long cycle = 0;
	long num = 1;
	while(num < limit)
	{
		num += add;
		sum += num;
		//cout << num << endl;
		cycle++;
		if(cycle >= 4)
		{
			cycle = 0;
			add += 2;
		}
	}
	cout << "Answer: " << sum << endl;
}