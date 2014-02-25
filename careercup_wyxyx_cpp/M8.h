//In MS Excel, the column numbers are named as A, B, C, ......, Z. 
//If you go beyond this 'Z' column you will encounter AA-->AZ, BA-->BZ, .... ZA-->ZZ then AAA-->AAZ, ABA-->ABZ, 
//........ and you can imagine how long this sequence can go! The question was to write a function which takes 
//in a positive integer and returns the character set at that column. For example: if column number is 26 my 
//function must return 'AA' (0-based index).

//Solution:
//Just like to translate a decimal number to a number which base is 26

char* GetLabel(int n, char szRet[])
{
	assert(n>=0 && szRet);

	int nSuffix = n%26;
	int nAs = n/26;

	int i = 0;
	for (; i < nAs; i++) 
		szRet[i] = 'A';
	szRet[i++] = 'A'+ nSuffix;
	szRet[i++] = '\0';

	return szRet;
}

void test()
{
	char a[100];
	cout<<GetLabel(256, a)<<endl;
}