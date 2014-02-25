//Find the longest common substring of two string

//Solution:
//Use DP to solve this problem. Build a M*N array says A, 
//A[i][j]represents the suffix length of string S1[0...i], S2[0...j]

char* LCSubString(const char* str1, const char* str2, char res[])
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(res != NULL);

	const int nLen1 = strlen(str1);
	const int nLen2 = strlen(str2);

	//Build DP record array
	int** pRec = new int*[nLen1+1];
	for (int i = 0; i < nLen1+1; i++)
	{
		pRec[i] = new int[nLen2+1];
		memset(pRec[i], 0, (nLen2+1)*sizeof(int));
	}
	
	int nMaxSuffixI = 0;
	int nMaxSuffixJ = 0;
	int nMaxSuffixLen = 0;
	for (int i = 1; i < nLen1+1; i++)
	{	
		for (int j = 1; j < nLen2+1; j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				pRec[i][j] = pRec[i-1][j-1] + 1;
				if (pRec[i][j] > nMaxSuffixLen)
				{
					nMaxSuffixLen = pRec[i][j];
					nMaxSuffixI = i;
					nMaxSuffixJ = j;
				}
			}
			else
				pRec[i][j] = 0;
		}
	}

	if (nMaxSuffixLen == 0) return "";
	int nStart = nMaxSuffixI - nMaxSuffixLen;
	for (int i = 0; i < nMaxSuffixLen; i++)
		res[i] = str1[nStart+i];
	res[nMaxSuffixLen] = '\0';

	//Destroy DP record array
	for (int i = 0; i < nLen1+1; i++)
		delete []pRec[i];
	delete []pRec;

	return res;
}

void test()
{
	char a[100];
	cout<<LCSubString("lkfsgbgsbeif", "kjkfsjh83hfjhgosdhp93WQODhf", a)<<endl;
}