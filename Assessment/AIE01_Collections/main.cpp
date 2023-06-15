#include "LinkedList.h"
#include <iostream>

int Compare(LinkedList<int>::Iterator _a, LinkedList<int>::Iterator _b)
{

}

void main()
{
	LinkedList<int> myList;

	myList.Sort(&Compare);

	// TODO: Write your test code here
	for (auto iter = myList.Begin(); iter != myList.End(); ++iter)
	{

	}

}