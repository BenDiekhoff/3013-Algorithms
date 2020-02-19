//***************************************************************
// Project #5 Minimum Spanning Tree
// Name: Ben Diekhoff
// Data Structures and Algorithms
// Date: 05/1/2019
//***************************************************************
/*
This program takes a graph data file, assigns each edge a weight, and
makes an adjacency list. It uses Prim's algorithm on the adjacency list 
to print out a forest of minimum spanning trees, identified by the ID of the
starting vertex, the size of the tree, and the weight of all
edges in the tree combined. The output is sorted in descending order of the
size of the tree.

The worst case complexity for this program is O(E log V) because Prim's 
algorithm is the most complex function. Because I used an adjacency list, it
only has to process existing edges. If I had used an adjacency matrix, it 
would have to process each element in a square matrix of vertices, which would
be O(V*V) = O(V^2).

/*****************************************************************
 I have written the enitre program as turned in and have not copied this
code, or parts of this code from the internet or another student.
Signature______________________________________________
/******************************************************************/



#include "Graph.h"

int main() {
	Graph G;
	G.addEdge();
	G.weightVert.resize(G.alist.size());
	
	// Run Prim's algorithm on every node
	// The taken vector is not reset between each loop
	for (int i = 0; i < G.alist.size(); i++) {
		if (G.taken[i] == 1)
			continue;
		if (G.alist[i].size() < 1) // check for empty lists
			continue;
		int size = 1;
		int weight = 0;
		G.process(i);

		while (!G.pq.empty()) {
			pair<int, int> front = G.pq.top();
			G.pq.pop();
			int u = -front.second;	//convert the 'to' vertex and weights
			int w = -front.first;	// back from negatives
			if (!G.taken[u]) {
				size++;  //adjacent node hasn't been taken. Increase size
				weight += w; //accumulate the total weight of the tree
				G.process(u); //Process the adjacent node
			}
		}

		//Only record tree data if its size is greater than 0;
		if (size > 0) {
			// put the weight of the edge in the index of the node's ID 
			// in weightVert
			G.weightVert[i] = weight;
			//push the size and node ID pair to a priority queue so it's 
			// easy to sort from largest size.
			G.tree.push(make_pair(size, i));
			//keep track of all the nodes in every tree so far
			G.totalNodes += size;	
		}
		

	}
	G.dumpTrees(); //print the forest of MSTs
	return 0;

}
