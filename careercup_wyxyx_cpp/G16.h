//Find the nth number which is composed by factor 2, 3 and 5

//Solution:
//The basic principal is that the nth number is the smallest number of all the previous
//n-1 number multiple 2, 3 or 5. It's based on previous results. So, I have two methods

//The first, for every round, we check all previous numbers, multiple them with 2,3 or 5
//. Find the smallest number just bigger than the n-1 th number. To optimize this, we do not
// really need to multiple all previous n-1 numbers, we keep three pointers, each time we find
// got a new result, we update the corresponding pointer, so the pointer is actually moving forward.
//For example, says i2 is the current pointer for 2, if we found a[j]*2 is the current result, i2 is updated to j.

//The second, make a BST, each round, remove the smallest says x, and insert x*2, x*3, x*5 to the min heap. we keep
// track of the times we inserted into this heap(don't count the duplicated), untill we reach n, then the largest number 
//in this BST is the result.

//The code for the first solution is given below:

int ReturnNth(int n)
{
	assert(n>0);

	if (1 == n) return 2;
	if (2 == n) return 3;
	if (3 == n) return 4;
	if (4 == n) return 5;

	int* pRes = new int[n];
	pRes[0] = 2;
	pRes[1] = 3;
	pRes[2] = 4;
	pRes[3] = 5;

	int i2 = 0;
	int i3 = 0;
	int i5 = 0;

	int nCur = 4;
	while (nCur < n)
	{
		while (i2 < nCur && pRes[i2]*2 <= pRes[nCur-1])
			i2++;
		while (i3 < nCur && pRes[i3]*3 <= pRes[nCur-1])
			i3++;
		while (i5 < nCur && pRes[i5]*5 <= pRes[nCur-1])
			i5++;

		int nMin = pRes[i2]*2<pRes[i3]*3 ? pRes[i2]*2 : pRes[i3]*3;
		nMin = nMin<pRes[i5]*5 ? nMin : pRes[i5]*5;

		pRes[nCur++] = nMin;
	}

	int nRes = pRes[n-1];
	delete []pRes;

	return nRes;
}

void test()
{
	cout<<ReturnNth(8)<<endl;
}