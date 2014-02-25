//Connect the leafs in a binary tree and return a reference to the first of the linked leafs. 
//This would allow clients of this API to subsequently traverse the leafs. The API has a fLR 
//flag indicating if the leafs should be connected from left-right (fLR = true) or from right-left (fLR = false).
//Please implement the following API:
//public Node ConnectLeafs(Node root, bool fLR)
//
//Parameters:
//Node root – a reference to the root of the tree
//bool fLR – direction of leaf liking.

//Solution:
//So easy, even don't want to write the solution down here ...

struct TREE_NODE 
{
	int nValue;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;
	TREE_NODE* pLeafNxt;

	TREE_NODE(int n) : nValue(n), pLft(NULL), pRgt(NULL), pLeafNxt(NULL) {}
};

void _inner_conn(TREE_NODE* pRoot, bool fLR, TREE_NODE*& pIter, TREE_NODE*& pFirst)
{
	if (pRoot == NULL)
		return;

	if (fLR)
		_inner_conn(pRoot->pLft, fLR, pIter, pFirst);
	else
		_inner_conn(pRoot->pRgt, fLR, pIter, pFirst);

	if (pRoot->pLft == NULL && pRoot->pRgt == NULL)
	{
		if (NULL == pIter)
		{
			pIter = pRoot;
			pFirst = pRoot;
		}
		else
		{
			pIter->pLeafNxt = pRoot;
			pIter = pIter->pLeafNxt;
		}
	}

	if (fLR)
		_inner_conn(pRoot->pRgt, fLR, pIter, pFirst);
	else
		_inner_conn(pRoot->pLft, fLR, pIter, pFirst);

}

TREE_NODE* ConnectLeafs(TREE_NODE* pRoot, bool fLR)
{
	assert(pRoot);
	TREE_NODE* pIter = NULL;
	TREE_NODE* pFirst = NULL;
	_inner_conn(pRoot, fLR, pIter, pFirst);

	return pFirst;
}

void test()
{
	vector<TREE_NODE*> vec;
	TREE_NODE node0(0);
	vec.push_back(&node0);
	TREE_NODE node1(1);
	vec.push_back(&node1);
	TREE_NODE node2(2);
	vec.push_back(&node2);
	TREE_NODE node3(3);
	vec.push_back(&node3);
	TREE_NODE node4(4);
	vec.push_back(&node4);
	TREE_NODE node5(5);
	vec.push_back(&node5);
	TREE_NODE node6(6);
	vec.push_back(&node6);
	TREE_NODE node7(7);
	vec.push_back(&node7);

	node0.pLft = &node1;
	node0.pRgt = &node2;
	node1.pLft = &node3;
	node1.pRgt = &node4;
	node2.pLft = &node5;
	node2.pRgt = &node6;
	node6.pRgt = &node7;

	TREE_NODE* pFirst = ConnectLeafs(&node0, false);
	while (pFirst != NULL)
	{
		cout<<pFirst->nValue<<" ";
		pFirst = pFirst->pLeafNxt;
	}
	cout<<endl;
}