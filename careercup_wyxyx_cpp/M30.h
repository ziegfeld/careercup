//Program the quick sort algorithm

void QuickSort(int a[], int n)
{
	assert(a);
	if (n <= 1) return;

	int nBeg = 0;
	int nEnd = n-1;

	bool bBeg = true;
	while (nBeg != nEnd)
	{
		if (bBeg)
		{
			if (a[nEnd] < a[nBeg])
			{
				int nTemp = a[nEnd];
				a[nEnd] = a[nBeg];
				a[nBeg] = nTemp;

				bBeg = false;
			}
			else
				nEnd--;
		}
		else
		{
			if (a[nEnd] < a[nBeg])
			{
				int nTemp = a[nEnd];
				a[nEnd] = a[nBeg];
				a[nBeg] = nTemp;

				bBeg = true;
			}
			else
				nBeg++;
		}
	}

	QuickSort(a, nBeg);
	QuickSort(a+nBeg+1, n-nBeg-1);
}

void test()
{
	int a[] = {10, 3, 2, -1, 54, 23, -43, 214};
	QuickSort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<endl;
	}
}