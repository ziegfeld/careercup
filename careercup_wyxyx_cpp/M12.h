//Given an array of positive and negative integers, re-arrange it 
//so that you have postives on one end and negatives on the other, 
//BUT retain the original order of appearance. 
//For eg. 1, 7, -5, 9, -12, 15 => -5, -12, 1, 7, 9, 15

// There is a solution which took O(n) space and O(n) time which is simple
// Below is a solution which adopt the concept of merge so the time cost is 
// O(nlogn) and space O(1)
// Below is the merge sort solution, notice that if you want to turn -1,-2,3,4,5
// to 3,4,5,-1,-2, you need to reverse the whole array, that's to 5,4,3,-2,-1; and for 
// the two segment, reverse each segment back. So, first reversion come to 3,4,5,-2,-1,
// last reversion come to 3,4,5,-1,-2 which is the resilt you want

void Rearrange(int a[], int n)
{
	assert(n>0);
	if (1 == n) return;

	if (2 == n)
	{
		if (a[0]>=0 && a[1]<0)
		{
			int tmp = a[0];
			a[0] = a[1];
			a[1] = tmp;
		}

		return;
	}

	int nLft = n/2;
	int nRgt = n-nLft;
	int* pLft = a;
	int* pRgt = a+nLft;
	Rearrange(pLft, nLft);
	Rearrange(pRgt, nRgt);

	int* pIterL = pLft;
	int* pIterR = pRgt;
	while (*pIterL < 0 && pIterL-pLft<nLft) pIterL++;
	while (*pIterR < 0 && pIterR-pRgt<nRgt) pIterR++;
	
	pIterR--;
	int* pTmpL = pIterL;
	int* pTmpR = pIterR;
	while (pTmpL < pTmpR)
	{
		int tmp = *pTmpL;
		*pTmpL = *pTmpR;
		*pTmpR = tmp;
		pTmpL++;
		pTmpR--;
	}

	int* pIterLEnd = pIterL+(pIterR-pRgt);
	int* pIterRBeg = pIterLEnd+1;
	pTmpL = pIterL;
	pTmpR = pIterLEnd;
	while (pTmpL < pTmpR)
	{
		int tmp = *pTmpL;
		*pTmpL = *pTmpR;
		*pTmpR = tmp;
		pTmpL++;
		pTmpR--;
	}

	pTmpL = pIterRBeg;
	pTmpR = pIterR;
	while (pTmpL < pTmpR)
	{
		int tmp = *pTmpL;
		*pTmpL = *pTmpR;
		*pTmpR = tmp;
		pTmpL++;
		pTmpR--;
	}
}

void test()
{
	int a[] = {1,-3, 56, 7, -5, 9, -12, 15};
	Rearrange(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}