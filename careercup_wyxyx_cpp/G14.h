//You are given a matrix of size M rows and N columns. A is the first element i.e. 
//mat[i][j] where i=j=0, and B is the end point i.e. i=M and j=N. There is a robot at A 
//and it can only move one step right or go down one step. There are walls in the matrix denoted by X. 
//The robot cant make his move when it encounters a wall on right or on its way down. Find the number 
//of paths from starting point A to the end point of the matrix B for the robot.
//hint:recursion with condition checking for the end point and the wall.

//Solution:
//Pretty easy one, recursion and counting with condition check...
//any more challenge??

int GetNumOfWays(bool** pRec, int m, int n, int i, int j)
{
	assert(pRec);
	assert(m > 0 && n > 0);
	assert(i >= 0 && i <= m);
	assert(j >= 0 && j <= n);

	if (i >= m || j >= n) return 0;
	if (i == m-1 && j == n-1) return 1;
	if (pRec[i][j]) return 0;

	return GetNumOfWays(pRec, m, n, i+1, j)+GetNumOfWays(pRec, m, n, i, j+1);
}

void test()
{
	bool** pRec = new bool*[3];
	for (int i = 0; i < 3; i++)
	{
		pRec[i] = new bool[2];
		pRec[i][0] = pRec[i][1] = false;
	}

	//pRec[1][1] = true;
	//pRec[2][0] = true;
	cout<<GetNumOfWays(pRec, 3, 2, 0, 0)<<endl;
}