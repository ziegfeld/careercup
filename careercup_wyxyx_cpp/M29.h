//Given a character string, find out all the English words contained in the string. Optimize the solution.
//Solution:
//Construct the dictionary in a trie tree and search all the string's suffix by suffix tree.

class CTrieTree
{
	struct TRIE_NODE;
public:
	CTrieTree() { m_pRoot = new TRIE_NODE('\0'); }
	~CTrieTree() { _inner_release(m_pRoot); }

	void LoadAWord(const char* szWord);
	void MatchPath(const char* szWord, deque<string>& que);

protected:
	TRIE_NODE* m_pRoot;

protected:
	void _inner_release(TRIE_NODE* pNode);
	struct TRIE_NODE 
	{
		bool bEnd;
		char chr;
		deque<TRIE_NODE*> children;

		TRIE_NODE(const char c) : chr(c), bEnd(false) {}
		
		TRIE_NODE* FindNode(const char c)
		{
			deque<TRIE_NODE*>::iterator iter = children.begin();
			while (iter != children.end())
			{
				TRIE_NODE* pNd = *iter;
				if (pNd->chr == c)
					return pNd;

				iter++;
			}

			return NULL;
		}

		TRIE_NODE* Insert(const char c)
		{
			TRIE_NODE* pMatch = FindNode(c);
			if (NULL == pMatch)
			{
				pMatch = new TRIE_NODE(c);
				children.push_back(pMatch);
			}
			
			return pMatch;
		}
	};
};

inline void CTrieTree::_inner_release(TRIE_NODE* pNode)
{
	if (NULL == pNode) return;

	for (deque<TRIE_NODE*>::iterator it = pNode->children.begin();
	it != pNode->children.end(); it++)
	{
		_inner_release(*it);
	}

	delete pNode;
}

inline void CTrieTree::LoadAWord(const char* szWord)
{
	if (*szWord == '\0') return;

	const char* pIter = szWord;
	TRIE_NODE* pNode = m_pRoot;
	while ('\0' != *pIter)
	{
		pNode = pNode->Insert(*pIter);
		pIter++;
	}

	pNode->bEnd = true;
}

inline void CTrieTree::MatchPath(const char* szWord, deque<string>& que)
{
	string strRecrd;
	TRIE_NODE* pSearch = m_pRoot;
	while (NULL != pSearch && szWord != '\0')
	{
		strRecrd.append(1, *szWord);
		pSearch = pSearch->FindNode(*szWord);

		if (NULL != pSearch && pSearch->bEnd)
			que.push_back(strRecrd);

		szWord++;
	}
}

void PrintAllWords(CTrieTree& tree, const char* pStr)
{
	while (*pStr != '\0')
	{
		deque<string> que;
		tree.MatchPath(pStr, que);
		for (deque<string>::iterator it = que.begin();
			it != que.end(); it++)
		{
			string& str = *it;
			cout<<str.c_str()<<endl;
		}

		pStr++;
	}
}

void test()
{
	CTrieTree tree;
	tree.LoadAWord("car");
	tree.LoadAWord("carp");
	tree.LoadAWord("port");
	tree.LoadAWord("a");

	PrintAllWords(tree, "carport");
}