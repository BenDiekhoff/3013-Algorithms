


////////////////////////////////////////////////////////
// Main Program 
// TreeStudy.cpp : Ver .8   Test Binary Search tree class
// Programmed by Richard P. Simpson on 2/11/2019 for class. This is an approach
// that is not C++11.  IE we make a lot of copies. If we get
// time we will look at how r-value references can reduce the 
// number of tree copies we make :>)
// updated on 2/19/2019  added clone() and fixed missing sz code

#include <iostream>
#include <vector>
#include <initializer_list>
#include "BST.h"
using namespace std;

// make a random tree having n nodes whose values are less than limit
BST MakeRandTree(int n, int limit) {
	BST T;
	for (int i = 0; i < n; i++)
		T.Insert(rand() % limit);
	return T;// Note that T is an R-value :>) so no copy
	// Single step past this point using F11 and see who gets called.
}


int main()
{
	int size = 10;
	srand(6);

	vector<int> vals;//stores values in a tree 
	int v;
	BST T;//Creates an empty tree.
	for (int i = 2; i < size; i++) {
		//v = rand();
		T.Insert(i);
		vals.push_back(i);
		cout << i << " ";

	}
	cout << "\n\n";
	////Do 1000 delete/insert pairs;
	//for (int i = 0; i < 1000; i++) {
	//	int idx = rand() % size;
	//	T.Remove(vals[idx]);//remove the random value
	//	int v = rand();
	//	T.Insert(v);//insert a random number 0->99
	//	vals[idx] = v;
	//}
	//T.InorderPrint(cout);

	////This is just a test of T.remove so remove all but one value
	//for (int i = 0; i < vals.size() - 7; i++)
	//	T.Remove(vals[i]);

	//BST R(T);// calls copy constructor
	//R.InorderPrint(cout);

	//BST S;
	//S = T;//calls overload assignment
	//S.InorderPrint(cout);

	////check sum
	//cout << "Sum=" << S.Sum() << endl;

	//// Test initializer_list constructor
	//cout << "\nTest initializer_list constructor" << endl;
	//BST Q{ 1,5,3,4,6 };
	//Q.InorderPrint(cout);
	////Test Rvalue reference code
	//cout << "\nTest move constructor " << endl;
	//BST RT{ 2,4,6 };
	//RT = MakeRandTree(100, 1000);// Debug into this and see what happens
	//RT.InorderPrint(cout);

	//cout << "\nTest overloaded output" << endl;
	//cout << RT << endl;
	cout << T.NumNodes();
	T.Remove(1);
	cout << T.NumNodes();
	T.Remove(1);
	T.Remove(1);
	T.Remove(1);
	cout << T.NumNodes();
	system("pause");
}


