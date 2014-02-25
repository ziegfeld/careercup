//Sort array containing only 0, 1, 2

//Solution:
//The idea is to swap the 0s to the left side and the 2s to the right side, the 1s are left in the middle.

void Sort012(int a[], int n)
{
	assert(a);
	assert(n>0);

	int nBeg = 0;
	int nEnd = n-1;
	for (int i = 0; i <= nEnd;)
	{
		if (a[i] == 0)
		{
			//swap a[i] and a[nBeg] i++ nBeg++
			int nTemp = a[i];
			a[i] = a[nBeg];
			a[nBeg] = nTemp;

			i++;
			nBeg++;
		}
		else if (a[i] == 2)
		{
			//swap a[i] and a[nEnd] nEnd--
			int nTemp = a[i];
			a[i] = a[nEnd];
			a[nEnd] = nTemp;

			nEnd--;
		}
		else if (a[i] == 1)
		{
			i++;
		}
		else
			throw "Values should be 0, 1 or 2! \n";
	}
}

void test()
{
	int a[] = {1,0,2,2,1,1,1,0,0,2,1,2};
	Sort012(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<endl;
	}
}