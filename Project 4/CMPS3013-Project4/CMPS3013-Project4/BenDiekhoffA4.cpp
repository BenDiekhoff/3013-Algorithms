
//***************************************************************
// Project #4 Median
// Name: Ben Diekhoff
// Data Structures and Algorithms
// Date: 04/01/2019
//***************************************************************
/*
This program inserts the numbers 1 - 1000 into a class that contains 2 
priority queues and an integer variable that hold the median. Then it extracts
the first 30 medians and prints their values, one per line.
						 COMPLEXITY
The complexity of this program in O(log(n)), unless you count the insertion 
of the numbers 1 - 1000, in which case the complexity is O(n).
The most complex methods in the program are push() and pop(), which are both
O(log(n)).

/*****************************************************************
 I have written the enitre program as turned in and have not copied this
code, or parts of this code from the internet or another student.
Signature______________________________________________
/******************************************************************/
#include <iostream>
#include "Median.h"

using namespace std;

int main() {
	Median m;
	
	// insert the numbers 1 through 1000.
	for (int i = 1; i <= 1000; i++)
		m.insert(i);
	
	// extract the median 30 times.
	for (int i = 0; i < 30; i++)
		m.extractMedian();

	system("pause");
	return 0;
}