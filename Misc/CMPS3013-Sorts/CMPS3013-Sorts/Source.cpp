#include <iostream>
#include <vector>
#include <ctime>
using namespace std;



void insertion(vector<int>&);

void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

void quicksort(vector<int> &, int, int);
int partition(vector<int> &, int, int);


int main() {
	
	/********************************************************************
						INSERTION SORT
	/********************************************************************/
	//srand(time(NULL));
	vector<int> list{ 7,2,4,1,5,3,6 };

	// fill vector and display unsorted values
	cout << "insertion\n";

	for (int i = 0; i < list.size(); i ++)
		cout << list[i] << " ";
	cout << "\n";

	insertion(list);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << "\n\n";

	/********************************************************************
					MERGE SORT
	/********************************************************************/
	cout << "Merge\n";
	vector<int> a { 1,4,1,6,8,5,3,7 };
	for (int i = 0; i <= a.size() - 1; i++)
		cout << a[i] << " ";
	cout << "\n";

	mergeSort(a, 0, a.size() - 1);

	
	for (int i = 0; i <= a.size() -1; i++)
		cout << a[i] << " ";
	cout << "\n\n\n";


/********************************************************************
				QUICK SORT
/********************************************************************/
	cout << "quick\n";
	vector<int> A = { 2, 3, 7, 10, 4, 8, 6, 9, 1, 5 };
	
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;

	quicksort(A, 0, A.size() - 1);

	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;

	/********************************************************************
/********************************************************************/



	system("pause");
	return 0;
}




/********************************************************************
/********************************************************************/

/********************************************************************
/********************************************************************/

/********************************************************************
/********************************************************************/






//////////////////////////////////////////////////////////////////////////
					//INSERTION
//////////////////////////////////////////////////////////////////////////

void insertion(vector<int> &v) {

	int size = v.size()-1;


	for (int i = 1; i <= size; i++) {
		int ind = i;
		int val = v[i];

		while (ind > 0 && v[ind - 1] > val) {
			v[ind] = v[ind - 1];
			ind--;
		}
		v[ind] = val;
	}
}


//////////////////////////////////////////////////////////////////////////
							//MERGE
//////////////////////////////////////////////////////////////////////////

void mergeSort(vector<int> &a, int l, int r) {
	int m;
	
	if (l < r){
	m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m+1, r);

	merge(a, l, r, m);
	}

}



void merge(vector<int> &a, int l, int r, int m){
	int i, j, k;
	i = l;
	j = m + 1;
	k = 0;

	vector<int> temp(r - l + 1);

	while (i <= m && j <= r) {
		if (a[i] < a[j]) 
			temp[k++] = a[i++];

		else 
			temp[k++] = a[j++];

	}

	while (i <= m) 
		temp[k++] = a[i++];

	while (j <= r) 
		temp[k++] = a[j++];


	for (i = l; i <= r; i++)
		a[i] = temp[i - l];

}

//////////////////////////////////////////////////////////////////////////
							//QUICK
//////////////////////////////////////////////////////////////////////////


void quicksort(vector<int> &A, int low, int high) {
	if (low < high) {
		int p_index = partition(A, low, high);

		quicksort(A, low, p_index - 1);
		quicksort(A, p_index + 1, high);
	}
}


int partition(vector<int> &A, int low, int high) {
	int pivot = A[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) 
		if (A[j] <= pivot)
			swap(A[++i], A[j]);
	

	swap(A[i + 1], A[high]);

	return i + 1;
}














































//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//void mergesort2(vector<int> a, int n) {
//	int n = a.size();
//	if (n < 2) return;
//	int mid = n / 2;
//
//	vector<int> l(mid);
//	vector<int> r(n - mid);
//
//	for (int i = 0; i < mid - 1; i++) 
//		l[i] = a[i];
//
//	for (int i = mid; i < n - 1; i++)
//		r[i - mid] = a[i];
//
//	mergesort2(l);
//	mergesort2(r);
//
//	merge2(a, l, r,);
//}
//
//void merge2(vector<int> &a, vector<int> &l, vector<int> &r, int nL, int nR) {
//	int nL, nR, i, j, k;
//	nL = l.size();
//	nR = r.size();
//
//	i = j = k = 0;
//
//	while (i < nL && j < nR) {
//		if (l[i] <= r[j]){
//			a[k] = l[i];
//			i++;
//		}
//		else {
//			a[k] = r[j];
//			j++;
//		}
//		k++;
//	}
//	while (i < nL) {
//		a[k] = l[i];
//		i++;
//		k++;
//	}
//	while (j < nR) {
//		a[k] = r[j];
//		j++;
//		k++;
//	}
//
//}


////////////////////////////////////////////////////////////////////////////


//void MergeSort(vector<int> &a, int low, int high)
//{
//	int mid;
//	if (low < high)
//	{
//		mid = (low + high) / 2;
//		// Split the data into two half.
//		MergeSort(a, low, mid);
//		MergeSort(a, mid + 1, high);
//
//		// Merge them to get sorted output.
//		Merge(a, low, high, mid);
//	}
//}
//
//void Merge(vector<int> &a, int low, int high, int mid)
//{
//	// We have low to mid and mid+1 to high already sorted.
//	int i, j, k;
//
//	vector<int> temp(high - low + 1);
//
//	i = low;
//	k = 0;
//	j = mid + 1;
//
//	// Merge the two parts into temp[].
//	while (i <= mid && j <= high)
//	{
//		if (a[i] < a[j])
//			temp[k++] = a[i++];
//
//		else
//			temp[k++] = a[j++];
//
//	}
//
//	// Insert all the remaining values from i to mid into temp[].
//	while (i <= mid)
//		temp[k++] = a[i++];
//
//
//	// Insert all the remaining values from j to high into temp[].
//	while (j <= high)
//		temp[k++] = a[j++];
//
//
//	// Assign sorted data stored in temp[] to a[].
//	for (i = low; i <= high; i++)
//	{
//		a[i] = temp[i - low];
//	}
//}
