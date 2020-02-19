#include "Graph.h"



/**********************************************************************
	addEdge()
	Parameters: none
	Complexity: O(E)

	Reads in the edges from the input file and manipulates it so each vertex
	has a unique ID. With the IDs, an adjacency list is made containing the 
	edges of that ID and the weight of each edge. Self loops are omitted.
	The complexity is O(E) because the you need to process every edge in the
	graph.
	***********************************************************************/
void Graph::addEdge() {
	ifstream infile("CA-GrQc.txt");
	int f, t, w;
	vector<pair<int,int>> fromTo;
	
	//read in data. f is put in a set (nums) so it only stores unique numbers
	while (infile >> f >> t) {
		nums.insert(f);
		fromTo.push_back(make_pair(f, t));
	}
	infile.close();
	ID.resize(nums.size());  //make one index for each unique number

	//resize index to have an index from 0 the largest number in the set
	auto it = nums.end();
	it--;
	int last = *it;
	index.resize(last + 1);

	//vectors for each number read in, 15000 is held in index 15000,etc
	// ID holds the unique numbers only, sorted from min to max
	it = nums.begin();	//iterator to beginning of nums, points to 13
	int i = 0;
	for (auto j : nums) {			
		index[*it] = i;		//index[13] holds 0, index [14] holds 1, etc
		ID[i] = *it;		//ID[0] holds 13, ID[1] holds 14, etc
		it++;
		i++;
	}

	alist.resize(ID.size()); //resize adj list to hold a vector for each ID


	vtx v;
	// read from vector of pairs fromTo so I don't have to read the infile again
	for (auto i: fromTo)
		if (i.first != i.second) {	// ignore loops
			w = abs(i.first - i.second) % 10;	//weight
			i.first = index[i.first];			//from
			i.second = index[i.second];			//to
			v.f = i.first;
			v.t = i.second;
			v.w = w;
			list.push_back(v); // make a list of edges
		}

	// make a pair containing (to,weight) and push it to the vector of pairs
	// in my adjacency list. The index they're pushed to are determined by
	// where the edge is coming from.
	// For example, the number 13 has ID 0, so all of 13's connections are
	// pushed to alist[0].
	for (auto i : list) {
		int from = i.f;
		int to = i.t;
		int weight = i.w;
		alist[from].push_back(make_pair(to, weight));
	}

	taken.assign(alist.size(), 0); //fill taken with 0s

}
	

/**********************************************************************
	process()
	Parameters: one int - the vertex to start from
	Complexity: O(E log V)
	
	Takes an intial vertex and checks all adjacent edges and connects to any 
	adjacent nodes based on the path with the shortest weight, as long as the
	adajcent node isn't already taken (either by the current tree, or in the
	case of my program, any other trees in the forest);
	The complexity is O(E log V) because it process each edge one time O(E),
	and	since we're using a priority queue, pushing and popping is O(log E)
	***********************************************************************/
void Graph::process(int vert) {
	taken[vert] = 1;
	//the vertex being processed is now taken, this avoids cycles

	//look at each edge that vert connects to
	for (int i = 0; i < alist[vert].size(); i++) {
		//make a pair from adj list (to,weight)
		pair<int, int> v = alist[vert][i]; 
		if (!taken[v.first]) //if the next vertex isn't taken, push values 
			// to the pq so it sorts from smallest weights, swap v.second and
			// v.first so you aren't sorting by vertex ID
			pq.push(make_pair(-v.second, -v.first));
	}
}


/**********************************************************************
	dumpTrees()
	Parameters: none
	Complexity: O(E)
	
	This function prints out every tree in the forest of MSTs in descending
	order based on the size of the tree. It prints the ID of the starting 
	vertex, the size of the tree, and the weight of every edge in the tree.
	It also prints out the number of nodes in every tree in the forest.
	The complexity is O(E) because the in worst case scenario, every edge is
	is a tree.
	***********************************************************************/
void Graph::dumpTrees() {
	ofstream outfile("out.txt");
	outfile << "Total number of nodes in all trees: " << totalNodes << endl
		<< endl << setw(30) << "Tree starting at Vertex ID"
		<< setw(15) << "Tree Size" << setw(15) << "Tree Weight"
		<< endl;
	
	while (!tree.empty()) {	// print until there are no trees left
		auto it = tree.top();
		// Print tree ID, tree size, and weight of all edges in the tree.
		outfile << setw(30)<< it.second << setw(15)<< it.first <<setw(15)
			<< weightVert[it.second] << endl;
		//pop the recently printed tree off the top of the priority queue.
		tree.pop(); 
	}
}
