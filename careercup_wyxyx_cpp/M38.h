//Write an efficient program to find an element in a two dimensional matrix, 
//the rows and columns of which are increasing monotonically. 
//(Rows and columns are increasing from top to bottom and from left to right).

//Solution:
//*//A : */start at a point that: the elements at one its side follows different sorting sequence from another side. lets' say:
// 1  2  3  4
// 3  5  8  9
// 6  7  8  10
// 11 15 18 20;
//in this case you choose either 4 or 11.
//then if the current number is smaller than you expect, move towards decreasing side, else moves towards increasing side...
//let's say you choose 4, you find 7.
//first move down, then move left, then move left, then move down...
//O(n)

//Optimize this solution by binary search!

// 1  2  3  4
// 3  5  8  9
// 6  7  8  10
// 11 15 18 20; 
//Notice the special property of this matrix. For number x (i,j), the rectangle formed by top left point and x are all less or equal
//than x and the rectangle formed by x and right bottom are all larger or equal than x, this property can be used to prove this approach
/********************************************************************************************************************************/

//Holly shite, passed at the first time!!!!!!!!!!!!!!!!!
//I'm a genius 
void FindElement(int** pArr, int m, int n, int nToFound)
{
	assert(pArr);
	assert(m>0);
	assert(n>0);

	bool bFound = false;
	bool bFoundInRow = false;

	//nRow to m-1; 0 to nCol
	int nRow = 0;
	int nCol = n-1;

	while (!bFound)
	{
		if (bFoundInRow && nRow < m && nCol > 0)
		{
			//binary search in row
			int nLow = 0;
			int nHigh = nCol;

			while (nLow <= nHigh)
			{
				int nMid = (nLow+nHigh)/2;
				if (pArr[nRow][nMid] == nToFound)
				{
					nCol = nMid;
					bFound = true;
					break;
				}

				//Find the first smaller than nToFound
				if (pArr[nRow][nMid] > nToFound)
				{
					nHigh = nMid-1;
				}
				else
				{
					if (pArr[nRow][nMid] < nToFound && (nMid == nCol || pArr[nRow][nMid+1] > nToFound))
					{
						nRow++;
						nCol = nMid;
						break;
					}
					nHigh = nMid-1;
				}
			}

			bFoundInRow = !bFoundInRow;
		}
		else
		{
			//binary search in col
			int nLow = nRow;
			int nHigh = m-1;

			while (nLow <= nHigh)
			{
				int nMid = (nLow+nHigh)/2;
				if (pArr[nMid][nCol] == nToFound)
				{
					nRow = nMid;
					bFound = true;
					break;
				}

				//Find the first bigger than nToFound
				if (pArr[nMid][nCol] < nToFound)
				{
					nLow = nMid+1;
				}
				else
				{
					if (pArr[nMid][nCol] > nToFound && (nMid == nRow || pArr[nMid-1][nCol] < nToFound))
					{
						nRow = nMid;
						nCol--;
						break;
					}
					nHigh = nMid-1;
				}
			}

			bFoundInRow = !bFoundInRow;
		}
	}

	if (bFound)
		cout<<nToFound<<" is at row : "<<nRow+1<<" Col : "<<nCol+1<<endl;
	else
		cout<<"Not found"<<endl;
}

void test()
{
	// 1  2  3  4
	// 3  5  8  9
	// 6  7  8  10
	// 11 15 18 20; 
	int** pArr = new int*[4];
	for (int i = 0; i < 4; i++)
		pArr[i] = new int[4];

	pArr[0][0] = 1;
	pArr[0][1] = 2;
	pArr[0][2] = 3;
	pArr[0][3] = 4;

	pArr[1][0] = 3;
	pArr[1][1] = 5;
	pArr[1][2] = 8;
	pArr[1][3] = 9;

	pArr[2][0] = 6;
	pArr[2][1] = 7;
	pArr[2][2] = 8;
	pArr[2][3] = 10;

	pArr[3][0] = 11;
	pArr[3][1] = 15;
	pArr[3][2] = 18;
	pArr[3][3] = 20;

	FindElement(pArr, 4, 4, 20);
}