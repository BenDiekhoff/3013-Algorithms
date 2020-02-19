//***************************************************************
// Project #3 Binary Search Tree
// Name: Ben Diekhoff
// Data Structures and Algorithms
// Date: 02/27/2019
//***************************************************************
/*
This program creates a binary search tree class. It adds nodes using
dynamically allocated memory from the heap. It takes input from cin through
"file.txt" and adds, removes, and returns the rank of nodes in the tree.
It also returns the amount of nodes within the range of a pair of integers.

						 COMPLEXITY
The complexity of this program in O(N).
The most complex method in the program is O(N). Many methods, like search,
insert, and remove would would be O(log N) on a perfectly balanced tree. 
However, this tree is nearly flat, so these functions are all closer to
O(N). Additionally, other methods, like remove, numNodes, and inOrderPrint
need to access every node in the tree, so they are naturally O(N).

/*****************************************************************
 I have written the enitre program as turned in and have not copied this
code, or parts of this code from the internet or another student.
Signature______________________________________________
/******************************************************************/


// Source.cpp

#include <iostream>
#include <iomanip>
#include <initializer_list>
#include "BST.h"
#include <queue>
using namespace std;

int main() {
	
	//initializer_list<int> lst = { 50,29,54,33,62,45,58,213,48 };
	//initializer_list<int> lst = { 4,2,6,1,3,5,7 };
	initializer_list<int> lst = { 5,3,8,1,4,7,9,2,6 };
	BST T(lst);
	/*for (int i = 0; i < 25; i++) {
		int x = rand() % 1000;
		T.insert(x);
		cout << x << " ";
	}
	cout << endl << endl;

	T.flatten();
	T.inOrderPrint(cout);
	T.preOrderPrint(cout);*/
	//int N, M, K, addNum, delNum, mNum, a, b;

	//// Load numbers 1 - 1000
	//for (int i = 1; i <= 1000; i++) {
	//	T.insert(i);
	//	cout << setw(4) << i << " ";
	//	
	//	if (i % 15 == 0)
	//		cout << "\n";
	//}
	//cout << endl << endl;

	////Insert and remove numbers from file.txt
	//cin >> N;
	//for (int i = 0; i < N; i++) {
	//	cin >> addNum >> delNum;
	//	T.insert(addNum);
	//	T.remove(delNum);
	//}
	//
	//// Print rank
	//cin >> M;
	//for (int i = 0; i < M; i++) {
	//	cin >> mNum;
	//	cout << T.rank(mNum) << endl;
	//}
	//cout << endl;

	//// Print range
	//cin >> K;
	//for (int i = 0; i < K; i++) {
	//	cin >> a >> b;
	//	cout << T.range(a, b) << endl;
	//}

	struct Node{
		int val; // The value stored in the node
		Node *left; // points to the left subtree
		Node *right; // points to the right subtree
	};
	queue<Node *> q;
		

	cout << T.ipl();




	system("pause");
	//return 0;
}


