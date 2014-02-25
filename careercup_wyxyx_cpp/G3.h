//you have a bag full of airplane tickets with various destinations. 
//given two destinations find those tickets in the bag and give the 
//cheapest routing in the least time possible

//Solution:
//Each ticket can be viewed as a path in a directed graph with the price the cost of this path
//The problem becomes given a directed graph, find the path between two points with the least cost

class CGraph
{
public :
	CGraph(int n);
	~CGraph();

public:
	void inputEdge(int nIndex1, int nIndex2, int nCost);
	void PrintCheapestRout(int nIndex1, int nIndex2);

private:
	int m_nNodes;
	int** m_pGraph;

private:
	struct DIST_REC 
	{
		int nCost;
		int nPrev;
		bool bCalc;

		DIST_REC() { nCost = 0; nPrev = -1; bCalc = false; }
	};
};

inline CGraph::CGraph(int n)
{
	assert(n>0);

	m_nNodes = n;
	m_pGraph = new int*[m_nNodes];
	for (int i = 0; i < m_nNodes; i++)
	{
		m_pGraph[i] = new int[n];
		memset(m_pGraph[i], 0, n);
	}
}

inline CGraph::~CGraph()
{
	for (int i = 0; i < m_nNodes; i++)
	{
		delete [](m_pGraph[i]);
	}

	delete []m_pGraph;
}

inline void CGraph::inputEdge(int nIndex1, int nIndex2, int nCost)
{
	if (nIndex1 < 0 || nIndex1 >= m_nNodes) return;
	if (nIndex2 < 0 || nIndex2 >= m_nNodes) return;
	if (nCost <= 0) return;

	m_pGraph[nIndex1][nIndex2] = nCost;
}

inline void CGraph::PrintCheapestRout(int nIndex1, int nIndex2)
{
	DIST_REC* pRec = new DIST_REC[m_nNodes];
	deque<int> que;
	que.push_back(nIndex1);

	while (!que.empty())
	{
		int nIndex = que.front();
		que.pop_front();
		pRec[nIndex].bCalc = true;

		for (int i = 0; i < m_nNodes; i++)
		{
			if (i != nIndex && m_pGraph[nIndex][i] > 0)
			{
				que.push_back(i);
				if (pRec[i].nPrev == -1 || pRec[i].nCost > m_pGraph[nIndex][i] + pRec[nIndex].nCost)
				{
					pRec[i].nPrev = nIndex;
					pRec[i].nCost = m_pGraph[nIndex][i] + pRec[nIndex].nCost;
				}
			}
		}
	}

	if (pRec[nIndex2].nCost <= 0)
	{
		cout<<"No path to destination"<<endl;
	}
	else
	{
		cout<<"Cost : "<<pRec[nIndex2].nCost<<endl;
		stack<int> stk;
		int nIter = nIndex2;
		while (nIter >= 0)
		{
			stk.push(nIter);
			nIter = pRec[nIter].nPrev;
		}

		while (!stk.empty())
		{
			int n = stk.top();
			cout<<n<<endl;
			stk.pop();
		}
	}

	delete []pRec;
}

void test()
{
	CGraph gph(5);
	gph.inputEdge(0, 2, 2);
	gph.inputEdge(2, 3, 10);
	gph.inputEdge(0, 3, 20);
	gph.inputEdge(0, 2, 2);
	gph.inputEdge(2, 1, 1);
	gph.inputEdge(0, 1, 5);
	gph.inputEdge(1, 3, 12);
	gph.inputEdge(1, 4, 2);
	gph.inputEdge(4, 3, 3);

	gph.PrintCheapestRout(0, 3);
}