//Generate all subsets of a given set. In another words generate super set of a given set. Example- Given set {1,2,3}. 
//Output- {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}

void Rec(int a[], bool bpRec[], int n, int nCur)
{
	if(nCur == n)
	{
		cout<<"{";
		bool bFirst = true;
		for (int i = 0; i < n; i++)
		{
			if (bpRec[i])
			{
				if (bFirst)
				{
					cout<<a[i];
					bFirst = false;
				}
				else
					cout<<","<<a[i];
			}
		}
		cout<<"}"<<endl;
		return;
	}

	bpRec[nCur] = true;
	Rec(a, bpRec, n, nCur+1);

	bpRec[nCur] = false;
	Rec(a, bpRec, n, nCur+1);
}

void PrintSubSets(int a[], int n)
{
	assert(a);
	assert(n>0);

	bool* bSelArr = new bool[n];
	Rec(a, bSelArr, n, 0);

	delete []bSelArr;
}

void test()
{
	int a[] = {1,2,3};
	PrintSubSets(a, sizeof(a)/sizeof(int));
}