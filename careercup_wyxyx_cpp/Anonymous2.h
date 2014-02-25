//Given a collection of segments, each segment have three values, the beginning point, the end point and the
//score. Find a set of segments have the largest score but non of them is overlapped with others.

//Sort the segments by starting points, says A and ending points says B.
//Look for B from beginning to the end, for each new segment, decide whether to add
//it or not. TotalScore(n) = max{TotalScore(n-1), TotalScore(m)+Score(n)}, m is the
//max number that do not overlapped with nth segment which means m+1 to n-m are overlapped with n(th) segment

struct SEG_INFO 
{
	int nBeg;
	int nEnd;
	int nVal;

	SEG_INFO(int n1 = 0, int n2 = 0, int nv = 0) : nBeg(n1), nEnd(n2), nVal(nv)
	{}
};

class CSegCollection
{
public:
	void AddSeg(int nBeg, int nEnd, int nVal) 
	{ 
		SEG_INFO seg(nBeg, nEnd, nVal);
		m_vecSegs.push_back(seg); 
	}

	void PrintBestSegs();

private:
	void change_once(int nIndex, bool arrSel[], int arrSortedEnd[]);

private:
	vector<SEG_INFO> m_vecSegs;

private:
	class CSortEnd
	{
	public:
		CSortEnd(vector<SEG_INFO>& v) : vec(v) {}
		bool operator()(int a, int b)
		{
			return vec[a].nEnd < vec[b].nEnd;
		}
	private:
		vector<SEG_INFO>& vec;
	};
};

inline void CSegCollection::PrintBestSegs()
{
	if (m_vecSegs.empty())
		return;

	int* arrSortBeg = new int[m_vecSegs.size()];
	int* arrSortEnd = new int[m_vecSegs.size()];
	bool* arrSel = new bool[m_vecSegs.size()];

	for (int i = 0; i < m_vecSegs.size(); i++)
	{
		arrSortBeg[i] = i;
		arrSortEnd[i] = i;
		arrSel[i] = false;
	}

	CSortEnd SEnd(m_vecSegs);
	sort(arrSortEnd, arrSortEnd+m_vecSegs.size(), SEnd);

	for (int i = 0; i < m_vecSegs.size(); i++)
		change_once(i, arrSel, arrSortEnd);

	cout<<"*********** Best arranged segments ***********"<<endl;
	for (int i = 0; i < m_vecSegs.size(); i++)
	{
		if (arrSel[i])
		cout<<"Begin : "<<m_vecSegs[arrSortEnd[i]].nBeg<<" End : "
			<<m_vecSegs[arrSortEnd[i]].nEnd<<" Value : "<<m_vecSegs[arrSortEnd[i]].nVal<<endl;
	}
	cout<<"********************* End ********************"<<endl;

	delete []arrSel;
	delete []arrSortBeg;
	delete []arrSortEnd;
}

inline void CSegCollection::change_once(int nIndex, bool arrSel[], int arrSortedEnd[])
{
	int nCurVal = 0;
	for (int i = 0; i < nIndex; i++)
	{
		if (arrSel[i])
			nCurVal += m_vecSegs[arrSortedEnd[i]].nVal;
	}

	vector<int> vecFliped;
	int nNewVal = nCurVal;
	int nLookFor = nIndex-1;
	while (nLookFor >= 0)
	{
		if (arrSel[nLookFor] && m_vecSegs[arrSortedEnd[nLookFor]].nEnd > m_vecSegs[arrSortedEnd[nIndex]].nBeg)
		{
				nNewVal -= m_vecSegs[arrSortedEnd[nLookFor]].nVal;
				vecFliped.push_back(nLookFor);
		}
		nLookFor--;
	}
	nNewVal += m_vecSegs[arrSortedEnd[nIndex]].nVal;

	if (nNewVal > nCurVal)
	{
		for (vector<int>::iterator it = vecFliped.begin(); it != vecFliped.end(); it++)
			arrSel[*it] = false;
		arrSel[nIndex] = true;
	}
}

void test()
{
	CSegCollection segCol;
	segCol.AddSeg(1,3,3);
	segCol.AddSeg(4,6,1);
	segCol.AddSeg(5,6,2);
	segCol.AddSeg(0,2,2);
	segCol.AddSeg(8,10,3);
	segCol.AddSeg(6,8,1);

	segCol.PrintBestSegs();
}