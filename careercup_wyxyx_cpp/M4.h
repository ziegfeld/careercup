//code a function that returns the nth fibnocci number... coded it the most efficient way by using 3 variable... 
//Then the interviewer wrote the recursive form and asked me what are the pros
//and cons of your(iterative) approach and recursive approach.

int CalcFib(int n)
{
	if (0 == n) return 1;
	if (1 == n) return 1;

	int n1 = 1;
	int n2 = 1;
	int nRes = 0;
	for (int i = 2; i <= n; i++)
	{
		nRes = n1 + n2;
		n1 = n2;
		n2 = nRes;
	}

	return nRes;
}

