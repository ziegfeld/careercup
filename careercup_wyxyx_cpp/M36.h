//Create two evenly balanced teams for a game of soccer.
//Condition:The difference between the number of players in both teams should not differ by more than 1 . 
//Each player has skill point associated with him. The total skill point of the players on each team 
//should be as nearly equal as possible.

//Solution:
//First of all, it's not a NP complete problem you moron!!!
//lets say that the array is divided into two parts with the number of elements of each array fixed (relatively same in this problem)
//The basic idea here is given two initial parts, we can reach the final status by swapping elements, 
//swapping two elements each time to make the sum of the two parts closer until we cannot find a way two make 
//these two parts any closer by swapping.Says P1 and P2 are these two parts, Sum1 and Sum2 are the sum of the two parts and
//sum1 > sum2. For each time, we swap a from sum1 and b from sum2 to make them closer. So sum1-sum2 > |sum1-a +b-(sum2+a-b)|,
//then 0<2(a-b)<=sum1-sum2. How can we pick a and b quick?? Ofcourse from two sorted array, going through two sorted arrays once we can get a and b(figure out this by yourself). 
//The time complexity in the worset is O(n^2)

//Three points I didn't do good here.
//1.List the right inequality
//2.Didn't consider t0 handle (a[ia]-b[ib]) == sum1-sum2 properly
//3.Forgot to sort the new sub array after swapping

void swap(int& a, int& b)
{
	int nTmp = a;
	a = b;
	b = nTmp;
}

bool MakeCloser(int& sum1, int a[], const int na, int& sum2, int b[], const int nb)
{
	assert(sum1 >= sum2);

	int ia = 0;
	int ib = 0;

	bool bFound = false;
	while (true)
	{
		if (a[ia] <= b[ib] || (a[ia]-b[ib]) == sum1-sum2)
		{
			if (ia == na-1)
			{
				bFound = false;
				break;
			}

			ia++;
		}
		else
			if ((a[ia]-b[ib]) > sum1-sum2)
			{
				if (ib == nb-1)
				{
					bFound = false;
					break;
				}

				ib++;
			}
			else
			{
				bFound = true;
				break;
			}
	}

	if (bFound)
	{
		sum1 = sum1 - a[ia] + b[ib];
		sum2 = sum2 - b[ib] + a[ia];

		swap(a[ia], b[ib]);

		//for a, shift left
		while (ia != 0 && a[ia] < a[ia-1])
		{
			swap(a[ia], a[ia-1]);
			ia--;
		}

		//for b, shift right
		while (ib != nb-1 && b[ib] > b[ib+1])
		{
			swap(b[ib], b[ib+1]);
			ib++;
		}
	}

	return bFound;
}

int GetClosestPartition(int a[], int n)
{
	assert(a);
	assert(n>0);

	if (n == 1) return 0;

	sort(a, a+n);
	int nDivIndex = n/2-1;

	int nSum1 = 0;
	for (int i = 0; i < nDivIndex+1; i++)
		nSum1 += a[i];

	int nSum2 = 0;
	for (int i = 0; i < n-nDivIndex-1; i++)
		nSum2 += a[nDivIndex+1+i];

	bool bSwapped = false;
	do 
	{
		if (nSum1 > nSum2)
		{
			bSwapped = MakeCloser(nSum1, a, nDivIndex+1, nSum2, a+nDivIndex+1, n-nDivIndex-1);
		}
		else
		{
			bSwapped = MakeCloser(nSum2, a+nDivIndex+1, n-nDivIndex-1, nSum1, a, nDivIndex+1);
		}
	} 
	while (bSwapped);

	return nDivIndex;
}

void test()
{
	int a[] = {1,2,3,5,0,1,-1,-2,3,3,1};
	int nDiv = GetClosestPartition(a, sizeof(a)/sizeof(int));

	cout<<"Part A ************************************:"<<endl;
	int sum1 = 0;
	for (int i = 0; i <= nDiv; i++)
	{
		cout<<a[i]<<" ";
		sum1 += a[i];
	}
	cout<<endl;

	cout<<"Part B ************************************:"<<endl;
	int sum2 = 0;
	for (int i = nDiv+1; i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<" ";
		sum2 += a[i];
	}
	cout<<endl;
	cout<<"Difference is : "<<(sum1<sum2?sum2-sum1:sum1-sum2)<<endl;
}