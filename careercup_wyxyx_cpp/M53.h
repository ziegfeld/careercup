//Merge two sorted singly linked lists into one without using extra space and the duplicates should remian in the final list.

struct LNK_NODE
{
	int nVal;
	LNK_NODE* pNext;

	LNK_NODE(int n) : nVal(n), pNext(NULL)
	{}
};

void AddTail(LNK_NODE*& pTail, LNK_NODE* pNode)
{
	if (NULL == pTail) 
		pTail = pNode;
	else
	{
		pTail->pNext = pNode;
		pTail = pTail->pNext;
	}

	pTail->pNext = NULL;
}

LNK_NODE* MergSorted(LNK_NODE* pHead1, LNK_NODE* pHead2)
{
	if (pHead1 == NULL) return pHead2;
	if (pHead2 == NULL) return pHead1;

	LNK_NODE* pIter1 = pHead1;
	LNK_NODE* pIter2 = pHead2;

	LNK_NODE* pDupHead = NULL;
	LNK_NODE* pDupTail = NULL;

	LNK_NODE* pNewHead = NULL;
	LNK_NODE* pNewTail = NULL;

	while (pIter1 != NULL && pIter2 != NULL)
	{
		//Init
		if (NULL == pNewHead)
			pIter1->nVal <= pIter2->nVal ? pNewHead = pIter1 : pNewHead = pIter2;

		if (pIter1->nVal == pIter2->nVal)
		{
			if (NULL == pDupHead) pDupHead = pIter2;

			LNK_NODE* pOrg = pIter1;
			pIter1 = pIter1->pNext;
			AddTail(pNewTail, pOrg);

			pOrg = pIter2;
			pIter2 = pIter2->pNext;
			AddTail(pDupTail, pOrg);
		}
		else
			if (pIter1->nVal < pIter2->nVal)
			{
				LNK_NODE* pOrg = pIter1;
				pIter1 = pIter1->pNext;
				AddTail(pNewTail, pOrg);
			}
			else
			{
				LNK_NODE* pOrg = pIter2;
				pIter2 = pIter2->pNext;
				AddTail(pNewTail, pOrg);
			}
	}

	if (pIter1 != NULL) 
		pNewTail->pNext = pIter1;
	else
		pNewTail->pNext = pIter2;

	while (pNewTail->pNext != NULL)
		pNewTail = pNewTail->pNext;

	pNewTail->pNext = pDupHead;

	return pNewHead;
}

void test()
{
	LNK_NODE* p0 = new LNK_NODE(1);
	LNK_NODE* p1 = new LNK_NODE(3);
	LNK_NODE* p2 = new LNK_NODE(5);

	p0->pNext = p1; p1->pNext = p2;

	LNK_NODE* q0 = new LNK_NODE(2);
	LNK_NODE* q1 = new LNK_NODE(3);
	LNK_NODE* q2 = new LNK_NODE(4);
	LNK_NODE* q3 = new LNK_NODE(5);
	LNK_NODE* q4 = new LNK_NODE(6);

	q0->pNext = q1; q1->pNext = q2; q2->pNext = q3; q3->pNext = q4;
	
	LNK_NODE* pLnk = MergSorted(p0, q0);
	while (pLnk != NULL)
	{
		cout<<pLnk->nVal<<endl;
		pLnk = pLnk->pNext;
	}
}