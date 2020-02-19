// BST.cpp
#include "BST.h"


/**********************************************************************
clear()
Parameters: Node*&
Complexity: O(n)

Private method to recursively delete every node from the tree. 
Complexity is O(n) because it has to remove every 
***********************************************************************/
void BST::clear(Node*& r){
	if (r != nullptr) { //If the node exists
		clear(r->left); //clear the left subtree
		clear(r->right);//clear the right subtree
		delete r;		//delete the current node
		r = nullptr;	//remove dangling points
	}
}

/**********************************************************************
insertAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to insert an int into the tree.
It's passed a pointer to a node and an int to be inserted.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
void BST::insertAux(Node*& r, int v) {
	if (r == nullptr)	//If the passed node doesn't exist
		r = new Node(v); //make a new one from the heap containing the 
						//passed int

	else {				// If the passed node does exist
		r->size++;		// increment the size value of this node
		
		if (v < r->val)				// If the passed int is less than the 
			insertAux(r->left, v);	// value of this node, go to the left 
									//subtree
		
		else						// if the passed int is greater than or
			insertAux(r->right, v);	// equal to the value of this node, go
	}								// to the left subtre			
}

/**********************************************************************
removeAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to remove a node from the tree.
It's passed a pointer to a node and an int to be removed.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
void BST::removeAux(Node*& r, int v) {
	if (r == nullptr)	// If the node is not found
		return;
	
	else{
		if (v < r->val) {			// If v is less than the value of the node,
			r->size--;				// decrment the size of nodes along the
			removeAux(r->left, v);	// path and go left.
		}
		else
			if (v > r->val) {			// If v is less than the value of the 
				r->size--;				// node, decrement size and go right.
				removeAux(r->right, v);

			}
			else //The node to be removed has been found and r points to it.

		// Two children
				if (r->left != nullptr && r->right != nullptr) {
				   // Find the successor by going right and all the way left
					Node* temp = r->right;  // temp points to node to the right
					Node* back = r->right;	// back points to node to the right
					
					while (temp->left != nullptr) {   // go all the way left
						back = temp;         // back points to previous node
						temp = temp->left; // temp points to node to the left
					}
					//when left is nullptr, temp points to successor node, copy
					//the successor node's value and size to it's replacement
					r->val = temp->val;
					r->size = temp->size;
				
					// If we did not go left at all just splice temp node out
					if (r->right == temp) {
						r->right = temp->right;
						delete temp;
					}
					else {//we did go left so splice out temp here
						back->left = temp->right;
						delete temp;
					}
				}
		//  Node has less than two children.
				else {
					if (r->left != nullptr) {
						Node* t = r;// new r is sent back thru ref parameter
						r = r->left;
						delete t;
					}
					else {// r->right is not null or it is.
						Node* t = r; //t points to node to be deleted
						r = r->right;	// r either points to right subnode
										// or nullptr
						// new r is sent back thru ref parameter
						delete t;
					}
				}

	}
	return;
}

/**********************************************************************
inOrderPrintAux()
Parameters: Node*&, ostream&
Complexity: O(n)

Private method that uses recursion to print the value of every node int the 
tree in ascending order.
It's passed a pointer to a node and an ostream type that determines how it 
outputs the information.
Complexity is O(n) because it has to go to and print every node in the
tree.
***********************************************************************/
void BST::inOrderPrintAux(Node* r, ostream& os)const {
	if (r != nullptr) {
		inOrderPrintAux(r->left, os);// print left sub tree
		os << r->val << " ";
		inOrderPrintAux(r->right, os);//print right sub tree
	}

}

/**********************************************************************
numNodesAux()
Parameters: Node*&
Complexity: O(n)

Private method that uses recursion to return the total number of nodes in the
tree.
It's passed a pointer to a node.
Complexity is O(n) because the method has to go to and count every node in
the tree.
***********************************************************************/
int BST::numNodesAux(Node*& r)const {
	if (r == nullptr)
		return 0;
	else
		return 1 + numNodesAux(r->left) + numNodesAux(r->right);
}


/**********************************************************************
searchAux()
Parameters: Node*&, int
Complexity: O(n)

Private method that uses recursion to search for a node in the tree and return 
true or false depending on whether it's found.
It's passed a pointer to a node and an int to be searched for.
Complexity is O(n) because the tree may not be balanced.
***********************************************************************/
bool BST::searchAux(Node*& r, int v)const {
	if (r == nullptr) {				//v is not found
		return false;
	}
	
	if (v < r->val)
		searchAux(r->left, v);		//go left

	else if (v > r->val)
		searchAux(r->right, v);		//go right
	else                            // v is found
		return true;

}

/**********************************************************************
rankAux()
Parameters: Node*&, two ints
Complexity: O(n)

Private method that uses recursion to return an integer's rank in the tree.
It's passed a pointer to a node and two ints. Int v is the int who's rank
will be determined. Int rank keeps track of the rank of v through the 
recursive calls.
The rank is its position in the sorted tree. For example, the smallest
int in a tree would be rank 1. The largest would be equal to the number
of nodes in the tree. If the integer is not found in the tree, it
returns 0.
Complexity is O(n) because the method may have to go through every node in 
the tree.
***********************************************************************/
int BST::rankAux(Node*& r, int v, int rank) {
	if (r == nullptr)	//If v is not found, it's rank is 0
		return 0;
	
	if (v < r->val)
		rankAux(r->left, v, rank);	// go left
	else if (v > r->val) {
		if (r->left == nullptr)		//if the left subnode doesn't exist,
			rank++;					//increment size.
		else
			rank += (1 + r->left->size);//add the size of the left subtree +1
		rankAux(r->right, v, rank);		// to rank and go right
	}
	else {							//v is found. If v has a left subnode, add 
		if (r->left != nullptr)		//it's size to rank.
			rank += r->left->size;
		return rank;
	}
}

/**********************************************************************
rangeAux()
Parameters: Node*&, two ints
Complexity: O(n)

Private method that uses recursion to return the amount of nodes in a certain
range. The range is the number of nodes in the tree that are greater than or
equal to the first argument (i), and less than the second (j).
Complexity is O(n) because the method may have to go through every node in
the tree.
***********************************************************************/
int BST::rangeAux(Node*& r, int i, int j) {
// if the arguments create an impossible range or a node is nullptr, return 0
	if (i >= j || r == nullptr) 
		return 0;

	if (r->val >= i && r->val < j)	//the node is in the range between i and j.
									//Start counting until it's not in range.
		return 1 + rangeAux(r->left, i, j) + rangeAux(r->right, i, j);
	else if (r->val >= i)
		return rangeAux(r->left, i, j); // go left until r->val is < j
	else if (r->val < j)
		return rangeAux(r->right, i, j); // go right until r->val is >= i
	else 
		return 0;
}




