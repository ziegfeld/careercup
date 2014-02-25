//Write an algorithm to find out how many different summations you can compute using numbers range from 1 to 1000. 2 constrains
//1) Each valid sum must be less than 10000
//2) A number can only be used once for a sum
//example:
//1+2+300 < 10000 is valid
//1+2+300+400 < 10000 is valid
//1+2+2 is not valid (2 appear twice)

//Solution:
//Typical 01 knapsack problem : S(n[i],v) = s(n[i-1],v-v[i-1])*2 || S(n[i-1],v) || S(n[i-1],v) + 1

const int CHOICE = 1000;
const int LTSUM = 10000;

int GetSumations(int nChoice, int nSum)
{
	assert(nChoice>0 && nSum>0);

	int* pRec = new int[nSum];
	for (int i = 0; i < nSum; i++)
		pRec[i] = 1;

	for (int i = 1; i < nChoice; i++)
		for (int j = nSum-1; j >= 0; j--)
		{
			int nDiff = j - i;
			if (nDiff < 0) continue;

			if (nDiff == 0) 
				pRec[j]++;
			else
				pRec[j] = pRec[nDiff]*2;
		}
	int nRet = pRec[nSum-1];

	delete []pRec;

	return nRet;
}

void test()
{
	cout<<GetSumations(CHOICE, LTSUM)<<endl;
}