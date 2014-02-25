//You're given N signed integers a[1..N].
//You need to find N correct signs s[1..N] 
//(that is, numbers s[i] = +/-1), such that
//a[1]*s[1] + a[2]*s[2] + .. + a[N]*s[N] = 0.
//Assume that the solution always exists.
//Example: a = {5, 7, 3, -8, 1};
//then the signs are: s = {1, 1, -1, 1, -1}
//because: 5 + 7 - 3 - 8 - 1 = 0
//(or symmetric solution: s = {-1, -1, 1, -1, 1})

//Solution:
//Note that initial assignments of signs is irrelevant. The problem is equivalent to
//finding a subset of numbers, whose total is half the total of all numbers
//considering their absolute values.
//
//
//In our case the total of all the numbers is 24. Half is 12. One subset, whose
//total is equal to 12 is {5, 7}. In order for the whole set to total to 0, {5, 7}
//should get one sign and the rest {3, 8, 1} the other. For example, -5-7+3+8+1=0.
//Thus the assignment of signs to 5,7,3,-8,1 should be -1,-1,1,-1,1. 

//NP complete problem, what's the answer the interviewer want?? Not sure about that!!
//http://en.wikipedia.org/wiki/NP-complete
//http://en.wikipedia.org/wiki/Partition_problem
//http://en.wikipedia.org/wiki/Subset-sum_problem
//http://baike.baidu.com/view/841810.htm

//Get the combination of subset in a positive integer array, the sum of which is 
//half the sum of every integers in the array. DP is used below, however, when sum
//is large, this method is intolerable
bool GetPartition(int a[], bool b[], int n)
{
	int nSum = 0;
	for (int i = 0; i < n; i++)
		nSum += a[i];

	if (nSum%2 == 1) return false;
	nSum = nSum/2;

	int* pRec = new int[nSum+1];
	for (int i = 0; i <= nSum; i++) 
		pRec[i] = -1;

	int nCur = 0;
	for (int i = 0; i < n; i++)
	{
		nCur += a[i];

		// note : don't cover the existed path!!!!!
		for (int j = 0; j <= (nSum<nCur ? nSum : nCur); j++)
		{
			if (j == a[i] && pRec[j] < 0) 
				pRec[j] = i;
			else
			{
				if (pRec[j] >= 0 && j+a[i] <= nSum && pRec[j+a[i]] < 0)
					pRec[j+a[i]] = i;
			}
		}
	}

	if (pRec[nSum] < 0) return false;
	int nIter = nSum;

	while (nIter != 0)
	{
		b[pRec[nIter]] = true;
		nIter = nIter - a[pRec[nIter]];
	}

	delete []pRec;
	return true;
}

void test()
{
	int a[] =	{1,3,5,6,2,1};
	bool b[] =	{false,false,false,false,false,false};

	int nsz = sizeof(a)/sizeof(int);
	if (!GetPartition(a, b, nsz))
	{
		cout<<"No subset available"<<endl;
		return;
	}

	for (int i = 0; i < nsz; i++)
	{
		if (b[i]) cout<<a[i]<<" ";
	}
	cout<<endl;
}