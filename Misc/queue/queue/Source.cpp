#include <iostream>
#include <queue>
#include <vector>
using namespace std;


	// A Binary Tree Node 
	struct node
	{
		struct node *left;
		int data;
		struct node *right;
	};


	void levelOrder(node *r) {
		queue<node *> q;

		q.push(r);
		while (!q.empty()) {
			r = q.front();
			q.pop();
			
			if (r->left)
				q.push(r->left);
			
			if(r->right)
				q.push(r->right);
			
			cout << r->data << " ";
		}
		cout << endl;
	}

	// Utility function to create a 
	// new tree node 
	node* newNode(int data)
	{
		node *temp = new node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	// Driver program to test above 
	// functions 
	int main()
	{

		// Let us create binary tree 
		// shown above 
		node *root = newNode(1);
		root->left = newNode(2);
		root->right = newNode(3);
		root->left->left = newNode(4);
		root->left->right = newNode(5);
		root->right->right = newNode(6);

		levelOrder(root);
		system("pause");
		return 0;



	}
