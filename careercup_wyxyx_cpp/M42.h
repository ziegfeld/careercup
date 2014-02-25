//Reverse an integer array bitwise algorithm? code? Test cases?


void ReverseArrBit(int a[], int n)
{
	int j = n-1;
	for (int i = 0; i < j; i++,j--)
	{
		a[i] = a[i]^a[j];
		a[j] = a[i]^a[j];
		a[i] = a[i]^a[j];
	}
}

void test()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	ReverseArrBit(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}