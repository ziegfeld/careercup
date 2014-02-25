//Given a binary tree with the following node structure
//struct node
//{
//	data
//	pointer to left subtree
//	pointer to right subtree
//	pointer to sibling
//
//};
//The sibling pointers are NULL for all the nodes.Make the sibling pointers 
//point to their respective nodes in O(n)time complexity

//Solution
//Top down recursion

struct TREE_NODE
{
	int m_nData;
	TREE_NODE* m_pLft;
	TREE_NODE* m_pRgt;
	TREE_NODE* m_pSib;

	TREE_NODE(int n) : m_nData(n), m_pLft(NULL), m_pRgt(NULL), m_pSib(NULL)
	{}
};

void LinkSiblings(TREE_NODE* pParent)
{
	assert(NULL != pParent);

	if (NULL != pParent->m_pLft)
	{
		pParent->m_pLft->m_pSib = pParent->m_pRgt;
		LinkSiblings(pParent->m_pLft);
	}

	if (NULL != pParent->m_pRgt)
	{
		pParent->m_pRgt->m_pSib = pParent->m_pLft;
		LinkSiblings(pParent->m_pRgt);
	}
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

	node0.m_pLft = &node1;
	node0.m_pRgt = &node2;
	node1.m_pLft = &node3;
	node1.m_pRgt = &node4;
	node2.m_pLft = &node5;
	node2.m_pRgt = &node6;
	node6.m_pRgt = &node7;

	LinkSiblings(&node0);

	for (vector<TREE_NODE*>::iterator it = vec.begin();
		it != vec.end(); it++)
	{
		if ((*it)->m_pSib)
			cout<<(*it)->m_nData<<" sibling "<<(*it)->m_pSib->m_nData<<endl;
	}
}