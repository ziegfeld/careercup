//Write a function to generate all possible n pairs of balanced parentheses. For example, if n=1
//{}
//for n=2
//{}{}
//{{}}

void _inner_print(deque<char>& que, int nPairs, int nLeft, int nRight)
{
	if (nLeft == nPairs && nRight == nPairs)
	{
		for (deque<char>::iterator it = que.begin(); it != que.end(); it++)
			cout<<*it<<" ";
		cout<<endl;
		return;
	}

	if (nLeft < nPairs && nLeft >= nRight)
	{
		que.push_back('{');
		_inner_print(que, nPairs, nLeft+1, nRight);
		que.pop_back();
	}

	if (nRight < nLeft)
	{
		que.push_back('}');
		_inner_print(que, nPairs, nLeft, nRight+1);
		que.pop_back();
	}
}

void PrintBrackets(int nPairs)
{
	assert(nPairs > 0);
	deque<char> que;

	_inner_print(que, nPairs, 0, 0);
}

void test()
{
	PrintBrackets(5);
}