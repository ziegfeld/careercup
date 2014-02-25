//How to completely delete a linked list with circle?

//Solution:
//Break the loop!! Find a node which is within the loop and break it to form
//two joint single link(If you do not know how to find this node, refer to my code
//or just search on google or baidu). Then, calculate the length of the two links says
//len1 and len2. The head of the two links says h1 and h2.Find the longer link and delete the first
//fabs(len1-len2) nodes. Then, the two links are of same length.
//Then delete forward together with the header node of another link
//one by one untill the first joint node is found. Delete the joint part of the two links.

struct LNK_NODE
{
	int nValue;
	LNK_NODE* pNext;

	LNK_NODE(int n) : nValue(n), pNext(NULL){}
	~LNK_NODE() { cout<<"Kill node :"<<nValue<<endl; }
};

void DeleteLink(LNK_NODE* pHead)
{
	assert(pHead != NULL);

	//Find the loop if existed
	LNK_NODE* pIter1 = pHead;
	LNK_NODE* pIter2 = pHead->pNext;

	while (pIter1 != NULL && pIter2 != NULL && pIter2->pNext != NULL && pIter1 != pIter2)
	{
		pIter1 = pIter1->pNext;
		pIter2 = pIter2->pNext->pNext;
	}

	// Do not have a loop
	if (pIter1 != pIter2)
	{
		while (pHead != NULL)
		{
			LNK_NODE* pDel = pHead;
			pHead = pHead->pNext;
			delete pDel;
		}

		return;
	}

	//Find a node in the loop
	LNK_NODE* pHead2 = pIter1->pNext;
	pIter1->pNext = NULL;

	//Calculate length
	int nLen1 = 0;
	int nLen2 = 0;
	pIter1 = pHead;
	pIter2 = pHead2;

	while (pIter1 != NULL)
	{
		nLen1++;
		pIter1 = pIter1->pNext;
	}

	while (pIter2 != NULL)
	{
		nLen2++;
		pIter2 = pIter2->pNext;
	}

	LNK_NODE* pShorter = NULL;
	LNK_NODE* pLonger = NULL;
	int nDiff = 0;

	if (nLen1 > nLen2)
	{
		pLonger = pHead;
		pShorter = pHead2;
		nDiff = nLen1-nLen2;
	}
	else
	{
		pLonger = pHead2;
		pShorter = pHead;
		nDiff = nLen2-nLen1;
	}

	while (nDiff--)
	{
		LNK_NODE* pDel = pLonger;
		pLonger = pLonger->pNext;
		delete pDel;
	}

	while (pLonger != pShorter)
	{
		LNK_NODE* pDel = pLonger;
		pLonger = pLonger->pNext;
		delete pDel;

		pDel = pShorter;
		pShorter = pShorter->pNext;
		delete pDel;
	}

	while (pLonger != NULL)
	{
		LNK_NODE* pDel = pLonger;
		pLonger = pLonger->pNext;
		delete pDel;
	}
}

void test()
{//0--1--2--3--4--5--6--7--3
	LNK_NODE* p0 = new LNK_NODE(0);
	LNK_NODE* p1 = new LNK_NODE(1);
	LNK_NODE* p2 = new LNK_NODE(2);
	LNK_NODE* p3 = new LNK_NODE(3);
	LNK_NODE* p4 = new LNK_NODE(4);
	LNK_NODE* p5 = new LNK_NODE(5);
	LNK_NODE* p6 = new LNK_NODE(6);
	LNK_NODE* p7 = new LNK_NODE(7);

	p0->pNext = p1;
	p1->pNext = p2;
	p2->pNext = p3;
	p3->pNext = p4;
	p4->pNext = p5;
	p5->pNext = p6;
	p6->pNext = p7;
	p7->pNext = p3;

	DeleteLink(p0);
}