#include <iostream>
#include <ctime>
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