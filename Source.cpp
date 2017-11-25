// LabListRandom
// CSC 2430 Lab Assignment
// Written by: Hector Dominguez-Maceda
// Date: May 25th, 2016

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <limits>
using namespace std;

#include "SortedLabListP.h"
#include "LabListP.h"

void printListClass(char listname[], const ListClass& lst)
{
	cout << listname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

void printListClass(char sortedlistname[], const SortedListClass& lst)
{
	cout << sortedlistname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

int main()
{
	/////////////////////////////////////////////////
	// setup
	const int N = 10;			// number of items, used only to create initial list of values
	const int RANGE = 1001;		// value range. Set to INT_MAX for a list of values from 0 .. 32767

	// Prepare random number generator with initial seed value
	//    and discard the first few data items in the sequence
	srand(1);
	for (int i = 0; i < 10; ++i)
		rand();

	// Greeting
	cout << "Linked List Lab: Implemented by Hector Dominguez-Maceda" << endl;
	cout << "Randomly generate list of " << N << " values in range 0-" << RANGE - 1 <<
		" and convert into a sorted list" << endl << endl;

	/////////////////////////////////////////////////
	// Create initial "by position" data value list
	ListClass listbyposition;
	SortedListClass listByValue;

	for (int i = 1; i <= N; ++i)
	{
		int val = rand() % RANGE;		// produce next random number value
		listbyposition.insert(i, val);  // Put val into list at position i
		listByValue.insert(val);
	}

	// Output initial data list
	printListClass("listbyposition", listbyposition);

	system("pause");
	/////////////////////////////////////////////////
	


	printListClass("sortedlist", listByValue);

	return(0);
}