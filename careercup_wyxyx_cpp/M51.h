//This Question is asked in a written test of microsoft in Bangalore today.
//given two sorted linked list.
//Write a recursive code to find the intersection of two list.
//the resulted list must be in sorted order.
//all unused node should be deleted using "free()".
//method Signature was given..
//Node *SortedIntersection(Node *l1, Node *l2)

struct LNK_NODE
{
	int nVal;
	LNK_NODE* pNext;

	LNK_NODE(int n) : nVal(n), pNext(NULL)
	{}

	~LNK_NODE() { cout<<"Destruction : "<<nVal<<endl; }
};

LNK_NODE* MoveDel(LNK_NODE*& pIter)
{
	if (pIter == NULL) return NULL;

	LNK_NODE* pDel = pIter;
	pIter = pIter->pNext;
	delete pDel;

	return pIter;
}

LNK_NODE *SortedIntersection(LNK_NODE *pHead1, LNK_NODE *pHead2)
{
	assert(pHead2 && pHead1);

	LNK_NODE* pNewHead = NULL;
	LNK_NODE* pPrev = NULL;
	LNK_NODE* pIter1 = pHead1;
	LNK_NODE* pIter2 = pHead2;

	while (pIter1 != NULL && pIter2 != NULL)
	{
		if (pIter1->nVal == pIter2->nVal)
		{
			if (NULL == pNewHead) pNewHead = pIter1;

			pPrev = pIter1;
			pIter1 = pIter1->pNext;

			MoveDel(pIter2);
		}
		else if (pIter1->nVal < pIter2->nVal)
			pPrev == NULL ? MoveDel(pIter1) : pPrev->pNext = MoveDel(pIter1);
		else
			MoveDel(pIter2);
	}

	LNK_NODE* pDel = pIter1 != NULL ? pIter1 : pIter2;
	while (MoveDel(pDel) != NULL); 

	if (pPrev != NULL) pPrev->pNext = NULL;

	return pNewHead;
}

void test()
{
	LNK_NODE* p0 = new LNK_NODE(1);
	/*LNK_NODE* p1 = new LNK_NODE(2);
	LNK_NODE* p2 = new LNK_NODE(3);
	LNK_NODE* p3 = new LNK_NODE(4);*/
	/*p0->pNext = p1;
	p1->pNext = p2;
	p2->pNext = p3;*/

	LNK_NODE* p4 = new LNK_NODE(1);
	/*LNK_NODE* p5 = new LNK_NODE(5);
	LNK_NODE* p6 = new LNK_NODE(6);
	LNK_NODE* p7 = new LNK_NODE(7);*/
	/*p4->pNext = p5;
	p5->pNext = p6;
	p6->pNext = p7;*/

	LNK_NODE* pNewHead = SortedIntersection(p0, p4);

	cout<<"Common nodes are : "<<endl;
	while(pNewHead != NULL)
	{
		cout<<pNewHead->nVal<<" ";
		pNewHead = pNewHead->pNext;
	}
	cout<<endl;
}