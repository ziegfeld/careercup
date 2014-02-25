//You have been given a linked list of numbers. The size is not know. You need to find 
//out if the number stored in the list is a palindrome in the best possible optimized manner.

//Solution:
//There is a way to finish it in two passes, no extra memory is needed.
//Keep a fast pointer and a slow pointer, fast pointer moves two nodes
//each time and slow pointer one node. During the moving, slow pointer
//reverse the nodes it passed. When fast pointer reaches the end, slow pointer
//reaches the middle of the link. So, the link is divided into to links, judge
//whether the link is palindrome by passing the two links at the same time. During
//moving back of the first half of the original link, reverse it back.

struct LNK_NODE
{
	char cVal;
	LNK_NODE* pNext;
	
	LNK_NODE(char c) : cVal(c), pNext(NULL)
	{}
};

bool IsLinkPalindrome(LNK_NODE* pHead)
{
	assert(pHead);
	if (pHead->pNext == NULL) return true;

	LNK_NODE* pSlow = pHead;
	LNK_NODE* pTmp = pSlow->pNext;
	LNK_NODE* pFast = pHead;

	LNK_NODE* pLnk1 = NULL;
	LNK_NODE* pLnk2 = NULL;

	while (true)
	{
		if (pFast->pNext == NULL)
		{
			pLnk1 = pSlow->pNext;
			pLnk2 = pTmp;
			break;
		}

		if (pFast->pNext->pNext == NULL)
		{
			pLnk1 = pSlow;
			pLnk2 = pTmp;
			break;
		}

		pFast = pFast->pNext->pNext;
		
		LNK_NODE* pOrg = pSlow;
		pSlow = pTmp;
		pTmp = pSlow->pNext;
		pSlow->pNext = pOrg;
	}

	LNK_NODE* pIter1 = pLnk1;
	LNK_NODE* pIter2 = pLnk2;

	bool bRet = true;
	while (pIter2 != NULL && pIter2->pNext != NULL)
	{
		if (!bRet || pIter1->cVal != pIter2->cVal)
			bRet = false;

		pIter2 = pIter2->pNext;
		
		LNK_NODE* pNew = pIter1->pNext;
		pIter1->pNext->pNext = pIter1;
		pIter1 = pNew;
	}

	//joint two broken link
	if (pSlow != pLnk1)
		pLnk1->pNext = pSlow;
	pSlow->pNext = pLnk2;

	return bRet;
}

void test()
{
	LNK_NODE* p0 = new LNK_NODE('a');
	//LNK_NODE* p1 = new LNK_NODE('a');
	//LNK_NODE* p2 = new LNK_NODE('c');

	//p0->pNext = p1;
//	p1->pNext = p2;
	//p2->pNext = px;
	/*px->pNext = p3;
	p3->pNext = p4;*/

	cout<<IsLinkPalindrome(p0)<<endl;
	LNK_NODE* pIter = p0;
	while (NULL != pIter)
	{
		cout<<pIter->cVal<<endl;
		pIter = pIter->pNext;
	}
}