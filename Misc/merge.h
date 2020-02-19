mergesort(vector<int> &a, int l, int r){
	int m;
	
	if(l<r){
		m = (l+r)-1;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		
		merge(a,l,r,m);
	}
}

merge(vector<int> &a, int l, int r, int m){
	int i, j, k;
	vector<int> temp(r-l+1);
	
	i = l, 
	j = m+1;
	k = 0;
	
	while (i <= m && j <= r){
		if(a[i] < a[j]
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
		}
		
	while (i <= m)
		temp[k++] = a[i++];
	while (i <= r)
		temp[k++] = a[j++];
		
	for (i = l; i <= r; i++)
		a[i] = temp[i - l)


}

