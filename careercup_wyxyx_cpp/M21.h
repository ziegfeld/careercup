//Do iterative post order traversal without keeping visited flag

//Solution:
//Of course we can use stack to do this, the problem is how to get the sibling of
//a given node. The answer is by its parent. How to get the parent? Of course the one
//next to it in the stack!

//This problem is really a tough one!!! Not that easy as it looks like

struct TREE_NODE 
{
	int nValue;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;

	TREE_NODE(int n) : nValue(n)
	{
		pLft = NULL;
		pRgt = NULL;
	}
};

void PostOrderTravel(TREE_NODE* pRoot)
{
	assert(pRoot);

	stack<TREE_NODE*> stk;
	stk.push(pRoot);

	while (!stk.empty())
	{
		TREE_NODE* pTop = stk.top();
		if (pTop->pLft != NULL)
			stk.push(pTop->pLft);
		else if (pTop->pRgt != NULL)
			stk.push(pTop->pRgt);
		else
		{
			while (!stk.empty())
			{
				pTop = stk.top();
				cout<<pTop->nValue<<endl;
				stk.pop();

				if (stk.empty()) break;

				TREE_NODE* pParent = stk.top();
				if (pParent->pRgt == pTop || (pParent->pLft == pTop && pParent->pRgt == NULL))
					continue;
				else
				{
					assert(pParent->pLft == pTop && pParent->pRgt != NULL);
					stk.push(pParent->pRgt);
					break;
				}
			}
		}
	}
}

void test()
{
	TREE_NODE node0(0);
	TREE_NODE node1(1);
	TREE_NODE node2(2);
	TREE_NODE node3(3);
	TREE_NODE node4(4);
	TREE_NODE node5(5);
	TREE_NODE node6(6);
	TREE_NODE node7(7);

	node0.pLft = &node1;
	node0.pRgt = &node2;
	node1.pLft = &node3;
	node1.pRgt = &node4;
	node2.pLft = &node5;
	node2.pRgt = &node6;
	node6.pRgt = &node7;

	PostOrderTravel(&node0);
}