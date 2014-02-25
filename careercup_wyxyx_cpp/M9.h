//Given a string and print the words which have the same exact letters. Space is the only seperator.
//For example, abc bbe bca derwe eeb
//it will print abc bca.
//abc bbe abcd derwe eeb will print nothing.

//Solution 1:
//Sort the words

//Solution 2:
//Hash table, notice that the hash function should disregard the order of the characters in a word

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct STR_PAIR 
{
	string strOrig;
	string strCur;

	void clear() { strOrig = strCur = ""; }
};

class Compare
{
public:
	bool operator() (const STR_PAIR& p1, const STR_PAIR& p2)
	{
		return p1.strCur < p2.strCur;
	}
};

void FindDups(char* pStr)
{
	assert(pStr);
	char* pIter = pStr;

	vector<STR_PAIR> vec;
	STR_PAIR pair;
	char tmp[256];
	memset(tmp, 0, 256);
	while(*pIter != '\0')
	{
		if (*pIter == ' ')
		{
			pIter++;
			continue;
		}
		
		pair.strOrig += *pIter;
		tmp[*pIter++]++;
		if (*pIter == ' ' || *pIter == '\0')
		{
			for (int i = 0; i < 256; i++)
			{
				while (tmp[i] > 0)
				{
					pair.strCur += i;
					tmp[i]--;
				}
			}

			vec.push_back(pair);
			pair.clear();
			memset(tmp, 0, 256);
		}
	}
	
	sort(vec.begin(), vec.end(), Compare());
	for (vector<STR_PAIR>::iterator it = vec.begin(); it != vec.end()-1; it++)
	{
		if (it->strCur == (it+1)->strCur)
			cout<<it->strOrig<<" = "<<(it+1)->strOrig<<endl;
	}
}

void test()
{
	char str[] = "abc cdds bac ddf dfd aac";
	FindDups(str);
}