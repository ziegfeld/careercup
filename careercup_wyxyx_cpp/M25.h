//Given an array, find the longest subarray which the sum of the subarray less or equal then the given MaxSum
//int[] FindMaxSumArray(int[] array, int maxsum)
//for example, given array: {1, -2, 4, 5, -2, 6, 7}
//maxsum=7
//the result would be: {1,-2,4, -2, 6}

//Solution:
//Num(i,n) = max{if(not larger)Num(i-1,n-n(i))+1, Num(i-1,n)}
//No DP is suitable here!! The range of the numbers may too large!!!
//Similar to knapsack problem but no DP!! The volume of a knapsack is limited, numbers are not!!

struct RECORD
{
	vector<int> vecSeq;
	int nSum;

	RECORD() { nSum = 0; }
	int GetNum() { return vecSeq.size(); }
	void InPut(int n)
	{
		vecSeq.push_back(n);
		nSum += n;
	}
};

RECORD GetSubArray(int a[], int n, int nLT)
{
	assert(a);
	assert(n>0);
	
	RECORD res;
	if (n == 1)
	{
		if (a[0] <= nLT)
			res.InPut(a[0]);
	}
	else
	{
		RECORD rec = GetSubArray(a, n-1, nLT-a[n-1]);
		res = GetSubArray(a, n-1, nLT);

		if (rec.nSum < nLT-a[n-1] && rec.GetNum()+1 > res.GetNum())
		{
			res = rec;
			res.InPut(a[n-1]);
		}
	}

	return res;
}

void test()
{
	int a[] = {1, 123, 4, 5, -2, 6, 2};
	RECORD rec = GetSubArray(a, sizeof(a)/sizeof(int), 7);
	for (vector<int>::iterator it = rec.vecSeq.begin();
		it != rec.vecSeq.end(); it++)
	cout<<*it<<endl;
}