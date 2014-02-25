//write c code for checking if given binary tree is balanced ?

struct TREE_NODE 
{
	int nValue;
	TREE_NODE* pLft;
	TREE_NODE* pRgt;

	TREE_NODE(int n) : nValue(n), pLft(NULL), pRgt(NULL)
	{}
};

bool IsBalance(TREE_NODE* pRoot, int& nHight)
{
	if (pRoot == NULL)
	{
		nHight = 0;
		return true;
	}

	int nHLft = 0;
	int nHRgt = 0;

	if (!IsBalance(pRoot->pLft, nHLft) || !IsBalance(pRoot->pRgt, nHRgt))
		return false;

	if (nHLft-nHRgt > 1 || nHLft-nHRgt < -1)
		return false;

	nHight = (nHLft>nHRgt) ? nHLft+1 : nHRgt+1;
	return true;
}
	/*	   0
		 1   2
		3 4 5 6
			7
*/

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
	//n0.pRgt = &n2;
	n1.pLft = &n3;
	//n1.pRgt = &n4;
	/*n2.pLft = &n5;
	n2.pRgt = &n6;
	n5.pRgt = &n7;*/

	int nh;
	cout<<IsBalance(&n0, nh)<<endl;
}