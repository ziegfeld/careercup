//You are given a String number containing the digits of a
//phone number (the number of digits, n, can be any positive integer) . To help you memorize
//the number, you want to divide it into groups of contiguous digits. Each group must contain
//exactly 2 or 3 digits. There are three kinds of groups:
//• Excellent: A group that contains only the same digits. For example, 000 or 77.
//• Good: A group of 3 digits, 2 of which are the same. For example, 030, 229 or 166.
//• Usual: A group in which all the digits are distinct. For example, 123 or 90.
//The quality of a group assignment is defined as
//2 × (number of excellent groups) + (number of good groups)
//Divide the number into groups such that the quality is maximized. Design an efficient
//algorithm to return the solution that maximizes the quality.

//Solution:
//Dynamic programming : f(n) = max { v(n, n-1, n-2)+f(n-3); v(n, n-1)+f(n-2) }

int ctoa(char c)
{
	if (c == 0) return -1;

	int ret = c-'0';
	if (ret < 0 || ret > 9)
		return -1;
	return ret;
}

int CalcTwo(int a, int b)
{
	assert(a >= 0 && a <= 9);
	assert(b >= 0 && b <= 9);

	return a==b ? 2 : 0;
}

int CalcThree(int a, int b, int c)
{
	assert(a >= 0 && a <= 9);
	assert(b >= 0 && b <= 9);
	assert(c >= 0 && c <= 9);

	if (a == b && b == c) return 2;
	if (a == b && b != c) return 1;
	if (a == c && b != c) return 1;
	if (b == c && a != b) return 1;

	return 0;
}

int GetMaxValue(const char* szNumber)
{
	assert(strlen(szNumber) >= 2);
	int nStrLen = strlen(szNumber);

	if (nStrLen == 2) 
		return CalcTwo(ctoa(*szNumber), ctoa(*(szNumber+1)));
	if (nStrLen == 3) 
		return CalcThree(ctoa(*szNumber), ctoa(*(szNumber+1)), ctoa(*(szNumber+2)));

	int* arrValue = new int[nStrLen];
	memset(arrValue, 0, nStrLen);

	arrValue[1] = CalcTwo(ctoa(*szNumber), ctoa(*(szNumber+1)));
	arrValue[2] = CalcThree(ctoa(*szNumber), ctoa(*(szNumber+1)), ctoa(*(szNumber+2)));
	arrValue[3] = CalcTwo(ctoa(*szNumber), ctoa(*(szNumber+1))) + CalcTwo(ctoa(*(szNumber+2)), ctoa(*(szNumber+3)));

	for (int i = 4; i < nStrLen; i++)
	{
		arrValue[i] = max(arrValue[i-2]+CalcTwo(ctoa(szNumber[i]), ctoa(szNumber[i-1])), 
			arrValue[i-3]+CalcThree(ctoa(szNumber[i]), ctoa(szNumber[i-1]), ctoa(szNumber[i-2])));
	}

	int nRet = arrValue[nStrLen-1];
	delete[] arrValue;

	return nRet;
}

void test()
{
	cout<<GetMaxValue("0012343")<<endl;
}