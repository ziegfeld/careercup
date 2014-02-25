//Write a routine to draw a circle (x ** 2 + y ** 2 = r ** 2) without making use of any floating point computations

//Solution:
//Many people said this shitty question is not prompt by M$ interviewer. Some proposed a mid point circle drawing
//algorithm which I believe is not the prospected answer because its too professional. Below is my solution, I use 
//a two dimensional array to represent the smallest rectangle that covers the circle. For each elements within the array
//to see whether its in the circle or not, in is true, outside is false. Then traverse this array line by line, for each element,
//if it's true print a star ,if it's false print a blank. The stars printed on the screen will form a circle

void PrintCircle(int r)
{
	assert(r>0);

	int nDim = 2*r+1;

	//Center is pRect[r][r]
	for (int i = 0; i < nDim; i++)
	{
		for (int j = 0; j < nDim; j++)
		{
			int nDx = i-r;
			int nDy = j-r;
			if (nDx*nDx + nDy*nDy <= r*r)
				cout<<"*";
			else
				cout<<" ";
			cout<<" ";
		}

		cout<<endl;
	}
}

void test()
{
	PrintCircle(10);
}