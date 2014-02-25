//There is an array of odd and even numbers. Now, sort them in such a way that the top portion of 
//the array contains odd numbers, bottom portion contains even numbers. The odd numbers are to be sorted 
//in descending order and the even numbers in ascending order. You are not allowed to use any extra array 
//and it has to use a conventional sorting mechanism and should not do any pre or post processing.

//Solution:
//Code below shows every thing

class CLess
{
public:
	bool operator() (int a, int b)
	{
		if(a%2 == 0 && b%2 == 1)
			return false;

		if(a%2 == 1 && b%2 == 0)
			return true;

		if (a%2 == 0 && b%2 == 0)
			return a>b;

		return a<b;
	}
};

void EOSort(int a[], int n)
{
	sort(a, a+n, CLess());
}

void test()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,12,14,13,16};
	EOSort(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout<<a[i]<<endl;
}