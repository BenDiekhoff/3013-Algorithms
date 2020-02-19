#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Median {
	priority_queue<int, vector<int>, less<int>> lessQ; //max heap
	int lSize = 0; // size of lessQ

	int med;  //median
	bool medVal = false;  // does med have a valid value?
	
	priority_queue<int, vector<int>, greater<int>> greaterQ; //min heap
	int gSize = 0; // size of greaterQ

public:
	Median() {};
	~Median() {};
	void insert(int);
	void extractMedian();

private:
	void insertAux(int);
	void extractMedianAux();
};

