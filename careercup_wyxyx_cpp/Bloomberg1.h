//Write an algorithm to find the number 
//of six digit numbers where the sum of the first three digits is equal to the sum of the last three digits.

//Solution:
//I have a quit review of all the answers given by others and found my answer is the best one. The key here is
//to use an array to keep the number of different combinations of three digit given a certain sum. So, the next time
//dealing with the same sumation, just get the result directly from this array. This array contains 27 (1+0+0 ~ 9+9+9) elements with
//the index plus one representing the combinations of three digit with their summation same to the index plus one. A typical DP solution.


int CalcSumComb(int n)
{
	assert(n >= 1);
	assert(n <= 27);

	int nRet = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (i+j <= n && n-i-j <= 9)
				nRet++;
		}
	return nRet;
}

int CalcCombinations()
{
	int a[27];
	for (int i = 0; i < 27; i++)
		a[i] = CalcSumComb(i+1);

	int nCount = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
			{
				nCount += a[i+j+k-1];
			}

	return nCount;
}

void test()
{
	cout<<CalcCombinations()<<endl;
}