//Given a set of points (x,y) on a 2D coord system, identify list of 
//2D coords that are of distance less than x units long.
//Let x = 1;
//Given (0,0), (0,1), (1, 2), (4,6);
//Return 1 -> (0,0), (0,1)

// No a satisfied solution to above problem
// Below is the solution of the closest pair problem
// the closest pair solution is so complex that you better search it on google
// the resolution of closest pair problem is based on divided and conquer concept
// which only cost O(nlogn) time complexity

struct POINT2D
{
	double x;
	double y;

	POINT2D(double nx = 0.0, double ny = 0.0) : x(nx), y(ny) {} 
};

double CalcDistSquare(POINT2D& p1, POINT2D& p2)
{
	double fx = p1.x - p2.x;
	double fy = p1.y - p2.y;
	return fx*fx+fy*fy;
}

struct INDEX_POINT : public POINT2D 
{
	int nIndex;

	void attach(int index, POINT2D& p)
	{
		nIndex = index;
		x = p.x;
		y = p.y;
	}
};

class CSortX
{
public:
	bool operator()(const INDEX_POINT& p1, const INDEX_POINT& p2)
	{
		return p1.x < p2.x;
	}
};

class CSortY
{
public:
	bool operator()(const INDEX_POINT& p1, const INDEX_POINT& p2)
	{
		return p1.y < p2.y;
	}
};

void closest(POINT2D points[], int nOrg, int pfX[], int pfY[], int n, int& n1, int& n2);
void PrintClosetPair(POINT2D points[], int n)
{
	assert(points);
	assert(n>1);

	INDEX_POINT* pXOrder = new INDEX_POINT[n];
	INDEX_POINT* pYOrder = new INDEX_POINT[n];

	for (int i = 0; i < n; i++)
	{
		pXOrder[i].attach(i, points[i]);
		pYOrder[i].attach(i, points[i]);
	}

	sort(pXOrder, pXOrder+n, CSortX());
	sort(pYOrder, pYOrder+n, CSortY());

	int *pXIndex = new int[n];
	int *pYIndex = new int[n];
	for (int i = 0; i < n; i++)
	{
		pXIndex[i] = pXOrder[i].nIndex;
		pYIndex[i] = pYOrder[i].nIndex;
	}

	delete []pXOrder;
	delete []pYOrder;

	int n1 = 0;
	int n2 = 0;
	closest(points, n, pXIndex, pYIndex, n, n1, n2);
	delete []pXIndex;
	delete []pYIndex;

	cout<<"Closest points are :"<<endl;
	cout<<"("<<points[n1].x<<", "<<points[n1].y<<")"<<endl;
	cout<<"("<<points[n2].x<<", "<<points[n2].y<<")"<<endl;
}

void closest(POINT2D points[], int nOrg, int pfX[], int pfY[], int n, int& n1, int& n2)
{
	assert(n>1);
	if (n == 2)
	{
		n1 = pfX[0];
		n2 = pfX[1];
		return;
	}

	if (n == 2)
	{
		double d01 = CalcDistSquare(points[pfX[0]], points[pfX[1]]);
		double d02 = CalcDistSquare(points[pfX[0]], points[pfX[2]]);
		double d12 = CalcDistSquare(points[pfX[1]], points[pfX[2]]);

		if (d01 >= d02 && d01 >= d12)
		{
			n1 = pfX[0];
			n2 = pfX[1];
			return;
		}

		if (d02 >= d01 && d02 >= d12)
		{
			n1 = pfX[0];
			n2 = pfX[2];
			return;
		}

		if (d12 >= d01 && d02 >= d02)
		{
			n1 = pfX[1];
			n2 = pfX[2];
			return;
		}
	}

	int nLft = n/2;
	int* pXLft = new int[nLft];
	int* pYLft = new int[nLft];
	int nRgt = n-nLft;
	int* pXRgt = new int[nRgt];
	int* pYRgt = new int[nRgt];
	int* pRec = new int[nOrg];
	memset(pRec, 0, nOrg*sizeof(int));

	// init pXLft pXRgt
	for (int i = 0; i < nLft; i++) pXLft[i]=pfX[i];
	for (int i = 0; i < nRgt; i++) pXRgt[i]=pfX[i+nLft];
	// init pYRgt pYLft
	for (int i = 0; i < nLft; i++)
		pRec[pfX[i]] = 1;
	for (int i = nLft; i < n; i++)
		pRec[pfX[i]] = 2;
	int nIterL = 0;
	int nIterR = 0;
	for (int i = 0; i < n; i++)
	{
		if (pRec[pfY[i]] == 1) pYLft[nIterL++] = pfY[i];
		if (pRec[pfY[i]] == 2) pYRgt[nIterR++] = pfY[i];
	}
	delete []pRec;

	int n1Lft = 0;
	int n2Lft = 0;
	closest(points, nOrg, pXLft, pYLft, nLft, n1Lft, n2Lft);
	double nDLft = CalcDistSquare(points[n1Lft], points[n2Lft]);

	int n1Rgt = 0;
	int n2Rgt = 0;
	closest(points, nOrg, pXRgt, pYRgt, nRgt, n1Rgt, n2Rgt);
	double nDRgt = CalcDistSquare(points[n1Rgt], points[n2Rgt]);
	
	double dMin = 0.0;
	if (nDLft < nDRgt)
	{
		dMin = nDLft;
		n1 = n1Lft;
		n2 = n2Lft;
	}
	else
	{
		dMin = nDRgt;
		n1 = n1Rgt;
		n2 = n2Rgt;
	}

	// Find points satisfied X scope
	int* pScopeL = new int[nLft];
	int nScopeL = 0;
	int* pScopeR = new int[nRgt];
	int nScopeR = 0;
	double fDelimite = points[pXLft[nLft-1]].x +((points[pXRgt[0]].x-points[pXLft[nLft-1]].x)/2);
	for (int i = 0; i < nLft; i++)
	{
		double nDx = points[pYLft[i]].x-fDelimite;
		if (nDx*nDx < dMin) pScopeL[nScopeL++]=pYLft[i];
	}
	for (int i = 0; i < nRgt; i++)
	{
		double nDx = points[pYRgt[i]].x-fDelimite;
		if (nDx*nDx < dMin) pScopeR[nScopeR++]=pYRgt[i];
	}

	int nYLevel = 0;
	for (int i = 0; i < nScopeL; i++)
	{
		bool bLevelSet = false;
		for (int j = nYLevel; j < nScopeR; j++)
		{
			double dYSqur = points[pScopeL[i]].y-points[pScopeR[j]].y;
			dYSqur *= dYSqur;
			if (dYSqur < dMin)
			{
				if (!bLevelSet)
				{
					bLevelSet = true;
					nYLevel = j;
				}
				
				double d = CalcDistSquare(points[pScopeL[i]], points[pScopeR[j]]);
				if (d < dMin)
				{
					dMin = d;
					n1 = pScopeL[i];
					n2 = pScopeR[j];
				}
			}
			else
			{
				if (points[pScopeR[j]].y > points[pScopeL[i]].y)
				{
					if (!bLevelSet) nYLevel = j;
					break;
				}
			}
		}
	}

	delete []pScopeL;
	delete []pScopeR;
	delete []pXLft;
	delete []pYLft;
	delete []pXRgt;
	delete []pYRgt;
}

void test()
{
	POINT2D points[8];
	points[0].x = 1.3;
	points[0].y = 2.4;
	points[1].x = -35;
	points[1].y = 4.7;
	points[2].x = 3.54;
	points[2].y = -55.6;
	points[3].x = 3.45;
	points[3].y = 567.43;
	points[4].x = 1.1;
	points[4].y = 1.2;
	points[5].x = 3.65;
	points[5].y = 31.2;
	points[6].x = 1.1;
	points[6].y = 1.21;
	/*points[7].x = 44.32;
	points[7].y = 6.45;*/

	PrintClosetPair(points, 8);
}