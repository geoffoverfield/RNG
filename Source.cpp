//  Created by Geoffrey Overfield on Dec 9, 2015.

#include "RNG.h"
using namespace std;
int main()
{
	RNG<int> numbers;
	numbers.CreateRNG();
	numbers.Display();

	system("pause");
	return 0;
}