//
//Add an Interview Question
//
//
//Microsoft Interview Question for Software Engineer / Developers about Algorithm Trees and Graphs
//Manox on May 25, 2010
//
//Given a binary tree print the nodes in this order:
//all the left most nodes from top to bottom, then all the leaves, then all the right most nodes from bottom to top, then the root. like
//
//			10
//	5            15
//3       2   12        17
//
//
//you would print 5 3 2 12 17 15 10

struct TREE_NODE
{
	int nVal;
	TREE_NODE* pRgt;
	TREE_NODE* pLft;

	TREE_NODE(int n) : nVal(n), pLft(NULL), pRgt(NULL)
	{}
};

void PrintLeftMost(TREE_NODE* pNode);
void PrintLeaf(TREE_NODE* pNode);
void PrintRgtMost(TREE_NODE* pNode, bool bPrint = true);

void PrintTriangle(TREE_NODE* pRoot)
{
	if (NULL == pRoot) return;

	PrintLeftMost(pRoot);
	PrintLeaf(pRoot);
	PrintRgtMost(pRoot);
}

void PrintLeftMost(TREE_NODE* pNode)
{
	if (NULL == pNode) return;

	if (pNode->pLft != NULL)
	{
		if (pNode->pLft->pLft != NULL || pNode->pLft->pRgt != NULL)
			cout<<pNode->pLft->nVal<<endl;
		PrintLeftMost(pNode->pLft);
	}
	else
		if (pNode->pRgt != NULL)
			PrintLeftMost(pNode->pRgt);
}

void PrintLeaf(TREE_NODE* pNode)
{
	if (NULL == pNode) return;

	if (NULL == pNode->pLft && NULL == pNode->pRgt)
		cout<<pNode->nVal<<endl;

	if (pNode->pLft != NULL)
		PrintLeaf(pNode->pLft);
	
	if (pNode->pRgt != NULL)
		PrintLeaf(pNode->pRgt);
}

void PrintRgtMost(TREE_NODE* pNode, bool bPrint)
{
	if (NULL == pNode) return;

	if (pNode->pRgt != NULL)
	{
		PrintRgtMost(pNode->pRgt, true);
		if (bPrint) cout<<pNode->nVal<<endl;
	}
	else
		if (pNode->pLft != NULL)
		{
			PrintRgtMost(pNode->pLft, false);
			if (bPrint) cout<<pNode->nVal<<endl;
		}
}

void test()
{
	TREE_NODE* p0 = new TREE_NODE(0);
	TREE_NODE* p1 = new TREE_NODE(1);
	TREE_NODE* p2 = new TREE_NODE(2);
	TREE_NODE* p3 = new TREE_NODE(3);
	TREE_NODE* p4 = new TREE_NODE(4);
	TREE_NODE* p5 = new TREE_NODE(5);
	TREE_NODE* p6 = new TREE_NODE(6);
	TREE_NODE* p7 = new TREE_NODE(7);

	p0->pLft = p1;
	p0->pRgt = p2;
	p1->pLft = p3;
	p1->pRgt = p4;
	p2->pLft = p5;
	p5->pRgt = p6;

	PrintTriangle(p0);
}