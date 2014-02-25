//Find median of two sorted arrays.

//Solution:
//Use the same logic we merge two sorted list, but we do not actually have to merge them, but counting numbers
//Another solution is to use the property that the median of two merged array is between the median of two arrays.
//So, every round we get two smaller array with it's number between the median two arrays in the last round. Not sure
//whether this method have better performance.

int GetMedian(int arr1[], int n1, int arr2[], int n2)
{
	assert(arr1);
	assert(arr2);
	assert(n1>0);
	assert(n2>0);

	int nNumber = (n1 + n2 + 1)/2;
	int i1 = 0;
	int i2 = 0;
	
	int nCount = 0;
	int nRet = 0;
	while (i1 < n1 && i2 < n2 && nCount != nNumber)
	{
		if (arr1[i1] < arr2[i2])
		{
			nRet = arr1[i1];
			nCount++;
			i1++;
		}
		else
			if (arr1[i1] == arr2[i2])
			{
				nRet = arr1[i1];
				nCount++;
				i1++;

				if (nCount == nNumber) break;

				nCount++;
				i1++;
			}
			else
			{
				nRet = arr2[i2];
				nCount++;
				i2++;
			}
	}

	if (nCount == nNumber) return nRet;

	if (i1 == n1)
		nRet = arr2[i2+nNumber-nCount-1];
	else
		nRet = arr1[i1+nNumber-nCount-1];

	return nRet;
}

void test()
{
	int a[] = {1};
	int b[] = {0};

	cout<<GetMedian(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int))<<endl;
}