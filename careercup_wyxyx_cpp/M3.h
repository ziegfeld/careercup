//REverse the words of a string.. Code it and write test cases.. 

//Solution:
//Reverse the whole string at first.
//Then, reverse each segment divided by space respectively

char* ReverseWords(char* pStr)
{
	assert(pStr);

	char* pStart = pStr;
	char* pEnd = pStr+strlen(pStr)-1;
	while (pStart < pEnd)
	{
		char tmp = *pStart;
		*pStart = *pEnd;
		*pEnd = tmp;
		pStart++;
		pEnd--;
	}

	char* pIter = pStr;
	pStart = pStr;
	while (*pIter != '\0')
	{
		if (*pIter == ' ') 
		{
			pStart = pIter+1;
		}
		else if (*(pIter+1) == ' ' || *(pIter+1) == '\0')
		{
			pEnd = pIter;
			while (pStart < pEnd)
			{
				char tmp = *pStart;
				*pStart = *pEnd;
				*pEnd = tmp;
				pStart++;
				pEnd--;
			}
		}

		pIter++;
	}

	return pStr;
}

void test()
{
	char a[] = "Microsoft google facebook sony IBM";
	cout<<ReverseWords(a)<<endl;
}