//You have a sorted circular linked list but you don't know the sorting order(increasing or decreasing).
//Write code to insert a node into this list.Take care of all the possible cases.

//Solution:
//1: Find one node in the circule.
//2: Break the link into two joint links
//3: Find the first common node which is the joint, say node A
//4: Connect the broken link
//5: Treat the circular link as a single direct link for we already know the joint point.

struct LNK_NODE 
{
	int nValue;
	LNK_NODE* pNext;

	LNK_NODE(int n) : nValue(n), pNext(NULL)
	{}
};

int GetLenSLL(LNK_NODE* pHead)
{
	assert(pHead);

	int nLen = 0;
	while(NULL != pHead)
	{
		pHead = pHead->pNext;
		nLen++;
	}

	return nLen;
}

LNK_NODE* GetOneInCircular(LNK_NODE* pHead)
{
	assert(pHead);

	LNK_NODE* pSlow = pHead;
	LNK_NODE* pFast = pHead->pNext;

	while (pSlow != NULL && pFast != NULL && pFast->pNext != NULL && pSlow != pFast)
	{
		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}

	if (pSlow == pFast)
		return pFast;
	return NULL;
}

LNK_NODE* GetTheJoint(LNK_NODE* pHead)
{
	assert(pHead);

	LNK_NODE* pNode = GetOneInCircular(pHead);
	if (NULL == pNode)
		return NULL;

	LNK_NODE* pNewHead = pNode->pNext;
	pNode->pNext = NULL;

	int nLen1 = GetLenSLL(pHead);
	int nLen2 = GetLenSLL(pNewHead);

	LNK_NODE* pShort = NULL;
	LNK_NODE* pLong = NULL;
	int nDiff = 0;

	if (nLen1 > nLen2)
	{
		pLong = pHead;
		pShort = pNewHead;
		nDiff = nLen1 - nLen2;
	}
	else
	{
		pLong = pNewHead;
		pShort = pHead;
		nDiff = nLen2 - nLen1;
	}

	while (nDiff--)
	{
		pLong = pLong->pNext;
	}

	while (pLong != pShort && pLong != NULL && pShort != NULL)
	{
		pLong = pLong->pNext;
		pShort = pShort->pNext;
	}

	pNode->pNext = pNewHead;
	if (pShort != pLong)
		throw "What the FUCK???? \n";

	return pShort;
}

void InsertToSorted(LNK_NODE* pHead, LNK_NODE* pToInsert)
{
	assert(pHead);
	assert(pToInsert);

	bool bGotOrder = false;
	bool bIncrease = false;

	LNK_NODE* pIter = pHead;
	LNK_NODE* pJoint = GetTheJoint(pHead);

	//Figure out the order
	int nTimes = 0;
	if (NULL == pJoint) 
		nTimes = 1;
	else
		nTimes = 2;

	int nCurEndTime = 1;
	while (!bGotOrder)
	{
		if (pIter->pNext == pJoint && nCurEndTime++ == nTimes)
			break;

		if (pIter->nValue > pIter->pNext->nValue)
		{
			bGotOrder = true;
			bIncrease = false;
		}

		if (pIter->nValue < pIter->pNext->nValue)
		{
			bGotOrder = true;
			bIncrease = true;
		}

		pIter = pIter->pNext;
	}

	//Insert into the link
	nCurEndTime = 1;
	pIter = pHead;
	while (true)
	{
		if (pIter->pNext == pJoint && nCurEndTime++ == nTimes)
			break;

		if ( (bIncrease && pIter->nValue <= pToInsert->nValue) || 
			 (!bIncrease && pIter->nValue >= pToInsert->nValue) )
		{
			break; 
		}
	}

	pToInsert->pNext = pIter->pNext;
	pIter->pNext = pToInsert;

	return; 
}