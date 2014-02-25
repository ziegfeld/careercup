//two sorted array are given .. say A1 & A2.
//A2 has space for all the elements of A1 .
//now make a library function for finding the merged sorted array.
//O(n) time

void Merg(int a1[], int n1, int a2[], int n2)
{
	assert(n1>0);
	assert(n2>0);
	assert(a1);
	assert(a2);

	int nIter1 = n1-1;
	int nIter2 = n2-1;
	int nIter = n1+n2-1;

	while (nIter1 >= 0 && nIter2 >= 0)
	{
		if (a1[nIter1] < a2[nIter2])
		{
			a2[nIter--] = a2[nIter2--];
		}
		else
			if (a1[nIter1] > a2[nIter2])
			{
				a2[nIter--] = a1[nIter1--];
			}
			else
			{
				a2[nIter--] = a1[nIter1--];
				a2[nIter--] = a1[nIter2--];
			}
	}

	if (nIter1 < 0)
	{
		while (nIter2 >= 0)
		{
			a2[nIter--] = a2[nIter2--];
		}
	}

	if (nIter2 < 0)
	{
		while (nIter1 >= 0)
		{
			a2[nIter--] = a2[nIter1--];
		}
	}
}

void test()
{
	int a1[] = {1,3,5,7,9};
	int a2[] = {-1,4,6,8,10,12,23, 0, 0, 0, 0, 0};
	Merg(a1, sizeof(a1)/sizeof(int), a2, 7);

	for (int i = 0; i < sizeof(a2)/sizeof(int); i++)
	{
		cout<<a2[i]<<endl;
	}
}