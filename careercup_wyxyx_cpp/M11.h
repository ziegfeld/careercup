//Implement a queue using a Stack? i know its possible with 2 stacks .. 
//but the guy told me to use only a single stack..
//Solution
//Use recursion as another stack

bool PopBack(stack<int>& stk, int& ret)
{
	if (stk.empty())
		return false;

	int nTop = stk.top();
	stk.pop();
	if (stk.empty())
	{
		ret = nTop;
		return true;
	}
	else
	{
		bool bRet = PopBack(stk, ret);
		stk.push(nTop);
		return bRet;
	}
}