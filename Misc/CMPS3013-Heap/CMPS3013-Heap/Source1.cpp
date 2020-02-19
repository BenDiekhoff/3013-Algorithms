//	Test practice
//	new heapsort

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

//	O(lg n)
void insert(vector<int> &heap, int x)
{
	heap.push_back(x); // insert x into the vector (heap)
	int i = heap.size() - 1; // location of x
	int p = i / 2; // location of the parent
				   //	swap up as necessary
				   //	if p > 0 (p is in the array)
				   // 	and if heap[i] (child) is bigger than heap[p] (parent) 
	while (p > 0 && heap[i] > heap[p])
	{
		int temp = heap[p];
		heap[p] = heap[i];
		heap[i] = temp;
		i = p; // i is now in p's former location
		p = i / 2; // the new parent's location
	}
}

//	O(lg n)
//	New and improved heapify
//	int n is the size of the vector
//	int i is the starting location (typically the root)
//	use heapify when the root is bad but both subtrees are proper
void heapify(vector<int> &heap, int n, int i)
{
	int l = 2 * i; // left child's location (index in the array/vector)
	int r = (2 * i) + 1; // right child's location
	int larger; // stores the comparison

				//	Compare the root to the two children 
				//	first ensure the child is actually in the array
				//	then compare values
	if (l < n && heap[l] > heap[i])
		larger = l;
	else
		larger = i;

	//	now check right child
	if (r < n && heap[r] > heap[larger])
		larger = r;

	//	now we know which location has the higher value
	//	swap if necessary
	if (larger != i)
	{
		int temp = heap[i];
		heap[i] = heap[larger];
		heap[larger] = temp;
		heapify(heap, n, larger);
	}
}

//	O(lg n)
//	extract
int extract(vector<int> &heap)
{
	int max = heap[1];
	int sz = heap.size() - 1;
	heap[1] = heap[sz]; // swap last number to root
	heap.pop_back();
	heapify(heap, sz, 1);

	return max;
}

//	O(n)
//	buildheap
void buildHeap(vector<int> &heap)
{
	int sz = heap.size();
	for (int i = sz / 2; i > 0; i--)
		heapify(heap, sz, i);
}

//	O(n lg n)
//	heapsort
void heapSort(vector<int> &heap)
{
	int n = heap.size() - 1;
	// First build the heap (could be all random numbers)
	buildHeap(heap);

	for (int i = n; i > 0; i--)
	{
		int temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		heapify(heap, i, 1);
	}
}

void printHeap(vector<int> &heapyboi)
{
	for (int i = 1; i < heapyboi.size(); i++)
		cout << heapyboi[i] << " ";
	cout << endl;
}


int main()
{
	// 91,62,37,19,24,54,29,41,65,79,40,74,87,22,78,39,4
	initializer_list<int> ilist = 
	{ 0,91,62,37,19,24,54,29,41,65,79,40,74,87,22,78,39,4 };
	vector<int> heapyboi = { ilist };

	printHeap(heapyboi);
	buildHeap(heapyboi);
	printHeap(heapyboi);
	heapSort(heapyboi);
	printHeap(heapyboi);

	return 0;
}