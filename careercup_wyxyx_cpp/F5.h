//Write code for finding length of largest monotonically increasing sequence in an array of integers.
//Optimize it (not the usual O(n) in worst case, but a better approach in average case).

//Solution1:
//Divided and conquer. Take one number to record the current maximum number found, start from the middle of the
//array and check to left and right to find the monotonically increasing sequence containing it and update the
//recording maximum length. Then do the same thing to the left part and right part if they are larger than the
//recording maximum length.

void _getMaximumIncSeq(int a[], int n, int& nMaxLen, int& nMaxStart)
{
	if (n <= nMaxLen) return;
	assert(a);

	int nLeft = n/2;
	int nRight = n/2;

	while (nLeft-1 >= 0 && a[nLeft] >= a[nLeft-1])
		nLeft--;
	while (nRight+1 < n && a[nRight] <= a[nRight+1])
		nRight++;

	if (nRight-nLeft+1 > nMaxLen)
	{
		nMaxLen = nRight-nLeft+1;
		nMaxStart = nLeft;
	}

	_getMaximumIncSeq(a, nLeft+1, nMaxLen, nMaxStart);
	_getMaximumIncSeq(a+1+nRight, n-1-nRight, nMaxLen, nMaxStart);
}

void PrintSeq1(int a[], int n)
{
	int nMaxLen = 1;
	int nMaxStart = 0; 
	_getMaximumIncSeq(a, n, nMaxLen, nMaxStart);

	for (int i = nMaxStart; i < nMaxStart+nMaxLen; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void test()
{
	int a[] = {1,3,2,4,5,6,7,8,9,3,2,4,6,3,4,6,8,3,4,5,8,9,4,2};
	PrintSeq1(a, sizeof(a)/sizeof(int));
}