//Given an integer array A,
//find the max item A[i].
//A[i]=A[x]+A[y].
//O(nlog(n)) or O(n^2)

//Solution:
//Sort the array at first, in an increase order.(This took O(nlogn))
//Then search i from the back of the sorted array to see wether the number
//is the sum of other two number. The one we found firstly is the number we want.
//The way we judge wether a given number in the sorted array is the sum of other two number is easy,
//it only took O(n) time complexity to do this. Says the number we want to find is the nth element in the
//sorted array. We start by two indexes, the zero and the n-1. If the sum of the two iterators is less than
//the nth number, increase the small index by one, vice versa.

#include <algorithm>
using namespace std;

void GetTheLgstSumNum(int a[], int n)
{
	sort(a, a+n);

	bool bFound = false;
	for (int i = n-1; i >= 0 && !bFound; i--)
	{
		int nBeg = 0;
		int nEnd = i-1;

		if (nEnd <= nBeg) break;
		while (nEnd > nBeg)
		{
			if (a[nBeg]+a[nEnd] == a[i])
			{
				bFound = true;
				cout<<a[i]<<" = "<<a[nBeg]<<" + "<<a[nEnd]<<endl;
				break;
			}
			else if (a[nBeg]+a[nEnd] > a[i])
					nEnd--;
			else nBeg++;
		}
	}
}

void test()
{
	int a[] = {1,4,3,5,9,34,32,4,3,14,13,12};
	GetTheLgstSumNum(a, sizeof(a)/sizeof(int));
}