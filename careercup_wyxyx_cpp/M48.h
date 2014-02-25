//Perform Sorted Insert on a link list and write test cases

struct LNK_NODE 
{
	int nValue;
	LNK_NODE* pNext;

	LNK_NODE(int n) : nValue(n), pNext(NULL) {}
};

class CLink
{
public:
	CLink() { m_pHead = NULL; }
	~CLink();
	void InsertSort(LNK_NODE* pNode);
	void PrintLink();

private:
	LNK_NODE* m_pHead;
};

inline CLink::~CLink()
{
	while (NULL != m_pHead)
	{
		LNK_NODE* pDel = m_pHead;
		m_pHead = m_pHead->pNext;
		delete pDel;
	}
}

inline void CLink::PrintLink()
{
	if (NULL == m_pHead)
		cout<<"Empty link"<<endl;
	else
	{
		LNK_NODE* pIter = m_pHead;
		while (NULL != pIter)
		{
			cout<<pIter->nValue<<" ";
			pIter = pIter->pNext;
		}
		cout<<endl;
	}
}

inline void CLink::InsertSort(LNK_NODE* pNode)
{
	assert(pNode != NULL);

	if (NULL == m_pHead)
	{
		m_pHead = pNode;
		return;
	}

	if (pNode->nValue < m_pHead->nValue)
	{
		pNode->pNext = m_pHead;
		m_pHead = pNode;
		return;
	}

	LNK_NODE* pIter = m_pHead;
	while (pIter->pNext != NULL && pNode->nValue >= pIter->pNext->nValue)
		pIter = pIter->pNext;

	pNode->pNext = pIter->pNext;
	pIter->pNext = pNode;
}

void test()
{
	CLink link;
	link.InsertSort(new LNK_NODE(3));
	link.InsertSort(new LNK_NODE(1));
	link.InsertSort(new LNK_NODE(3));
	link.InsertSort(new LNK_NODE(4));
	link.InsertSort(new LNK_NODE(-2));

	link.PrintLink();
}