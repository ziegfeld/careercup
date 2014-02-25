//Written-Qn-2) Write complete working code (only the function) to traverse a binary tree in ZigZag order
//void printTree(Node *root)
//
//Example:
//	 1
//	/ \
//   2     3
//  / \   / \
// 4   5 6   7
//
//1 3 2 4 5 6 7

//Solution:
//Use two queues to record levels

struct TREE_NODE
{
	int nVal;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;

	TREE_NODE(int n) : nVal(n), pLft(NULL), pRgt(NULL)
	{}
};

void PrintZigZag(TREE_NODE* pRoot)
{
	if (NULL == pRoot) return;

	stack<TREE_NODE*> stL2R;
	stack<TREE_NODE*> stR2L;

	bool bL2R = true;
	stack<TREE_NODE*>* pCurstk = &stL2R;
	stack<TREE_NODE*>* pAnotherstk = &stR2L;
	pCurstk->push(pRoot);

	while (!pCurstk->empty())
	{
		while (!pCurstk->empty())
		{
			TREE_NODE* p = pCurstk->top();
			pCurstk->pop();
			if (NULL == p) continue;

			cout<<p->nVal<<endl;

			if (bL2R)
			{
				pAnotherstk->push(p->pLft);
				pAnotherstk->push(p->pRgt);
			}
			else
			{
				pAnotherstk->push(p->pRgt);
				pAnotherstk->push(p->pLft);
			}
		}

		bL2R = !bL2R;
		stack<TREE_NODE*>* pTmp = pCurstk;
		pCurstk = pAnotherstk;
		pAnotherstk = pTmp;
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
	TREE_NODE* p8 = new TREE_NODE(8);

	p0->pLft = p1;
	p0->pRgt = p2;
	p1->pLft = p3;
	p1->pRgt = p4;
	p2->pLft = p5;
	p4->pLft = p7;
	p5->pRgt = p6;

	PrintZigZag(p0);
}