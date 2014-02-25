//Divide a list of numbers into group of consecutive numbers but their original order should be preserved?
//8,2,4,7,1,0,3,6
//2,4,1,0,3 and 8,7,6
//obviously in shortest time and space.

//Solution:
//This problem can be solved in O(n) time complexity, however, O(n) space complexity is also required
//Firstly, you need to build a hash map so you can get the index of a given number in the original array in O(1)
//Then, allocate an other array, says A, with the size same to the array given in the question, this array is used to
//store the group id of each element in the given array. 
//travel through the first element in the given array to the last. For each element, see if its consecutive numbers is
//existed in the given array using the hash map just built. For example, says the number is 3, if 3 is not given a group id
//(check this from array A in which each element represent the group id of the corresponding number in the given array, O(1)) 
//you need to see if 2 or 4 is
//in the given array, if it is, you need to mark the indexes of the consecutive numbers in array A to the same group id. You do this
//by extent the current number to both sides to find consecutive numbers. After the value of each element in array A is assigned, the 
//problem is solved

#include <hash_map>
using namespace stdext;
void OutPutConsecutive(int a[], int n)
{
	int* pGroupRec = new int[n];
	for (int i = 0; i < n; i++)
		pGroupRec[i] = -1;

	// input number index to hash table
	hash_map<int,int> hashMap;
	for (int i = 0; i < n; i++)
		hashMap[a[i]] = i;

	int nGroupID = 0;
	for (int i = 0; i < n; i++)
	{
		if (pGroupRec[i]>=0) continue;
		pGroupRec[i] = nGroupID;

		bool bDec = true;
		int nDec = a[i]-1;
		bool bInc = true;
		int nInc = a[i]+1;

		while (bDec || bInc)
		{
			if (bInc)
			{
				if (hashMap.find(nInc) == hashMap.end())
					bInc = false;
				else
				{
					pGroupRec[hashMap[nInc]] = nGroupID;
					nInc++;
				}
			}

			if (bDec)
			{
				if (hashMap.find(nDec) == hashMap.end())
					bDec = false;
				else
				{
					pGroupRec[hashMap[nDec]] = nGroupID;
					nDec--;
				}
			}
		}
		nGroupID++;
	}

	for (int i = 0; i < n; i++)
		cout<<pGroupRec[i]<<" ";
	cout<<endl;

	delete []pGroupRec;
}

void test()
{
	int a[] = {2,6,4,5,1,8,0,12,9,10};
	OutPutConsecutive(a, sizeof(a)/sizeof(int));
}