///////////////////////////////////////////////////////
// BST.cpp
#include "BST.h"
#include <stack>

// add complexity to each function below.

BST::BST()
{
	root = nullptr;
	sz = 0;
}

//BST::BST(initializer_list<int> lst) {
//	for (auto i : lst)
//		Insert(i);
//}

// REQUIRED since we have dynamic memory in the class
BST::~BST()
{
	Clear(root);
}

//// copy constructor. Makes a copy if T is not empty
//BST::BST(const BST& T) {
//	//copyTree(root, T.root);// uses two params
//	root = Clone(T.root);// another way, uses one param
//	sz = T.sz;
//}
//
////overloaded assignment. Note the structure of the method
//BST& BST::operator=(const BST& T) {
//	if (this->root != T.root) {//make sure we do not have A=A situation
//		this->Clear(root);// delete the tree on the left so no leakage
//		//copyTree(root, T.root);
//		root = Clone(T.root);// a better way , maybe
//		sz = T.sz;
//	}
//	return (*this);
//}
//
//// The move constructor , also no copying.
//BST::BST(BST&& T) {
//	root = T.root;
//	sz = T.sz;
//	T.root = nullptr;
//	T.sz = 0;
//}

//// This is the move assignment. No copying going own
//BST& BST::operator=(BST&& T) {// move assignment
//	if (this != &T) {
//		swap(root, T.root);// this trick allows the calling
//		sz = T.sz;
//	}                     // program to destruct r for this method
//	return *this;
//}
// Public Insert() method
void BST::Insert(int v)
{
	InsertAux(root, v);
	sz++;
}



// Print an inorder traversal of tree to os stream
void BST::InorderPrint(ostream& os) const
{
	if (root == nullptr)
		os << "<empty>";
	else
		InorderPrintAux(root, os);
	os << endl;
}



void BST::Flatten()
{
	// TODO:Write the code so that the tree is converted to
	// one that has all left pointers equal to nullptr.
	//This is called a flat BST or in some algorithm ie DSW algorithm
	// a backbone.  Can you figure out how to do this?
}

//Return the number of nodes in a tree
int BST::NumNodes() {
	return NumAux(root);
}



//Return the sum of the nodes in the tree
int BST::Sum()
{
	return SumAux(root);
}



// Remove the value v from the tree if it is there
// Only removes the first occurence of v.
void BST::Remove(int v)
{
	RemoveAux(root, v);
	sz--;
}




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Private auxilary recursive method 
void BST::InsertAux(Node*& r, int v)
{
	if (r == nullptr) {
		r = new Node(v);
	}
	else {
		if (v < r->val) {
			InsertAux(r->left, v);
		}
		else {
			InsertAux(r->right, v);
		}
	}
}




//Another case where & is really important
void BST::RemoveAux(Node*& r, int v)
{
	if (r == nullptr)return;//not found
	if (v < r->val) RemoveAux(r->left, v);
	else
		if (v > r->val)RemoveAux(r->right, v);
		else
			// We found v in the tree and
			// r now points to the node we wish to delete
			if (r->left != nullptr && r->right != nullptr) {// two children
			   //go right and all the way left. Find the succecessor
				Node* tptr = r->right;
				Node* bptr = r->right;//go right
				while (tptr->left != nullptr) {// go all the way left
					bptr = tptr;// save back ptr
					tptr = tptr->left;
				}
				// tptr now points to succecessor
				// copy succ value to node pointed to by r
				r->val = tptr->val;
				// If we did not go left at all just splice tptr node out
				if (r->right == tptr) {
					r->right = tptr->right;
					delete tptr;
				}
				else {//we did go left so splice out tptr here
					bptr->left = tptr->right;
					delete tptr;
				}
			}
			else {//  r node has less than two children so easy
				if (r->left != nullptr) {
					Node* t = r;// new r is sent back thru ref parameter
					r = r->left;
					delete t;
				}
				else {// r->right is not null or it is.
					Node* t = r;
					r = r->right;// new r is sent back thru ref parameter
					delete t;
				}
			}
}



void BST::InorderPrintAux(Node* r, ostream& os) const
{
	if (r != nullptr) {
		InorderPrintAux(r->left, os);// print left sub tree
		os << r->val << " ";
		InorderPrintAux(r->right, os);//print right sub tree
	}
}



//delete a tree using a reference parameter method
void BST::Clear(Node*& r)
{
	if (r != nullptr) {
		Clear(r->left);
		Clear(r->right);
		delete r;
		r = nullptr;
	}
}



//resursive sum.
int BST::SumAux(Node * r)
{
	if (r == nullptr)//base case when we pass a leaf
		return 0;
	else
		return r->val + SumAux(r->left) + SumAux(r->right);
}


int BST::NumAux(Node * r) {
	if (r == nullptr)//base case when we pass a leaf
		return 0;
	else
		return 1 + NumAux(r->left) + NumAux(r->right);
}

// create a clone of the r tree and put it into self
// I feel this is better than copyTree(). Its
// a friend as well. Returns a pointer to the cloned tree.
BST::Node *Clone(BST::Node * r) {
	if (r == nullptr)
		return r;
	//cute method to recursively create new nodes 
	BST::Node *t = new BST::Node(r->val, Clone(r->left), Clone(r->right));
	return t;
}

// Should only call this if Tree pointed to by r is empty.
// Makes a COPY of sr and puts it into r.  This is not
// a method.  Stand alone private friend utility function!
// The requirement that r be a nullptr in order to call this
// is quite questionable. Hmmm
//void copyTree(BST::Node *& r, const BST::Node *sr)
//{
//	if (sr == nullptr)
//		r = nullptr;
//	else
//	{
//		r = new BST::Node(sr->val);
//		copyTree(r->left, sr->left);
//		copyTree(r->right, sr->right);
//	}
//}