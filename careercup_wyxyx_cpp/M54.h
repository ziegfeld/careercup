//There is an array of size 'n' in which first 'a' elements are sorted in either ascending/descending order . 
//The remaining elements 'n-a' elements are again sorted in ascending/descending. 
//Find the index of the point of inflexion.If both parts are sorted in the same way return -1.

//Solution:
//We can judge the trend by checking out the first two numbers. Then, we can do the binary search.
//Every time we located a number, we judge it is in an ascending trend or an descending trend.
//If it's in ascending trend and the first half is ascending, we search the right half, wise versa.

int* _get_inflexion_pos(int a[], int n, bool bFirstAscending)
{
	if (n <= 1) return NULL;

	int i = n/2;

	//Find the left most same number
	int nLft = i;
	while (nLft-1 >= 0 && a[nLft] == a[nLft-1])
		nLft--;

	//Find the right most same number
	int nRgt = i;
	while (nRgt+1 < n && a[nRgt] == a[nRgt+1])
		nRgt++;

	int nPrev = 0==nLft ? 0 : nLft-1;
	int nMid = nLft;
	int nPost = (n-1)==nRgt ? nRgt : nRgt+1;

	//Descending
	if (a[nPrev] >= a[nMid] && a[nMid] >= a[nPost])
	{
		if (bFirstAscending)
			return _get_inflexion_pos(a, nLft+1, bFirstAscending);
		else
			return _get_inflexion_pos(a+nRgt, n-nRgt, bFirstAscending);
	}
	else if (a[nPrev] <= a[nMid] && a[nMid] <= a[nPost])
	{
		if (bFirstAscending)
			return _get_inflexion_pos(a+nRgt, n-nRgt, bFirstAscending);
		else
			return _get_inflexion_pos(a, nLft+1, bFirstAscending);
	}

	return &a[nMid];
}

int GetInflexion(int a[], int n)
{
	assert(n>0);
	if (1 == n) return -1;

	//Judge trend
	bool bFirstAscending = true;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] == a[i+1]) continue;
		if (a[i] > a[i+1])	bFirstAscending = false;

		break;
	}

	int* pPos = _get_inflexion_pos(a, n, bFirstAscending);
	if (NULL == pPos) return -1;

	return pPos - a;
}

void test()
{
	int a[] = {2,3,1,2,3,4,5,3,2,4,5,7,4,2,4,6};
	cout<<GetInflexion(a, sizeof(a)/sizeof(int))<<endl;
}