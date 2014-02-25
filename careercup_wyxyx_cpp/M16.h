//Write a function that, given a binary search tree and a value, 
//will find the next biggest node value in the tree

//Solution:
//Find this node and record its parent nodes in the path, stores them in a stack says S.
//If this node got a right child, the left most node of the left tree of this node
//is the next biggest one.
//If no right child existed, pop the parent node within stack S one by one until you see 
//the first node with its value bigger than the given node. This node is the one you want to find.

class CBST
{
public:
	CBST() : m_pRoot(NULL) {}
	~CBST();

	void InputValue(int n);
	bool FindNext(int n, int& nRes);

private:
	struct NODE 
	{
		int nValue;
		NODE* pLft;
		NODE* pRgt;

		NODE(int n) : nValue(n), pLft(NULL), pRgt(NULL) {}
	};
	
	NODE* m_pRoot;
	void InnerDestroy(NODE* p);
};

inline void CBST::InputValue(int n)
{
	if (NULL == m_pRoot)
	{
		m_pRoot = new NODE(n);
		return;
	}

	NODE* pIter = m_pRoot;
	
	while (1)
	{
		if (n >= pIter->nValue)
		{
			if (pIter->pRgt == NULL)
			{
				pIter->pRgt = new NODE(n);
				break;
			}
			else
				pIter = pIter->pRgt;
		}
		else
		{
			if (pIter->pLft == NULL)
			{
				pIter->pLft = new NODE(n);
				break;
			}
			else
				pIter = pIter->pLft;
		}
	}
}

inline bool CBST::FindNext(int n, int& nRes)
{
	stack<NODE*> stk;

	NODE* pIter = m_pRoot;
	while (NULL != pIter)
	{
		if (pIter->nValue == n)
			break;

		if (pIter->nValue < n)
		{
			stk.push(pIter);
			pIter = pIter->pRgt;
			continue;
		}

		if (pIter->nValue > n)
		{
			stk.push(pIter);
			pIter = pIter->pLft;
			continue;
		}
	}

	if (NULL == pIter)
		return false;

	pIter = pIter->pRgt;
	if (pIter != NULL)
	{
		while (pIter->pLft != NULL)
			pIter = pIter->pLft;
		nRes = pIter->nValue;
		return true;
	}

	while (!stk.empty())
	{
		pIter = stk.top();
		if (pIter->nValue > n)
		{
			nRes = pIter->nValue;
			return true;
		}

		stk.pop();
	}

	return false;
}

void CBST::InnerDestroy(NODE* p)
{
	if (NULL == p) return;

	InnerDestroy(p->pLft);
	InnerDestroy(p->pRgt);
	delete p;
}

CBST::~CBST()
{
	InnerDestroy(m_pRoot);
	m_pRoot = NULL;
}

void test()
{
	CBST bst;
	bst.InputValue(5);
	bst.InputValue(3);
	bst.InputValue(4);
	bst.InputValue(2);
	bst.InputValue(7);
	bst.InputValue(6);
	bst.InputValue(8);

	int n = 0;
	int x = 4;
	if (bst.FindNext(x, n))
		cout<<"The next biggest number of "<<x<<"is "<<n<<endl;
	else
		cout<<"Next biggest number not found"<<endl;
}