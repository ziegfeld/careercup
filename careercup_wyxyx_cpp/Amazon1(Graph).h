//A semi-connected graph is a graph that for each pair of vertices u,v, 
//there is either a path from u to v or a path from v to u. Give an algorithm to test if a graph is semi-connected.

//Solution:
//Please refer to below documents:
//http://hi.baidu.com/shcup/blog/item/8e4fd64f191e13c3d1c86a35.html
//http://wenku.baidu.com/view/ceb92fe2524de518964b7d66.html
//http://hi.baidu.com/19930705cxjff/blog/item/3a390f73e691ae0f8601b049.html

#include <stack>
using namespace std;

class CGraph
{
public:
	CGraph(int nPoints);
	~CGraph();
	virtual void AddEdge(int nFrom, int nTo) = 0;

protected:
	bool** m_pGraph;
	int m_nPoints;
};

inline CGraph::CGraph(int nPoints)
{
	assert(nPoints>0);

	m_nPoints = nPoints;
	m_pGraph = new bool*[m_nPoints];
	for (int i = 0; i < m_nPoints; i++)
	{
		m_pGraph[i] = new bool[m_nPoints];
		for (int j = 0; j < m_nPoints; j++)
			m_pGraph[i][j] = false;
	}
}

inline CGraph::~CGraph()
{
	for (int i = 0; i < m_nPoints; i++)
		delete []m_pGraph[i];
	delete []m_pGraph;
}

class CBiGraph : public CGraph
{
public:
	CBiGraph(int nPoints) : CGraph(nPoints) {}
	void AddEdge(int nFrom, int nTo)
	{
		assert(nFrom>=0 && nFrom<m_nPoints);
		assert(nTo>=0 && nTo<m_nPoints);
		m_pGraph[nFrom][nTo] = true;
		m_pGraph[nTo][nFrom] = true;
	}

	void PrintCutPoints();

private:
	void _inner_cut_points(int nPrevPt, int nCurPt, bool bPtPassed[], int nPtDepth[] , int nLowst[], int nCurDepth);
};

class CDirGraph : public CGraph
{
public:
	CDirGraph(int nPoints) : CGraph(nPoints) {}
	void AddEdge(int nFrom, int nTo)
	{
		assert(nFrom>=0 && nFrom<m_nPoints);
		assert(nTo>=0 && nTo<m_nPoints);
		m_pGraph[nFrom][nTo] = true;
	}

	//Strongly Connected and Directed Network
	void PrintLgstConGrph();

	//Kosaraju method to get strongest connected graph
	void PrintStrongConnKosaraju();

private:
	void _inner_Kosaraju_DFS1(int nCurPt, stack<int>& stk, bool pPassed[]);
	void _inner_Kosaraju_DFS2(int nCurPt, bool pPassed[]);
	void _inner_lgst_conn(int nCurPt, stack<int>& stk, bool bPtPassed[], int nPtLow[]);
};

inline void CDirGraph::PrintStrongConnKosaraju()
{
	bool* pPassed = new bool[m_nPoints];
	for (int i = 0; i < m_nPoints; i++)
		pPassed[i] = false;
	
	stack<int> stk;
	for (int i = 0; i < m_nPoints; i++)
	{
		if (!pPassed[i])
			_inner_Kosaraju_DFS1(i, stk, pPassed);
	}

	for (int i = 0; i < m_nPoints; i++)
		pPassed[i] = false;

	while (!stk.empty())
	{
		int n = stk.top();
		stk.pop();

		if (!pPassed[n])
		{
			cout<<"***** ";
			_inner_Kosaraju_DFS2(n, pPassed);
			cout<<"*****"<<endl;
		}
	}

	delete []pPassed;
}

void CDirGraph::_inner_Kosaraju_DFS1(int nCurPt, stack<int>& stk, bool pPassed[])
{
	pPassed[nCurPt] = true;

	for (int i = 0; i < m_nPoints; i++)
	{
		if (m_pGraph[nCurPt][i] && !pPassed[i])
			_inner_Kosaraju_DFS1(i, stk, pPassed);
	}

	stk.push(nCurPt);
}

void CDirGraph::_inner_Kosaraju_DFS2(int nCurPt, bool pPassed[])
{
	pPassed[nCurPt] = true;
	cout<<nCurPt<<" ";
	for (int i = 0; i < m_nPoints; i++)
	{
		if (m_pGraph[i][nCurPt] && !pPassed[i])
			_inner_Kosaraju_DFS2(i, pPassed);
	}
}

bool inStack(stack<int>& stk, int x)
{
	stack<int> stkTmp;
	bool bRet = false;
	while (!stk.empty())
	{
		int n = stk.top();
		if (n == x)
		{
			bRet = true;
			break;
		}

		stkTmp.push(n);
		stk.pop();
	}

	while (!stkTmp.empty())
	{
		stk.push(stkTmp.top());
		stkTmp.pop();
	}

	return bRet;
}

bool LowerThan(stack<int>& stk, int nLft, int nRgt)
{
	stack<int> stkTmp;
	bool bRet = false;
	while (!stk.empty())
	{
		int n = stk.top();
		if (n == nRgt)
		{
			bRet = true;
			break;
		}

		if (n == nLft) break;

		stkTmp.push(n);
		stk.pop();
	}

	while (!stkTmp.empty())
	{
		stk.push(stkTmp.top());
		stkTmp.pop();
	}

	return bRet;
}

inline void CDirGraph::_inner_lgst_conn(int nCurPt, stack<int>& stk, bool bPtPassed[], int nPtLow[])
{
	bPtPassed[nCurPt] = true;
	stk.push(nCurPt);

	int nLow = nPtLow[nCurPt];
	for (int i = 0; i < m_nPoints; i++)
	{
		if (m_pGraph[nCurPt][i])
		{
			if (!bPtPassed[i])
				_inner_lgst_conn(i, stk, bPtPassed, nPtLow);
			
			if (inStack(stk, i) && LowerThan(stk, nPtLow[i], nPtLow[nCurPt]))
				nPtLow[nCurPt] = nPtLow[i];
		}
	}

	if (nPtLow[nCurPt] == nCurPt)
	{
		cout<<"*** ";
		while (!stk.empty())
		{
			int n = stk.top();
			stk.pop();

			cout<<n<<" ";
			if (n == nCurPt) break;
		}
		cout<<"****"<<endl;
	}
}

inline void CDirGraph::PrintLgstConGrph()
{
	stack<int> stk;
	bool* pPassed = new bool[m_nPoints];
	int*  pLow = new int[m_nPoints];
	for (int i = 0; i < m_nPoints; i++)
	{
		pPassed[i] = false;
		pLow[i] = i;
	}

	for (int i = 0; i < m_nPoints; i++)
	{
		if (!pPassed[i])
			_inner_lgst_conn(i, stk, pPassed, pLow);
	}

	delete []pPassed;
	delete []pLow;
}

inline void CBiGraph::PrintCutPoints()
{
	cout<<"Cut points : "<<endl;
	bool* pPassed = new bool[m_nPoints];
	int*  pDepth =	new int[m_nPoints];
	int*  pLow =	new int[m_nPoints];
	for (int i = 0; i < m_nPoints; i++)
	{
		pPassed[i] = false;
		pDepth[i] = 0;
		pLow[i] = 0;
	}
	
	int nChld = 0;
	pPassed[0] = true;
	for (int i = 1; i < m_nPoints; i++)
	{
		if (!pPassed[i])
		{
			nChld++;
			_inner_cut_points(0, i, pPassed, pDepth, pLow, 1);
		}
	}

	if (nChld > 1) cout<<0<<endl;

	delete []pLow;
	delete []pPassed;
	delete []pDepth;
}

inline void CBiGraph::_inner_cut_points(int nPrevPt, int nCurPt, bool bPtPassed[], int nPtDepth[], int nLowst[], int nCurDepth)
{
	bPtPassed[nCurPt] = true;
	nPtDepth[nCurPt] = nCurDepth;
	nLowst[nCurPt] = nCurDepth;

	bool bCut = false;
	for (int i = 0; i < m_nPoints; i++)
	{
		if (m_pGraph[nCurPt][i] && i != nPrevPt)
		{
			if (!bPtPassed[i])
				_inner_cut_points(nCurPt, i, bPtPassed, nPtDepth, nLowst, nCurDepth+1);

			if (nPtDepth[nCurPt] <= nLowst[i])
			{
				if (bCut == false)
				{
					bCut = true;
					cout<<nCurPt<<endl;
				}
			}
			
			if (nLowst[nCurPt] > nLowst[i])
				nLowst[nCurPt] = nLowst[i];
		}
	}
}

void test()
{
	CDirGraph dgrph(6);
	dgrph.AddEdge(0,1);
	dgrph.AddEdge(1,2);
	dgrph.AddEdge(2,0);
	dgrph.AddEdge(0,3);
	dgrph.AddEdge(3,2);
	dgrph.AddEdge(3,4);
	dgrph.AddEdge(4,5);

	dgrph.PrintStrongConnKosaraju();
}