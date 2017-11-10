//============================================================================
// Name        : L7_Practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int hashh(string key, int size );

int main() {
	string key;
	cin >> key;
	cout << hashh(key, 5);
	return 0;
}

int hashh(string key, int size )
{
	int sum = 0;
	int index = 0;
	for (unsigned int i = 0; i <key.length();i++)
	{
		sum += (int)key[i];

	}
	index = sum % sum;
	return index;
}


