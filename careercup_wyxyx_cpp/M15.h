//You are given a NxN square board like chess. You are at the top left and 
//your destination is the bottom right. There are many blocks on the board 
//where you cannot go. At each step you can one block left, right, top, bottom 
//but not diagonal. Write an algorithm to traverse from home to destination ? 
//Print the path if you get to the destination or else return -1 if there is no legitimate path ?

//Solution:
//Use depth first search, remember the passed blocks should be recorded

const int EMPTY = 0;
const int BLOCKED = 1;
const int PASSED = 2;

struct LOCATION
{
	int x;
	int y;

	LOCATION(int nx, int ny) : x(nx), y(ny) {}
};

bool MarkPath(int** pMaze, int nX, int nY, int nCurX, int nCurY, stack<LOCATION>& stk)
{
	assert(pMaze[nCurX][nCurY] == EMPTY);
	pMaze[nCurX][nCurY] = PASSED;
	if (nCurX == nX-1 && nCurY == nY-1)
	{
		stk.push(LOCATION(nCurX, nCurY));
		return true;
	}

	bool ret = false;
	//go left
	if (nCurX-1 >= 0 && pMaze[nCurX-1][nCurY] == EMPTY && !ret)
	{
		ret = MarkPath(pMaze, nX, nY, nCurX-1, nCurY, stk);
		if (ret) stk.push(LOCATION(nCurX, nCurY));
	}

	//go right
	if (nCurX+1 < nX && pMaze[nCurX+1][nCurY] == EMPTY && !ret)
	{
		ret = MarkPath(pMaze, nX, nY, nCurX+1, nCurY, stk);
		if (ret) stk.push(LOCATION(nCurX, nCurY));
	}

	//go up
	if (nCurY-1 >= 0 && pMaze[nCurX][nCurY-1] == EMPTY && !ret)
	{
		ret = MarkPath(pMaze, nX, nY, nCurX, nCurY-1, stk);
		if (ret) stk.push(LOCATION(nCurX, nCurY));
	}

	//go down
	if (nCurY+1 < nY && pMaze[nCurX][nCurY+1] == EMPTY && !ret)
	{
		ret = MarkPath(pMaze, nX, nY, nCurX, nCurY+1, stk);
		if (ret) stk.push(LOCATION(nCurX, nCurY));
	}
	
	return ret;
}

void test()
{
	int**a;
	a = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = new int[10];
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = EMPTY;
		}

	a[0][1] = BLOCKED;
	a[1][1] = BLOCKED;
	a[2][2] = BLOCKED;
	a[9][3] = BLOCKED;

	stack<LOCATION> stk;
	if (!MarkPath(a, 10, 10, 0, 0, stk))
	{
		cout<<"Can not find a path"<<endl;
	}
	else
	{
		while (!stk.empty())
		{
			LOCATION loc = stk.top();
			stk.pop();
			cout<<loc.x<<" "<<loc.y<<endl;
		}
	}
}