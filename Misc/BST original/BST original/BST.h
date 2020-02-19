#pragma once
// Version .8
// NOTE: if you want to use recursion you must write a
// recursive Aux function that the public method calls.
#include <iostream>
#include <initializer_list>
using namespace std;
class BST
{
	struct Node {
		int val;
		//int size;// if implemented will contain the size of the subtree rooted here
		Node * left;
		Node * right;
		Node(int v, Node* l = nullptr, Node* r = nullptr) :val(v), left(l), right(r) {};
	};
	Node * root;
	int sz;// contains the number of nodes in the tree
public:
	BST();// Default method.
	BST(initializer_list<int>);
	~BST();// destructor. Calls clear

	//our two required constructors
	BST(const BST&);// copy constructor
	BST(BST&&);// rvalue reference constructor(move)

	void Insert(int);// insert a new node
	void Remove(int);//Remove a node

	void InorderPrint(ostream&) const;// Print an inorder traversal

	//Our two overloaded assignments
	BST& operator=(const BST&);// overloaded assignment operator
	BST& operator=(BST&&); //rvalue reference assignment (move)

	//some other methods 
	int SumNR();//return the sum of the values
	int Sum();//returns sum of the values in the tree
	int NumNodes();//returns the number of nodes in the tree recusively
				   // of course we could just return sz in this case.
	//Other methods that we can add
	void Flatten();// Not coded yes. It converts a tree 
				   //to one where all left ptrs are nullptr
	// Modify the remove() command so that it alternates between
	// using the predecessor and the successor within the function
	// This will keep the tree more balanced over time.
	//void Mirror()// swap left and right pointer for every node.
	// Augument the tree nodes with a size variable that contains
	//   the number of nodes in the tree rooted at each node. Then
	//   write the following two functions Rank() and Range() efficiently
	//int Rank(int v) // Returns the number of nodes less than v O(h)
	//int Range(int a,int b)//Returns the number of nodes greater than
	//   or equal to a and less than b  O(h) is required
	//int IPL();//internal path length. Returns the sum of the depths of nodes
	//bool Search(int);// search for a node in the tree. 
	// int Height()// return the height of the tree.
	// void DSW(Node * tree)// Day Stout Warren alg to balance the tree.
	//    requires a simple right rotation method.
	// Add iterators to this class (first thread the tree,both ways)
	// Node* Intersect(Node* r,Node* s);// return a tree that contains
	//    only values that exist in both tree.
private: // private recursive methods
	void InsertAux(Node*&, int);
	void RemoveAux(Node*&, int);
	void InorderPrintAux(Node *, ostream&)const;
	void Clear(Node*& r);
	int SumAux(Node *);
	int NumAux(Node *);
	friend Node *Clone(BST::Node *);
	//friend void copyTree(Node *&, const Node *);//copy right tree into left tree.
public://Friends
	//overloaded output operator
	friend ostream& operator<<(ostream& os, const BST& t) {
		t.InorderPrint(os);//Writes output to os stream.
		return os;
	}
};

