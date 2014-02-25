//Given a sorted array (ex. {1,2,3,4,5,6,7,8}). A random number from the array is taken and put the left side
//array to right side and left side array to right side.
//in the example; if 6 is randomly taken, the array will become like {7,8,6,1,2,3,4,5}
//Question:
//Given the above mangled array, write a searching algorithm to find a number present or not. 
//That algo should not be of O(n) solution.

//Find the pivot at first, this will cost O(logn).
//Notice the pivot should less than the first element and larger than the last element.
//So, this property makes a rule for binary search.
//Binary search on the appropriate sub array.

bool NumberInPivotedArr(int a[], int n, int num)
{
	assert(a);
	assert(n>0);
	
	int nLT = a[0];
	int nGT = a[n-1];

	int nBeg = 0;
	int nEnd = n-1;
	while (nBeg <= nEnd)
	{
		int nMid = (nBeg+nEnd)/2;

		if (a[nMid] >= nGT && a[nMid] <= nLT)
			break;

		if (a[nMid] >= nGT)
			nBeg = nMid+1;
		else
			nEnd = nMid-1;
	}

	if (nBeg > nEnd) return false;

	int nPivot = (nBeg+nEnd)/2;

	if (a[nPivot] == nLT || a[nPivot] == nGT)
	{
		int nDec = nPivot;
		int nInc = nPivot;

		while (nDec >= 0 || nInc < n)
		{
			if (nDec >= 0 && a[nDec--] > a[nPivot])
			{
				nPivot = nDec+2;
				break;
			}

			if (nInc < n && a[nInc++] < a[nPivot])
			{
				nPivot = nInc-2;
				break;
			}
		}
	}

	if (a[nPivot] == num)
		return true;

	nBeg = 0;
	nEnd = n-1;
	if (num < a[nPivot])
		nBeg = nPivot+1;
	else
		nEnd = nPivot-1;

	while (nBeg <= nEnd)
	{
		int nMid = (nBeg+nEnd)/2;

		if (a[nMid] == num)
			return true;

		if (a[nMid] > num)
			nEnd = nMid-1;
		else
			nBeg = nMid+1;
	}

	return false;
}

void test()
{
	int a[] = {1,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout<<NumberInPivotedArr(a, sizeof(a)/sizeof(int), 3)<<endl;
}