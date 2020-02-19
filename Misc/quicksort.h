void quicksort(vector<int> &A, int low, int high) {
	if (low < high) {
		int p_index = partition(A, low, high);

		quicksort(A, low, p_index - 1);
		quicksort(A, p_index + 1, high);
	}
}


int partition(vector<int> &A, int low, int high)
{
	int pivot = A[high];
	int temp = 0;
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (A[j] <= pivot)
		{
			//	Swap
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	temp = A[i + 1];
	A[i + 1] = A[high];
	A[high] = temp;

	return i + 1;
}