//1. There is a stream of numbers, design an effective datastructre to store the numbers and to return the median at any point of time.

//Solution:
//Maintain two heaps, one max heap and one min heap, they should always be balanced, I mean have same number of elements, 
//and all the elements in the max heap should less than the elements in the min heap. The root of the max heap is the median.
//During insertion, keep the two heap balance. Insert to the max heap and than keep the two heaps balance.

void swap(int& a, int& b)
{
	int nTmp = a;
	a = b;
	b = nTmp;
}

class CHeap
{
public:
	CHeap(int nMaxSize) : m_sz(0)
	{
		assert(nMaxSize>0);
		m_nMaxSize = nMaxSize;
		m_pHeap = new int[m_nMaxSize];
	}

	~CHeap() { delete []m_pHeap; }

public:
	bool	Insert(int n);
	bool	RemoveTop();
	int		GetCurSize() { return m_sz; }
	int		GetTop() { assert(m_sz > 0); return m_pHeap[0]; }

protected:
	virtual bool CompareRule(int nLft, int nRgt) = 0;

protected:
	int* m_pHeap;
	int	 m_nMaxSize;
	int  m_sz;
};

inline bool CHeap::Insert(int n)
{
	if (m_sz == m_nMaxSize) return false;

	m_pHeap[m_sz++] = n;

	int nIter = m_sz-1;

	while (0 != nIter && !CompareRule(m_pHeap[(nIter-1)/2], m_pHeap[nIter]))
	{
		swap(m_pHeap[(nIter-1)/2], m_pHeap[nIter]);
		nIter = (nIter-1)/2;
	}
}

inline bool CHeap::RemoveTop()
{
	if (m_sz == 0) return false;

	m_pHeap[0] = m_pHeap[m_sz-1];
	m_sz--;

	int nIter = 0;
	while (true)
	{
		if (2*nIter+1 == m_sz-1)
		{
			if (!CompareRule(m_pHeap[nIter], m_pHeap[2*nIter+1]))
			{
				swap(m_pHeap[nIter], m_pHeap[2*nIter+1]);
				nIter = 2*nIter+1;
			}
			else
				break;
		}
		else if (2*nIter+1 >= m_sz)
			break;
		else
		{
			int nComp = CompareRule(m_pHeap[2*nIter+1], m_pHeap[2*nIter+2]) ? 2*nIter+1 : 2*nIter+2;
			if (!CompareRule(m_pHeap[nIter], m_pHeap[nComp]))
			{
				swap(m_pHeap[nIter], m_pHeap[nComp]);
				nIter = nComp;
			}
			else 
				break;
		}
	}
}

class CMaxHeap : public CHeap
{
public:
	CMaxHeap(int nMaxSize) : CHeap(nMaxSize) {}

protected:
	bool CompareRule(int nLft, int nRgt) { return nLft >= nRgt; }
};

class CMinHeap : public CHeap
{
public:
	CMinHeap(int nMaxSize) : CHeap(nMaxSize) {}

protected:
	bool CompareRule(int nLft, int nRgt) { return nLft <= nRgt; }
};


class CSolution
{
public:
	CSolution(int nMaxSize) : m_MaxHeap(nMaxSize), m_MinHeap(nMaxSize)
	{}

	void Input(int n);
	int GetNumber() { return m_MaxHeap.GetCurSize() + m_MinHeap.GetCurSize(); }
	int GetMedian()
	{
		assert(GetNumber() != 0);
		return m_MaxHeap.GetTop();
	}

private:
	CMaxHeap m_MaxHeap;
	CMinHeap m_MinHeap;
};

inline void CSolution::Input(int n)
{
	if (GetNumber() == 0)
	{
		m_MaxHeap.Insert(n);
		return;
	}

	if (n > GetMedian())
		m_MinHeap.Insert(n);
	else
		m_MaxHeap.Insert(n);

	if (m_MaxHeap.GetCurSize() > m_MinHeap.GetCurSize() && 
		m_MaxHeap.GetCurSize()-m_MinHeap.GetCurSize() > 1)
	{
		int nTop = m_MaxHeap.GetTop();
		m_MaxHeap.RemoveTop();
		m_MinHeap.Insert(nTop);
	}

	if (m_MinHeap.GetCurSize() > m_MaxHeap.GetCurSize())
	{
		int nTop = m_MinHeap.GetTop();
		m_MinHeap.RemoveTop();
		m_MaxHeap.Insert(nTop);
	}
}

void test()
{
	CSolution sl(100);
	int a[] = {3,5,4,6,2,8,9,0,1,6,3,2,8,7};
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		sl.Input(a[i]);
		sort(a, a+i+1);
		
		cout<<"Array : ";
		for (int j = 0; j <= i; j++)
			cout<<a[j];
		cout<<endl;

		cout<<"Median : "<<sl.GetMedian()<<endl;
	}
}