//Given a binary search tree, the max number is a and the minimu number is b
//find the node with whose value just bigger than (a+b)/2

//Solution:
//Find a and b (log(n))
//perform binary search(log(n))

struct TREE_NODE
{
	int nVal;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;

	TREE_NODE(int n) : nVal(n), pLft(NULL), pRgt(NULL) 
	{}
};

TREE_NODE* _inner_find_bigger(TREE_NODE* pCur, int n)
{
	if (pCur == NULL) return NULL;

	TREE_NODE* pRet = NULL;
	if (pCur->nVal > n)
		pRet = _inner_find_bigger(pCur->pLft, n);
	else
		pRet = _inner_find_bigger(pCur->pRgt, n);

	if (pRet != NULL) return pRet;
	if (pCur->nVal > n) return pCur;

	return NULL;
}

TREE_NODE* FindJustBigger(TREE_NODE* pRoot)
{
	assert(pRoot != NULL);

	//Find smallest
	TREE_NODE* pIter = pRoot;
	while (pIter->pLft != NULL)
		pIter = pIter->pLft;
	int nMin = pIter->nVal;

	//Find largest
	pIter = pRoot;
	while (pIter->pRgt != NULL)
		pIter = pIter->pRgt;
	int nLrg = pIter->nVal;

	int n = (nMin+nLrg)/2;
	TREE_NODE* pRes = _inner_find_bigger(pRoot, n);

	return pRes;
}

void test()
{
	TREE_NODE* p0 = new TREE_NODE(6);
	TREE_NODE* p1 = new TREE_NODE(3);
	TREE_NODE* p2 = new TREE_NODE(8);
	TREE_NODE* p3 = new TREE_NODE(2);
	TREE_NODE* p4 = new TREE_NODE(5);
	TREE_NODE* p5 = new TREE_NODE(7);
	TREE_NODE* p6 = new TREE_NODE(9);
	TREE_NODE* p8 = new TREE_NODE(2);
	TREE_NODE* p9 = new TREE_NODE(4);

	p0->pLft = p1;
	p0->pRgt = p2;
	p1->pLft = p3;
	p1->pRgt = p4;
	p2->pLft = p5;
	p2->pRgt = p6;
	p3->pRgt = p8;
	p4->pLft = p9;

	TREE_NODE* pRes = FindJustBigger(p0);
	if (NULL == pRes)
		cout<<"Error, no such a number"<<endl;
	else
		cout<<pRes->nVal<<endl;
}