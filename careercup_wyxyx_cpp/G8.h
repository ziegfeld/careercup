//You r given a large string of characters lets call it Sbig. Then there is a small set of characters lets call it Ssmall. You have to find smallest substring of Sbig which contains all characters in Ssmall.
//
//For example you are given Sbig = "hello what are you doing"
//Ssmall= "eo"
//answer is "ello"

//Solution:
//Use bit map to solve this problem. Use two 256 elements array to record the occurrence of characters in the long string and 
//the short one respectively. Then, use two iterators point to the start and the end of the longer string. Increase the start 
//iterator until there is a character not included in the scope of the two iterators. Decrease the iterator initially at the 
//end of the string in the same way to reduce the scope. At last, the sub string with in these two iterators is the answer.

char* GetSubString(const char* szLong, const char* szShort, char szSubStr[])
{
	assert(szLong);
	assert(szShort);

	int* pChL = new int[256];
	int* pChS = new int[256];

	for (int i = 0; i < 256; i++)
	{
		pChL[i] = 0;
		pChS[i] = 0;
	}

	for (int i = 0; i < 256; i++)
	{
		if (pChL[i] < pChS[i])
			return "";
	}

	const char* pIter2 = szLong;
	while ('\0' != *pIter2)
		pChL[*pIter2++]++;

	const char* pIter1 = szShort;
	while ('\0' != *pIter1)
		pChS[*pIter1++]++;
	pIter1 = szLong;
	pIter2--;

	bool bStartEnd = false;
	bool bEndEnd = false;
	while ((!bStartEnd || !bEndEnd) && pIter1 <= pIter2)
	{
		if (!bStartEnd)
		{
			pChL[*pIter1]--;
			if (pChL[*pIter1] < pChS[*pIter1])
				bStartEnd = true;
			else
				pIter1++;
		}

		if (!bEndEnd)
		{
			pChL[*pIter2]--;
			if (pChL[*pIter2] < pChS[*pIter2])
				bEndEnd = true;
			else
				pIter2--;
		}
	}

	int i = 0;
	while (pIter1 <= pIter2)
		szSubStr[i++] = *pIter1++;
	szSubStr[i] = '\0';

	return szSubStr;
}

void test()
{
	char a[1000];
	cout<<GetSubString("a", "", a)<<endl;
}