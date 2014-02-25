//Given an inorder and preorder traversal of a tree construct the tree

//Solution:
//This problem can be resolved by recurse.
//Every element in the preorder traversal array can be deemed as a root of 
//a sub tree, which divided the inorder array into two parts.
//For example, the first element in the preorder array divide the inorder array into
//left part and the right part, the two parts contained the elements of the left sub tree
//and the right sub tree of the root. And for the left part, the second element in the preorder
//traversal array is the root of the sub tree formed by the left part just divided. So, do this in
//a recursive manner to solve the problem.

struct TREE_NODE 
{
	int nValue;
	TREE_NODE* pLfg;
	TREE_NODE* pRgt;

	TREE_NODE(int n) : nValue(n), pLfg(NULL), pRgt(NULL)
	{}
};

TREE_NODE* ConstructTree(int preOrder[], int& nPivot, int inOrder[], int nBeg, int nEnd)
{
	assert(preOrder);
	assert(nPivot>=0);

	if (nBeg > nEnd) return NULL;

	int nP = preOrder[nPivot++];
	int nIter = 0;
	for (nIter = nBeg; nIter <= nEnd; nIter++)
	{
		if (inOrder[nIter] == nP) break;
	}
	
	if (nIter > nEnd)
		throw "Error : pre-Order In-Order not consistent \n";
	
	TREE_NODE* pRet = new TREE_NODE(nP);
	pRet->pLfg = ConstructTree(preOrder, nPivot, inOrder, nBeg, nIter-1);
	pRet->pRgt = ConstructTree(preOrder, nPivot, inOrder, nIter+1, nEnd);

	return pRet;
}

void BreathFirstPrint(TREE_NODE* pRoot)
{
	deque<TREE_NODE*> que;
	que.push_back(pRoot);

	while (!que.empty())
	{
		TREE_NODE* pNode = que.front();
		que.pop_front();

		if (NULL != pNode)
		{
			cout<<pNode->nValue<<" ";
			que.push_back(pNode->pLfg);
			que.push_back(pNode->pRgt);
		}
	}
}

/*
                 1
			   2   3
			  4 5 6 7
*/

void test()
{
	int preorder[] = {1,2,4,5,3,6,7};
	int inorder[] = {4,2,5,1,6,3,7};

	int nPivot = 0;
	TREE_NODE* pRoot = ConstructTree(preorder, nPivot, inorder, 0, sizeof(inorder)/sizeof(int)-1);
	BreathFirstPrint(pRoot);
}