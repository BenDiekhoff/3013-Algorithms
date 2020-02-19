/* NOTE: PROJECT> PROPERTIES > CONFIGURATION PROPERTIES > DEBUGGING
	> COMMAND ARGUMENTS > REMOVE '<INPUT.TXT' TO NOT READ FROM CIN */


//************************************************************** 
// Project #1 Practice with Vectors 
// Name: Ben Diekhoff
// Data Structures and Algorithms 
// Date: 01/28/2019 
//*************************************************************** 
// This program takes several numbers as input. The first line determines the
// number of cases to be solved. Each case has 3 lines, one for each friend.
// The first number of each line states how many problems each friend solved,
// and thus how many numbers will be read in for that friend. The following
// numbers are the problems that particular friend solved.
// 
// The program reads the relevant data  into 3 vectors, compares the data in 
// each vector to the data in another, and only keeps the data that is unique
// to a single friend. Then it checks each vector to make sure that there are
// no duplicate entries (i.e. friend 1 solved problem 3 twice, etc.). Then,
// for each case, it prints the friend who solved the most problems, the 
// number of problems he solved, and his unique problems. In the case of a 
// tie, it prints this information for every friend who tied.
//
//					COMPLEXITY
// The most complex function of this program is O(N^2) complexity. 
// However, every function is called every time a new test case is read in.
// Since reading in the test cases is O (N), The worst case complexity is
// O (T * (N^2)), where T is the number of test cases.
 
//***************************************************************** 
/* I have written the enitre program as turned in and have not copied this 
code, or parts of this code from the internet or another student.

Signature______________________________________________*/

//******************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void loadVects(vector<int> &, vector<int> &, vector<int> &);
void removeDupes(vector<int> &, vector<int> &, vector<int> &);
void printVects(vector<int> &, vector<int> &, vector<int> &);



//******************************************************************* 
// main() 
// Parameters: none
// Complexity: O(N) 
// 
// Reads in the total number of cases and loops that amount of times, calling
// functions to read in the information, process it, and print it out. This 
// function has a single for loop, so its complexity is O(N).
//********************************************************************
int main() {
	vector<int> f1, f2, f3;  //f1, f2, f3 holds the problems for friends, 1,
							// 2, and 3, respectively
	
	int numCases;			//numCases holds the number of Cases to be read in

	cin >> numCases;

	for (int i = 0; i < numCases; i++) {
		cout << "Case #" << i + 1 << ":" << endl;

		loadVects(f1, f2, f3);
		removeDupes(f1, f2, f3);
		printVects(f1, f2, f3);
	}

	return 0;
}


//******************************************************************* 
// loadVects() 
// Parameters: 3 vectors of ints, passed by reference.
// Complexity: O(N) 
// 
// This function reads in the number of problems for a particular friend,
// and pushes the problems the friends solved to their own vectors. After all
// the vectors are loaded, it sorts the contents of each vector in numerical
// order.
// The parameters in this function are passed by reference, so they are
// modified directly and it doesn't need to return anything.
//
// This function has multiple for loops that are not nested, so its complexity
// is O(N).
//********************************************************************
void loadVects(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
	
	int tmp, numProbs;  // numProbs holds the number of problems to read in
						// for each friend

	cin >> numProbs;
	for (int i = 0; i < numProbs; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}


	cin >> numProbs;
	for (int i = 0; i < numProbs; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}


	cin >> numProbs;
	for (int i = 0; i < numProbs; i++) {
		cin >> tmp;
		v3.push_back(tmp);
	}

	// Sorts the vectors
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
}


//******************************************************************* 
// removeDupes()
// Parameters: 3 vectors of ints, passed by reference
// Complexity: O(N^2) 
// 
// This function creates 3 vectors to hold the unique problems each
// friend solved. First, it makes sure that the sorted vectors it has been 
// passed are not holding any duplicate data, for example, if friend 1 has
// solved problem 3 five times, it will remove all but one instance of problem
// 3. Then, it resizes the vectors based on the distance from the first 
// element of the vector to the element pointed to by the iterator after using
// unique() function.
// Next, it compares each element in a vector to the elements in both other
// vectors. Any unique elements are pushed to a vector of ints whose purpose
// is to hold the unique numbers. 
// After each friend has all their uniqe numbers stored, it clears the
// original vectors that were passed to it by reference. Then it copies the
// contents from the vectors that hold the unique numbers to the originals, 
// and clears the unique vectors.
//
// The parameters in this function are passed by reference, so they are
// modified directly and it doesn't need to return anything.
//
// The most complex operation in this function compares two vectors. Since
// I need to compare EVERY element in a vector against each element in another
// vector, I nested the comparison inside a for loop, which raises the
// complexity to O (N^2).
//********************************************************************
void removeDupes(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
	
	vector<int>u1, u2, u3;		// u1, u2, and u3 hold the unique problems
								// solved by friends 1, 2, and 3, respectively

	/* I use a lot of iterators in this function, the naming format is as 
	 follows. itervXvY is an iterator used for comparing the vector vX to
	 vY. For example, iterv1v3 compares the vector v1 to the vector v3. */

	// Removes any duplicate numbers from each vector
	auto iterv1v1 = unique(v1.begin(), v1.end());
	auto iterv2v2 = unique(v2.begin(), v2.end());
	auto iterv3v3 = unique(v3.begin(), v3.end());

	// Resizes the vectors after duplicate entries have been removed
	v1.resize(distance(v1.begin(), iterv1v1));
	v2.resize(distance(v2.begin(), iterv2v2));
	v3.resize(distance(v3.begin(), iterv3v3));

	//Compares v1 to v2 and v3, pushes any unique numbers to u1
	for (int i = 0; i < v1.size(); i++) {
		auto iterv1v2 = find(v2.begin(), v2.end(), v1[i]);
		auto iterv1v3 = find(v3.begin(), v3.end(), v1[i]);
		if (iterv1v2 == v2.end() && iterv1v3 == v3.end()) {
			u1.push_back(v1[i]);
		}
	}

	//Compares v2 to v1 and v3, pushes any unique numbers to u2
	for (int j = 0; j < v2.size(); j++) {
		auto iterv2v1 = find(v1.begin(), v1.end(), v2[j]);
		auto iterv2v3 = find(v3.begin(), v3.end(), v2[j]);
		if (iterv2v1 == v1.end() && iterv2v3 == v3.end()) {
			u2.push_back(v2[j]);
		}
	}

	//Compares v3 to v1 and v2, pushes any unique numbers to u3
	for (int k = 0; k < v3.size(); k++) {
		auto iterv3v1 = find(v1.begin(), v1.end(), v3[k]);
		auto iterv3v2 = find(v2.begin(), v2.end(), v3[k]);
		if (iterv3v1 == v1.end() && iterv3v2 == v2.end()) {
			u3.push_back(v3[k]);
		}
	}

	// Clears the original vectors
	v1.clear();
	v2.clear();
	v3.clear();

	// Copies the unique numbers into the original vectors
	v1 = u1;
	v2 = u2;
	v3 = u3;

	// Clears the unique vectors
	u1.clear();
	u2.clear();
	u3.clear();
}


//******************************************************************* 
// printVects() 
// Parameters: 3 vectors of ints, passed by reference. 
// Complexity: O(N) 
//
// This function determines which of the processed vectors is the largest, 
// and prints out the number of the friend with the largest vector, the
// number of problems he solved, and the unique problems he solved.
//
// The parameters in this function are passed by reference, so they are
// modified directly and it doesn't need to return anything.
//
// This function has multiple for loops that are not nested, so its complexity
// is O(N).
//********************************************************************
void printVects(vector<int> &v1, vector<int> &v2, vector<int> &v3) {

	// Friend 1 is the winner
	if (v1.size() > v2.size() && v1.size() > v3.size()) {
		cout << "1 " << v1.size() << " ";
		for (int i : v1) {
			cout << i << " ";
		}
	}
	// Friend 2 is the winner
	else if (v2.size() > v1.size() && v2.size() > v3.size()) {
		cout << "2 " << v2.size() << " ";
		for (int i : v2) {
			cout << i << " ";
		}
	}
	// Friend 3 is the winner
	else if (v3.size() > v1.size() && v3.size() > v2.size()) {
		cout << "3 " << v3.size() << " ";
		for (int i : v3) {
			cout << i << " ";
		}
	}
	// Friends 1, 2, and 3 are tied.
	else if (v1.size() == v2.size() && v1.size() == v3.size()
		&& v2.size() == v3.size()) {
		cout << "1 " << v1.size() << " ";
		for (int i : v1)
			cout << i << " ";
		cout << endl;
		cout << "2 " << v2.size() << " ";
		for (int j : v2)
			cout << j << " ";
		cout << endl;
		cout << "3 " << v3.size() << " ";
		for (int k : v3)
			cout << k << " ";
	}
	// Friends 1 and 2 are tied.
	else if (v1.size() == v2.size()) {
		cout << "1 " << v1.size() << " ";
		for (int i : v1)
			cout << i << " ";
		cout << endl;
		cout << "2 " << v2.size() << " ";
		for (int j : v2)
			cout << j << " ";
	}
	// Friends 1 and 3 are tied.
	else if (v1.size() == v3.size()) {
		cout << "1 " << v1.size() << " ";
		for (int i : v1)
			cout << i << " ";
		cout << endl;
		cout << "3 " << v3.size() << " ";
		for (int j : v3)
			cout << j << " ";
	}
	//Friends 2 and 3 are tied.
	else if (v2.size() == v3.size()) {
		cout << "2 " << v2.size() << " ";
		for (int i : v2)
			cout << i << " ";
		cout << endl;
		cout << "3 " << v3.size() << " ";
		for (int j : v3)
			cout << j << " ";
	}

	cout << endl;

	// Clears the vectors to prepare for the next case
	v1.clear();
	v2.clear();
	v3.clear();
}
