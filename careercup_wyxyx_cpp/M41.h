//Convert a Roman Numeral string to Decimal. algorithm? code? Test cases?

//Solution:
//I=1 V=5 X=10 L=50 C=100 D=500 M=1000
//unit digit : 1=>I 2=>II 3=>III 4=>IV 5=>V 6=>VI 7=>VII 8=>VIII 9=>IX
//Roman number rules : http://baike.baidu.com/view/42061.htm

int ConvChr(char c)
{
	if (c == 'i' || c == 'I') return 1;
	if (c == 'v' || c == 'V') return 5;
	if (c == 'x' || c == 'X') return 10;
	if (c == 'l' || c == 'L') return 50;
	if (c == 'c' || c == 'C') return 100;
	if (c == 'd' || c == 'D') return 500;
	if (c == 'm' || c == 'M') return 1000;
	if (c == '\0') return 0;

	return -1;
}

int _inner_conv(const char* szRomNum)
{
	assert(szRomNum);
	if (*szRomNum == 0) return 0;

	if (ConvChr(*szRomNum) == -1)
		throw "Invalid character found! \n";

	if (ConvChr(*szRomNum) < ConvChr(*(szRomNum+1)))
		return _inner_conv(szRomNum+1)-ConvChr(*szRomNum);
	else
		return ConvChr(*szRomNum)+_inner_conv(szRomNum+1);
}

bool ValidityCheck(const char* szRomNum)
{
	while (*szRomNum != 0)
	{
		//Continuous numbers of I,X,C can not exceed three
		if ((ConvChr(*szRomNum) == 1 || ConvChr(*szRomNum) == 10 || ConvChr(*szRomNum) == 100)
			&& strlen(szRomNum) > 3)
		{
			if (ConvChr(*szRomNum) == ConvChr(*(szRomNum+1)) == ConvChr(*(szRomNum+2)) == ConvChr(*(szRomNum+3)))
				return false;
		}

		if (ConvChr(*szRomNum) < ConvChr(*(szRomNum+1)))
		{
			if (ConvChr(*szRomNum) == 5 || ConvChr(*szRomNum) == 50 || ConvChr(*szRomNum) == 500)
				return false;

			if (ConvChr(*szRomNum) == 1 && ConvChr(*(szRomNum+1)) != 5 && ConvChr(*(szRomNum+1)) != 10)
				return false;

			if (ConvChr(*szRomNum) == 10 && ConvChr(*(szRomNum+1)) != 50 && ConvChr(*(szRomNum+1)) != 100)
				return false;

			if (ConvChr(*szRomNum) == 100 && ConvChr(*(szRomNum+1)) != 500 && ConvChr(*(szRomNum+1)) != 1000)
				return false;
		}

		szRomNum++;
	}

	return true;
}

int RomanToDecimal(const char* szRomNum)
{
	assert(szRomNum);
	if (*szRomNum == 0)
		throw "Empty string! \n";

	if (!ValidityCheck(szRomNum))
		throw "Invalid syntax! \n";

	return _inner_conv(szRomNum);
}

void test()
{
	try
	{
		cout<<RomanToDecimal("MCMLXXVI")<<endl;
	}
	catch (const char* szExp)
	{
		cout<<szExp<<endl;
	}
}