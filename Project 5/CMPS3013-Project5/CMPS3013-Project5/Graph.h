#pragma once
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class Graph {
public:
	struct vtx {		//holds the from, to, and weight of an edge
		int f, t, w;
	};
	vector<vtx> list;	//list of all edges
	set<int> nums;		// set containing each author number in the graph
	
	// Index stores the IDs of each author number in the index of the vector
	// ID stores each author number from smallest to greatest. The index each
	// number is stored in is its ID.
	// Taken determines whether a node has been used yet during Prim's algorithm 
	vector<int> index, ID, taken;	

	vector<vector<pair<int, int>>> alist;	//adjacency list
	priority_queue<pair<int, int>> pq;	// holds (to,weight)

	priority_queue<pair<int,int>>tree;  // (size, (weight/vertex index))
		
	// the second int in tree contains the ID / index to be used to get
	// a weight from weightVert.
	vector<int> weightVert;
	int totalNodes = 0;	//total amount of nodes of every tree in the forest



	
public:
	Graph() {};
	~Graph() {};
	void addEdge();
	void process(int);
	void dumpTrees();
};

