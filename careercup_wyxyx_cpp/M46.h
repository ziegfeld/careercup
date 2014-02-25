//Represent IP address in string form as integer
//Solution:
//Quite easy one, one integer is composed by 4 parts of 8-bit, and 8 bit can represent
//value from 0 to 255, which is the numeric range of a segment in an IP address

bool ConvertIpToInt(const char* szIP, int& nRes)
{
	assert(szIP);
	int arrSegInt[4];
	memset(arrSegInt, 0, sizeof(arrSegInt));

	int nCurSegVal = -1;
	int nCurSegIndex = 0;
	while (true)
	{
		if (*szIP == '.' || *szIP == '\0')
		{
			// segment end
			if (-1 == nCurSegVal || nCurSegIndex > 3 || nCurSegVal > 255) 
				return false;

			arrSegInt[nCurSegIndex++] = nCurSegVal;
			nCurSegVal = -1;

			if (*szIP == '\0') break;
		}
		else if (*szIP >= '0' && *szIP <= '9')
		{
			int n = *szIP - '0';
			if (n == 0 && *(szIP+1) != '\0' && *(szIP+1) != '.')
				return false;

			if (-1 == nCurSegVal) nCurSegVal = 0;
			nCurSegVal = nCurSegVal*10 + n;
		}
		else return false;

		szIP++;
	}

	if (nCurSegIndex != 4)
		return false;

	nRes = 0;
	for (int i = 0; i < 4; i++)
		nRes += arrSegInt[i] << ((3-i)*8);

	return true;
}

void test()
{
	int nVal = 0;
	bool b = ConvertIpToInt("9.81.1.123", nVal);

	if (!b)
		cout<<"Invalidate Ip address"<<endl;
	else
		cout<<nVal<<endl;
}