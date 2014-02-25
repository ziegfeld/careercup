//Given an m x n binary matrix. Find the maximum all 0 submatrix (not necessarily square submatrix).

//Solution:
//Use dynamic programing to reduce the time complexity to O(m*n*n), however, the space complexity would
//be O(m*m*n). Make a three dimensional array, says bool a[m][m][n], if a[i][j][k] represent true, it means
//all the number between i and j in column k are 0. Record the maximum rectangle which all contains 0 during
//the process of filling up this three dimensional array.

class CDPRec
{
public:
	CDPRec(int nRow, int nCol) : m_nRow(nRow), m_nCol(nCol)
	{
		assert(nRow>0 && nCol>0);
		m_pDPRec = new bool[m_nRow*m_nRow*m_nCol];
		for (int i = 0; i < m_nRow*m_nRow*m_nCol; i++) m_pDPRec[i] = false;
	}

	~CDPRec() { delete []m_pDPRec; }
	bool& GetElem(int i, int j, int k) { return m_pDPRec[i*m_nRow*m_nCol+j*m_nCol+k]; }

private:
	bool* m_pDPRec;
	int m_nRow;
	int m_nCol;
};

void FindLZeroRec(int** pArr, int m, int n)
{
	assert(pArr);
	assert(m>0);
	assert(n>0);

	int nMaxi = 0;
	int nMaxj = 0;
	int nMaxk = 0;
	int nLong = 0;
	int nMaxRec = 0;

	CDPRec rec(m,n);

	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (i == j)
					rec.GetElem(i, j, k) = (pArr[j][k] == 0);
				else 
				{
					if (pArr[j][k] == 0 && rec.GetElem(i, j-1, k))
						rec.GetElem(i, j, k) = true;
					else
						rec.GetElem(i, j, k) = false;
				}
			}
			
			int nMaxKVal = 0;
			int nMaxZero = 0;
			int nCurK = 0;
			int nCurZero = 0;
			for (int k = 0; k < n; k++)
			{
				if (rec.GetElem(i, j, k))
				{
					if (nCurZero == 0)  
						nCurK = k;
					nCurZero++;
				}
				
				if (!rec.GetElem(i, j, k) || k == n-1)
				{
					if (nCurZero > nMaxZero)
					{
						nMaxZero = nCurZero;
						nMaxKVal = nCurK;
					}
					nCurZero = 0;
				}
			}

			int nCurRec = (j-i+1)*nMaxZero;
			if (nCurRec > nMaxRec)
			{
				nMaxRec = nCurRec;
				nMaxi = i;
				nMaxj = j;
				nMaxk = nMaxKVal;
				nLong = nMaxZero;
			}
		}

		cout << "Row : " <<nMaxi<<" ==== "<<nMaxj<<endl;
		cout << "Col : " <<nMaxk<<" ==== "<<nMaxk+nLong-1<<endl;
}

//0 0 0 1
//1 1 2 2
//1 0 0 0
//2 0 0 1
void test()
{
	int** pArr = new int*[4];
	for (int i = 0; i < 4; i++)
		pArr[i] = new int[4];

	pArr[0][0] = 0;
	pArr[0][1] = 0;
	pArr[0][2] = 0;
	pArr[0][3] = 1;

	pArr[1][0] = 1;
	pArr[1][1] = 1;
	pArr[1][2] = 2;
	pArr[1][3] = 2;

	pArr[2][0] = 1;
	pArr[2][1] = 0;
	pArr[2][2] = 0;
	pArr[2][3] = 0;

	pArr[3][0] = 2;
	pArr[3][1] = 0;
	pArr[3][2] = 0;
	pArr[3][3] = 1;

	FindLZeroRec(pArr, 4, 4);
}