//Write string match pattern like : "A*BB??C" matchs "AXXXBBXXC"

bool _inner_match(const char* szPattern, const char* szString)
{
	assert(szPattern);
	assert(szString);

	if (*szPattern == 0 && *szString == 0)
		return true;

	if (*szPattern == '*')
	{
		while(*szPattern == '*') szPattern++;
		if (*szPattern == 0)
			return true;

		while (*szString != 0)
		{
			if (_inner_match(szPattern, szString++)) 
				return true;
		}

		return false;
	}
	else
		if (*szPattern == '?' || *szPattern == *szString)
		{
			return _inner_match(szPattern+1, szString+1);
		}
		else
			return false;
}

//Function does not trim the blanks
bool MatchPattern(const char* szPattern, const char* szString)
{
	assert(szString);
	assert(szPattern);

	const char* pPat = szPattern;
	//Blanks and empty pattern matches every string
	bool bPureBlank = true;
	while (*pPat != 0)
	{
		if (*pPat++ != ' ')
		{
			bPureBlank = false; 
			break;
		}
	}

	if (bPureBlank) return true;

	return _inner_match(szPattern, szString);
}

void test()
{
	assert(MatchPattern("ccc", "ccc"));
	assert(MatchPattern("ccc*", "ccc"));
	assert(MatchPattern("*ccc", "ccc"));
	assert(MatchPattern("*ccc*", "ccc"));
	assert(MatchPattern("*a*bc*", "abc"));
	assert(MatchPattern("*a****?**?*", "abc"));
	assert(MatchPattern("a?c", "abc"));
	assert(MatchPattern("??c", "abc"));
	assert(MatchPattern("???", "abc"));

	//negative cases
	assert(!MatchPattern("*???c", "abc"));
	assert(!MatchPattern("*acb", "abc"));
	assert(!MatchPattern("*a?b*", "abc"));
	assert(!MatchPattern("*acb?", "abc"));
}