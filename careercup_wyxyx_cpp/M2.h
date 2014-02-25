//Given an unsorted array, return the first repeadted integer? 
//I gave him first the bitmap solution.. he said somebody has solved the same problem in the same way...:D... 
//but there is more simple solution. ... then i gave him the hash table solution... then code it....later tested it.

void findFirstDup(int a[], int n)
{
	int* pHash = new int[n];
	memset(pHash, 0, sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		int nIndex = a[i]%n;
		while (pHash[nIndex%n] != 0 && pHash[nIndex%n] != a[i])
			nIndex++;

		if (0 == pHash[nIndex%n]) 
		{
			pHash[nIndex%n] = a[i];
		}
		else
		{
			cout<<a[i]<<endl;
		}
	}

	delete []pHash;
}

void test()
{
	int a[] = {1,4,3,7,8,2,34,21,1};
	findFirstDup(a, sizeof(a)/sizeof(int));
}