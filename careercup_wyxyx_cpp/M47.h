//Reverse linklist in block
//eg. block size is 3 and list is
//1 2 3 4 5 6 7 8
//Output: 3 2 1 6 5 4 8 7

struct LNK_NODE 
{
	int nValue;
	LNK_NODE* pNext;
	
	LNK_NODE(int n) : nValue(n), pNext(NULL) {}
};

LNK_NODE* reverse_n_nodes(LNK_NODE* pHead, LNK_NODE*& pNewHead ,int n)
{
	if (NULL == pHead) return NULL;
	
	LNK_NODE* pCur = pHead;
	LNK_NODE* pNxt = pCur->pNext;
	while (NULL != pNxt && --n)
	{
		LNK_NODE* pTmp = pNxt->pNext;
		pNxt->pNext = pCur;
		pCur = pNxt;
		pNxt = pTmp;
	}

	pNewHead = pCur;
	return pNxt;
}

LNK_NODE* ReveseBySeg(LNK_NODE* pHead ,int nSeg)
{
	assert(pHead != NULL);
	assert(nSeg > 0);
	if (1 == nSeg) return pHead;

	LNK_NODE* pRet = NULL;
	LNK_NODE* pNewHead = NULL;
	LNK_NODE* pNxtSeg = reverse_n_nodes(pHead, pNewHead, nSeg);
	pRet = pNewHead;

	//old head -> new head
	while (NULL != pNxtSeg)
	{
		LNK_NODE* pNewTail = pNxtSeg;
		pNxtSeg = reverse_n_nodes(pNxtSeg, pNewHead, nSeg);
		pHead->pNext = pNewHead;
		pHead = pNewTail;
	}
	pHead->pNext = NULL;
	
	return pRet;
}

void test()
{
	LNK_NODE* p1 = new LNK_NODE(1);
	LNK_NODE* p2 = new LNK_NODE(2);
	LNK_NODE* p3 = new LNK_NODE(3);
	LNK_NODE* p4 = new LNK_NODE(4);
	LNK_NODE* p5 = new LNK_NODE(5);
	LNK_NODE* p6 = new LNK_NODE(6);
	LNK_NODE* p7 = new LNK_NODE(7);
	LNK_NODE* p8 = new LNK_NODE(8);

	p1->pNext = p2;
	p2->pNext = p3;
	p3->pNext = p4;
	p4->pNext = p5;
	p5->pNext = p6;
	p6->pNext = p7;
	p7->pNext = p8;

	LNK_NODE* p = ReveseBySeg(p1, 3);
	for (; p != NULL; p = p->pNext) 
		cout<<p->nValue<<endl;
}