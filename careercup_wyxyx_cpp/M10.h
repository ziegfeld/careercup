//Given n non overlapping intervals and an element. 
//Find the interval into which this element falls.

//Soluton:
//Binary sort first, then you can get the solution in O(logn) time complexity 

struct INTERVAL 
{
	int nBeg;
	int nEnd;
	INTERVAL(int n1=0, int n2=0)
	{
		nBeg = n1<n2?n1:n2;
		nEnd = n1>n2?n1:n2;
	}

	bool IsIn(int n)
	{ return (n>=nBeg && n<=nEnd);}
};

class CSortInterval
{
public:
	bool operator()(const INTERVAL& itvl1, const INTERVAL& itvl2)
	{
		return itvl1.nBeg < itvl1.nBeg;
	}
};

class CIntervalSet
{
public:
	CIntervalSet() { m_bSorted=false; }
	void AddInterval(const INTERVAL& intvl) { m_vecIntvls.push_back(intvl); m_bSorted = false;}
	void SortInterval() 
	{ 
		sort(m_vecIntvls.begin(), m_vecIntvls.end(), CSortInterval());
		m_bSorted = true;
	}

	bool GetInerval(int n, INTERVAL& val)
	{
		if (m_vecIntvls.empty()) return false;
		if (!m_bSorted) SortInterval();
		
		int nLftIndex = 0;
		int nRgtIndex = m_vecIntvls.size()-1;
		while (nLftIndex<=nRgtIndex)
		{
			int nMid = nLftIndex+(nRgtIndex-nLftIndex)/2;
			if (m_vecIntvls.at(nMid).IsIn(n))
			{
				val = m_vecIntvls.at(nMid);
				return true;
			}
			
			if (m_vecIntvls.at(nMid).nBeg < n)
			{
				nLftIndex = nMid+1;
			}
			else
			{
				nRgtIndex = nMid-1;
			}
		}

		return false;
	}

private:
	vector<INTERVAL> m_vecIntvls;
	bool m_bSorted;
};

void test()
{
	CIntervalSet invSet;
	invSet.AddInterval(INTERVAL(1,3));
	invSet.AddInterval(INTERVAL(5,7));
	invSet.AddInterval(INTERVAL(9,12));
	invSet.AddInterval(INTERVAL(13,33));
	invSet.AddInterval(INTERVAL(35,53));
	invSet.AddInterval(INTERVAL(55,64));
	invSet.AddInterval(INTERVAL(67,78));

	INTERVAL val;
	if (invSet.GetInerval(66,val))
	{
		cout <<val.nBeg<<"<=====>"<<val.nEnd<<endl;
	}
}