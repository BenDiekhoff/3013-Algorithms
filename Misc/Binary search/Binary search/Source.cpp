#include <iostream>
using namespace std;

int num[256];



int main() {
	for (int i = 0; i < 256; i++) {
		num[i] = i + 1;
	}
	int anum = 256;
	bool found = false;
	int first, last, middle, count, count2, count3;
	first = 0;
	last = 255;
	count = count2 = 0;
	while (!found && first <= last) {
		count2++;
		middle = (first + last) / 2;
		if (anum == num[middle]) {
			found = true;
		}
	
		else if (anum > num[middle]) {
		first = middle + 1;
		count++;
		cout << first << endl;
	}
		else {
			last = middle - 1;
			
		}
	}
	cout << "anum > num[middle] comparisons: " << count << endl << "First <= last  and if anum == num[middle] comparisons: " << count2 << endl;
	system("pause");
	return 0;
}