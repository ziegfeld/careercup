//Write a program to find the square root of a given number.
//He wanted some kind of binary search.

//The trap here is binary search does not require actual numbers
//see the code below:

float GetSquareRoot(float f)
{
	assert(f >= 0.0);

	float fMin = 0.0;
	float fMax = f;
	float fTmp = (fMax + fMin)/2;

	int nCounts = 1000000;
	while (fTmp*fTmp - f > 0.00001 || fTmp*fTmp - f < -0.00001)
	{
		if (nCounts-- == 0) break;
		if (fTmp*fTmp > f)
		{
			fMax = fTmp;
			fTmp = (fMax + fMin)/2;
		}
		else
		{
			fMin = fTmp;
			fTmp = (fMax + fMin)/2;
		}
	}

	return fTmp;
}

void test()
{
	cout<<GetSquareRoot(38979824.26433524)<<endl;
}