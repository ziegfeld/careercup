//You need to organize a football tournament. There are n teams given. 
//You need to prepare a schedule for the matches so that each team plays with every 
//other team and on the same day no team plays twice. You want to finish the tournament as early as possible.

//Solution:
//Think about a n*n two dimensional square, the index of each element represent a single match.
//For example, a[0][1] stands for 1 vs 0. So, the question is to find a way to fill the triangle
//divided by the diagnal of the square, the triangle does not contain the diagnal because a team 
//can not match with itself. So, in the first day, fill the longest slide edge of the right triangle,
//the second day the second longest, untill all elements in the triangle is filled.

void PrintMatch(int n)
{
	assert(n>1);
	for (int j = 1; j < n; j++)
	{
		cout<<"Day "<<j<<" :"<<endl;
		for (int i = 0; i < n-1 && i+j < n; i++)
			cout<<"("<<i+1<<" vs "<<i+j+1<<") ";
		cout<<endl;
	}
}

void test()
{
	PrintMatch(6);
}