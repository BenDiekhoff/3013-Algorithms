void insertion(vector<int> &a){
	int size = a.size();
	for( int i = 1; i < size; i++){
		int ind = i;
		int val = a[i];
		
		while (ind > 0 && a[ind-1] > val){
			a[ind] = a[ind-1]
			ind--;
		}
		a[ind] = val;
		
	