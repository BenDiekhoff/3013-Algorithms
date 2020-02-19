#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
class MaxHeap{
private:

public:

	vector<int> heap = { 0 };
	
	MaxHeap() {};
	
	MaxHeap(vector<int> vect) {
		for (int x : vect)
			heap.push_back(x);
	}

	~MaxHeap() {};



	int parent(int i) {
		return i >> 1;
	}
	
	int left(int i) {
		return i << 1;
	}

	int right(int i) {
		return (i << 1) + 1;
	}

	void heapify(vector<int> &heap, int i) {
		int largest;
		int l = left(i);
		int r = right(i);
		if (l <= heap.size()-1 && heap[l] > heap[i])
			largest = l;
		else
			largest = i;
		if (r <= heap.size()-1 && heap[r] > heap[largest])
			largest = r;
		if (largest != i) {
			swap(heap[i], heap[largest]);
			heapify(heap, largest);
		}
	}

	void buildHeap()
	{
		for (int i = ((heap.size() -1) / 2); i > 0; i--)
			heapify(heap, i);
	}

	void heapSort() {

	}

	//void insert(int x) {
	//	heap.push_back(x);
	//	int i = heap.size() - 1;
	//	int parentIndex = i / 2;
	//	while (parentIndex > 0 && heap[i] > heap[parentIndex]) {
	//		swap(heap[i], heap[parentIndex]);
	//		i = parentIndex;
	//		parentIndex = i / 2;
	//	}
	//};

	//// O(n log n)
	//void insert(vector<int> vect) {
	//	for (int x : vect) {
	//		heap.push_back(x);
	//		int i = heap.size() - 1;
	//		int parentIndex = i / 2;
	//		
	//		while (parentIndex > 0 && heap[i] > heap[parentIndex]) {
	//			swap(heap[i], heap[parentIndex]);
	//			i = parentIndex;
	//			parentIndex = i / 2;
	//		}
	//	}
	//};

	void printHeap() {
		for (int i = 1; i <= heap.size()-1; i++)
			cout <<setw(3) << heap[i] << " ";
		cout << endl;
		for (int i = 1; i <= heap.size()-1; i++)
			cout << setw(3) << i << " ";
		cout << endl;
	};

	//void inOrderPrint() {

	//	
	//};

};

