//Given array A and B, write a function to find the smallest window in A that covers all numbers in B
//Solution:
//Design a hash table to record all the number and their occurence in B. Go through A while checking 
//whether current number is in the hash table and also record its occurence for A. Read all node in
//the hash table, for each node(which represent a number in B), the occurence in A should large or equal than occurence in B.
//Then, judge the threshold of left side and the right side by decreasing the occurence of the current number in A, if the current
//number is in the hash table and equal to the occurence in B, then the shreshold is met here.

struct HASH_NODE 
{
	int nVal;
	int nFreqA;
	int nFreqB;
	HASH_NODE* pNodeNxt;
	
	HASH_NODE(int n) : nVal(n), nFreqA(0), nFreqB(1), pNodeNxt(NULL)
	{}
};

class CHashLnk
{
public:
	CHashLnk(int n);
	~CHashLnk();

public:
	void AddNumberInB(int n);
	void AddNumberInA(int n);
	bool RemoveNumberInA(int n);
	bool JudgeAcontainB();

private:
	int m_nBuckets;
	HASH_NODE** m_pBuckets;
};

inline CHashLnk::CHashLnk(int n)
{
	assert(n>0);
	m_pBuckets = new HASH_NODE*[n];
	for (int i = 0; i < n; i++)
		m_pBuckets[i] = NULL;
	m_nBuckets = n;
}

inline CHashLnk::~CHashLnk()
{
	for (int i = 0; i < m_nBuckets; i++)
	{
		if (m_pBuckets[i] != NULL)
		{
			HASH_NODE* pIter = m_pBuckets[i];
			while (pIter != NULL)
			{
				HASH_NODE* pDel = pIter;
				pIter = pIter->pNodeNxt;
				delete pDel;
			}
		}
	}

	delete []m_pBuckets;
}

inline void CHashLnk::AddNumberInB(int n)
{
	int nIndex = n % m_nBuckets;
	if (NULL == m_pBuckets[nIndex])
		m_pBuckets[nIndex] = new HASH_NODE(n);
	else
	{
		HASH_NODE* pIter = m_pBuckets[nIndex];
		while (true)
		{
			if (pIter->nVal == n)
			{
				pIter->nFreqB++;
				break;
			}

			if (pIter->pNodeNxt == NULL)
			{
				pIter->pNodeNxt = new HASH_NODE(n);
				break;
			}

			pIter = pIter->pNodeNxt;
		}
	}
}

inline void CHashLnk::AddNumberInA(int n)
{
	int nIndex = n % m_nBuckets;
	if (NULL == m_pBuckets[nIndex])
		return;
	
	HASH_NODE* pIter = m_pBuckets[nIndex];
	while (pIter != NULL)
	{
		if (pIter->nVal == n)
		{
			pIter->nFreqA++;
			break;
		}

		pIter = pIter->pNodeNxt;
	}
}

inline bool CHashLnk::RemoveNumberInA(int n)
{
	int nIndex = n % m_nBuckets;
	if (NULL == m_pBuckets[nIndex])
		return true;

	HASH_NODE* pIter = m_pBuckets[nIndex];
	while (pIter != NULL)
	{
		if (pIter->nVal == n)
		{
			if (pIter->nFreqA <= pIter->nFreqB)
				return false;
			
			pIter->nFreqA--;
			return true;
		}

		pIter = pIter->pNodeNxt;
	}

	return true;
}

inline bool CHashLnk::JudgeAcontainB()
{
	for (int i = 0; i < m_nBuckets; i++)
	{
		if (m_pBuckets[i] != NULL)
		{
			HASH_NODE* pIter = m_pBuckets[i];
			while (pIter != NULL)
			{
				if (pIter->nFreqA < pIter->nFreqB)
					return false;

				pIter = pIter->pNodeNxt;
			}
		}
	}

	return true;
}

bool GetSmallestWindow(int A[], int nA, int B[], int nB, int& nLft, int& nRgt)
{
	assert(A);
	assert(B);
	assert(nB>0);
	assert(nA>0);

	CHashLnk hshLnk(nB);
	for (int i = 0; i < nB; i++)
		hshLnk.AddNumberInB(B[i]);
	for (int i = 0; i < nA; i++)
		hshLnk.AddNumberInA(A[i]);

	if(!hshLnk.JudgeAcontainB()) return false;

	nLft = 0;
	while (nLft < nA && hshLnk.RemoveNumberInA(A[nLft]))
		nLft++;

	nRgt = nA-1;
	while (nRgt >= nLft && hshLnk.RemoveNumberInA(A[nRgt]))
		nRgt--;

	return true;
}

void test()
{
	int a[] = {1,1,2,3,5,4,2,7,8,0};
	int b[] = {2};

	int nLft, nRgt;
	if (GetSmallestWindow(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int), nLft, nRgt))
	{
		cout<<nLft<<" "<<nRgt<<endl;
	}
	else
	{
		cout<<"error"<<endl;
	}
}

