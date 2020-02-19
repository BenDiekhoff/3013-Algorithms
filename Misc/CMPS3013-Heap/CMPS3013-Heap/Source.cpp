#include "Heap.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	srand(6);
	//{ 80, 21, 73, 55, 42, 83, 83, 79, 90, 84, 93, 97 }
	vector<int> nums = { 4,1,3,2,16,9,10,14,8,7 };
	MaxHeap H(nums);
	//for (int i = 0; i < 15; i++) {
	//	//int x = rand() % 50 + 1;
	//	nums.push_back(i);
	//	cout << i << " ";
	//}
	//cout << endl;

	H.buildHeap();
	//H.insert(nums);

	H.printHeap();
	//for (int i = 1; i < H.heap.size(); i++) {
	//	cout <<setw(3) << i << " ";
	//}

	system("pause");
	return 0;
}