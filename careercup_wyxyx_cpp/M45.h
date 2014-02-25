//There is long list of natural numbers.
//Remove every 2nd no from list in 1st pass
//Remove every 3rd no from list in 2nd pass
//Now find whether nth natural no will exist after p passes. n and p are inputs

//Solution:
//We can judge whether the number exist or not by judging whether it is eliminate from 
//the list at each pass. After each pass, we can get the new order of this number. The
//formula is : f(n) = (f(n-1)/time)*(time-1) + f(n-1)%time

bool IsExisted(int nPass, int num)
{
	assert(nPass>0);
	assert(num>0);

	int nOrder = num;
	int nCur = 2;
	while (nCur <= nPass+1)
	{
		int nDiv = nOrder/nCur;
		if (nDiv == 0) return true;

		int nReminder = nOrder%nCur;
		if (nReminder == 0) return false;

		nOrder = nDiv*(nCur-1)+nReminder;
		nCur++;
	}

	return true;
}

void test()
{
	cout<<IsExisted(5, 111)<<endl;
}