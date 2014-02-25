//how to implement a queue using one integer. this should store value 0 to 9. 
//example suppose queue has first value 2 then insert 4 then 6 so it should look like 246. 
//first value should be popped as 2. then it should be 46. program should support 0 in all the levels also. 
//example queue should handle like 01235 also, 
//0 as first value in queue. remember 0 just to use integer, nothing else as data storage.

//Solution:
//An integer is composed by 32 bits and if use 4 bits to represent a number, the total capacity of the queue
//can be 8 numbers. However, 1111 can be used to represent "empty" and "0000" (15 decimal) can be used to represent number 0

class CIntQueue
{
public:
	CIntQueue() { m_nQue = 0xFFFFFFFF; }
	int GetFront();
	bool PutBack(int x);
	void PopFront();
	bool IsFull();

private:
	int getFrontPos();
	int m_nQue;
};

const int POS_MASK[8] = {0xF0000000, 0x0F000000, 0x00F00000, 0x000F0000, 
						 0x0000F000, 0x00000F00, 0x000000F0, 0x0000000F};

inline int CIntQueue::getFrontPos()
{
	int nIter = 7;
	while (nIter >= 0 && (((m_nQue & POS_MASK[nIter])>>(4*(7-nIter))) == 15))
		nIter--;
	return nIter;
}

inline int CIntQueue::GetFront()
{
	int nPos = getFrontPos();
	if (nPos == -1)
		return -1;

	return (m_nQue & POS_MASK[nPos])>>(4*(7-nPos));
}

inline bool CIntQueue::PutBack(int x)
{
	assert(x >= 0 && x <= 9);
	if (IsFull()) return false;
	
	m_nQue = m_nQue >> 4;
	m_nQue = m_nQue | 0xF0000000;
	m_nQue = m_nQue & ((x << 28) | 0x0FFFFFFF);
}

inline void CIntQueue::PopFront()
{
	int nPos = getFrontPos();
	if (nPos == -1)
		return;

	m_nQue = m_nQue ^ (m_nQue & POS_MASK[nPos]) | POS_MASK[nPos];
}

inline bool CIntQueue::IsFull()
{
	return getFrontPos() == 7;
}

void test()
{
	CIntQueue que;
	que.PutBack(1);
	que.PutBack(2);
	que.PutBack(3);
	que.PutBack(4);
	que.PutBack(0);

	cout<<que.GetFront()<<endl;
	que.PopFront();
	cout<<que.GetFront()<<endl;
	que.PopFront();
	que.PutBack(9);
	que.PutBack(0);
	cout<<que.GetFront()<<endl;
	que.PopFront();
	cout<<que.GetFront()<<endl;
	que.PopFront();
	cout<<que.GetFront()<<endl;
	que.PopFront();
	cout<<que.GetFront()<<endl;
	que.PopFront();
	cout<<que.GetFront()<<endl;
	que.PopFront();
}