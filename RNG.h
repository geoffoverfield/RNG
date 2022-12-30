//  Created by Geoffrey Overfield on Dec 9, 2015.

#include <ctime>
#include <iostream>
using namespace std;

#ifndef RNG_H
#define RNG_H
template <class T>
class RNG
{
public:
	//modify array size as desired
	T rand1[index1][index2];
	T rand2[index1][index2];
	T rand3[index1][index2];

	void CreateRNG();
	void Display();
	bool DuplicatesExist();
	RNG();

    bool operator < (T &pnt)
    {
        if (this->x < pnt.x) return false;
        else return true;
    }
    
    bool operator == (T &pnt)
    {
        if (this->x == pnt.x) return false;
        else return true;
    }
    
    bool operator = (T &pnt)
    {
        if (this->x = pnt.x) return false;
        else return true;
    }
private:
    //modify with array sizes
	const int index1 = 5;
	const int index2 = 15;
	//edit % to set scope of random number
	const int randOf = 10e6;

};

/// <summary>
/// Populate the contents of our RND 2D arrays
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
void RNG<T>::CreateRNG()
{
	srand(time(NULL));
	for (int i = 0; i < index1; i++)
	{
		for (int j = 0; j < index2; j++)
		{
			rand1[i][j] = rand() % randOf;
			rand2[i][j] = rand() % randOf;
			rand3[i][j] = rand() % randOf;
		}
	}
}

/// <summary>
/// Displays the contents of the RNG 2D arrays
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
void RNG<T>::Display()
{
Display:
	int ans = 0;
	string output = "Contents of the {} array: " << endl << endl;
	cout << "Which array would you like to view?\nPlease enter 1, 2, or 3\nMake Your Selection Now:" << endl;
	cin >> ans;
	cout << endl;

	switch (ans)
	{
	case 1:
		cout << std::format(output, "first");
		for (int i = 0; i < index1; i++)
		{
			for (int j = 0; j < index2; j++)
			{
				cout << "Column: " << i << "\tRow: " << j << " " << rand1[i][j] << endl;
			}
		}
		break;
	case 2:
		cout << std::format(output, "second");
		for (int i = 0; i < index1; i++)
		{
			for (int j = 0; j < index2; j++)
			{
				cout << "Column: " << i << "\tRow: " << j << " " << rand2[i][j] << endl;
			}
		}
		break;
	case 3:
		cout << std::format(output, "third");
		for (int i = 0; i < index1; i++)
		{
			for (int j = 0; j < index2; j++)
			{
				cout << "Column: " << i << "\tRow: " << j << " " << rand3[i][j] << endl;
			}
		}
		break;
	default:
		cerr << "Please make a valid selection..." << endl;
		system("cls");
		goto Display;
		break;
	}
	
}

/// <summary>
/// Check to see if there are any duplicate indeces between the arrays
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <class T>
bool RNG<T>::DuplicatesExist()
{
	bool check = false;
	for (int i = 0; i < index1; i++)
	{
		for (int j = 0; j < index2; j++)
		{
			if (rand1[i][j] == rand2[i][j] || rand1[i][j] == rand3[i][j] || rand2[i][j] == rand3[i][j])
				check = true;
			else check = false;
		}
		
	}
	return check;
}

#endif