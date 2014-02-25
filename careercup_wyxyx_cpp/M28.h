//binary tree: each node has an additional field node which is initialized to be NULL at first. Asked to, for each node, 
//point its next pointer to the next node in level-by-level traversal order. NO QUEUE should be used HERE!

//Solution:
//Notice although the order of depth first search is not exactly same to breath first search, the order of the nodes in each
//level are the same. So, the key here is to record the link of each level and joint them together, log(n) space should be used here.
//At the beginning, we allocate a array with the elements same to the hight of the tree. Then, we perform depth first travel of this
//tree. When we encounter a node with the link of the same level null, we assign the address of this node to the elements corresponding
//to its level, otherwise, we connect the tail to this node. A depth first search will finish all the link of the same level, and go through
//the level link record array to connect each link representing certain level of the tree together.

struct TREE_NODE 
{
	int nValue;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;
	TREE_NODE* pNext;

	TREE_NODE(int n) : nValue(n), pLft(NULL), pRgt(NULL), pNext(NULL)
	{}
};

int GetHeight(TREE_NODE* pRoot)
{
	if (NULL == pRoot) return 0;

	int nHLft = GetHeight(pRoot->pLft);
	int nHRgt = GetHeight(pRoot->pRgt);

	return (nHLft>nHRgt) ? nHLft+1 : nHRgt+1;
}

struct RECORD
{
	TREE_NODE* pHead;
	TREE_NODE* pTail;

	RECORD() : pHead(NULL), pTail(NULL) {}
};

void DFSTree(TREE_NODE* pRoot, int nLevel, RECORD* pLNK)
{
	assert(pRoot);

	if (pRoot->pLft != NULL) DFSTree(pRoot->pLft, nLevel+1, pLNK);

	if (pLNK[nLevel].pHead == NULL)
	{
		pLNK[nLevel].pHead = pRoot;
		pLNK[nLevel].pTail = pRoot;
	}
	else
	{
		pLNK[nLevel].pTail->pNext = pRoot;
		pLNK[nLevel].pTail = pRoot;
	}

	if (pRoot->pRgt != NULL) DFSTree(pRoot->pRgt, nLevel+1, pLNK);
}

void SetNext(TREE_NODE* pRoot)
{
	int nHeight = GetHeight(pRoot);
	if (nHeight == 0 || nHeight == 1)
		return;

	RECORD* pLinks = new RECORD[nHeight];

	DFSTree(pRoot, 0, pLinks);
	for (int i = 0; i < nHeight-1; i++)
		pLinks[i].pTail->pNext = pLinks[i+1].pHead;

	delete []pLinks;
}

void test()
{
	TREE_NODE n0(0);
	TREE_NODE n1(1);
	TREE_NODE n2(2);
	TREE_NODE n3(3);
	TREE_NODE n4(4);
	TREE_NODE n5(5);
	TREE_NODE n6(6);
	TREE_NODE n7(7);

	n0.pLft = &n1;
	n0.pRgt = &n2;
	n1.pLft = &n3;
	n1.pRgt = &n4;
	n2.pLft = &n5;
	n2.pRgt = &n6;
	n5.pRgt = &n7;

	SetNext(&n0);
	TREE_NODE* pIter = &n0;
	while (pIter != NULL)
	{
		cout<<pIter->nValue<<" ";
		pIter = pIter->pNext;
	}
	cout<<endl;
}