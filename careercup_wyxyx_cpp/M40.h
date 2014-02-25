//Serialize/Unserialize 2 tree structure

//Solution:
//      1
//   2    3
//  4 5  6 7 8
//Serialize:
//1 2 3
//2 4 5
//3 6 7 8
#include <fstream>
#include <sstream>
using namespace std;

struct TREE_NODE
{
	int nValue;
	deque<TREE_NODE*> children;

	TREE_NODE(int n) : nValue(n) {}
	void InsertChild(TREE_NODE* pNode) { children.push_back(pNode); }
};

void Serialize(TREE_NODE* pRoot, const char* szFile)
{
	ofstream fs(szFile);
	deque<TREE_NODE*> que;
	que.push_front(pRoot);

	while(!que.empty())
	{
		TREE_NODE* pNode = que.back();
		que.pop_back();

		if (!pNode->children.empty() || pNode == pRoot)
			fs << pNode->nValue;

		for (deque<TREE_NODE*>::iterator it = pNode->children.begin();
			it != pNode->children.end(); it++)
		{
			TREE_NODE* pTmp = *it;
			fs << ' ' << pTmp->nValue;
			que.push_front(pTmp);
		}

		fs << endl;
	}
}

TREE_NODE* UnSerialize(const char* szFile)
{
	TREE_NODE* pRoot = NULL;
	deque<TREE_NODE*> que;
	ifstream fs(szFile);
	string s;

	bool bRoot = false;
	while (getline(fs, s))
	{
		stringstream ss;
		ss << s;
		
		int nParent = 0;
		ss >> nParent;
		if (!bRoot)
		{
			pRoot = new TREE_NODE(nParent);
			que.push_front(pRoot);
			bRoot = true;
		}

		TREE_NODE* pParent = que.back();
		que.pop_back();
		while (!ss.eof())
		{
			int i;
			ss >> i;

			TREE_NODE* pNode= new TREE_NODE(i);
			pParent->InsertChild(pNode);
			que.push_front(pNode);
		}
	}

	return pRoot;
}

void test()
{
	TREE_NODE* p1 = new TREE_NODE(1);
	TREE_NODE* p2 = new TREE_NODE(2);
	TREE_NODE* p3 = new TREE_NODE(3);
	TREE_NODE* p4 = new TREE_NODE(4);
	TREE_NODE* p5 = new TREE_NODE(5);
	TREE_NODE* p6 = new TREE_NODE(6);
	TREE_NODE* p7 = new TREE_NODE(7);
	TREE_NODE* p8 = new TREE_NODE(8);

	//1 2 3
	//2 4 5
	//3 6 7 8
	p1->InsertChild(p2);
	p1->InsertChild(p3);

	p2->InsertChild(p4);
	p2->InsertChild(p5);

	p3->InsertChild(p6);
	p3->InsertChild(p7);
	p3->InsertChild(p8);

	Serialize(p1, "c:\\TREE_SERIALIZE.txt");
	TREE_NODE* pRoot = UnSerialize("c:\\TREE_SERIALIZE.txt");
}