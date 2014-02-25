//Given an array a[n], build another array b[n], b[i] = a[0]*a[1]*...*a[n-1]/a[i]
//no division can be used, O(n) time complexity

//Solution:
//Make two arrays c1[n] and c2[n], c1[i] = a[0]*..*a[i]   c2[i] = a[n-1]*..*a[i]
//For b[i] = c1[i-1]*c2[i+1]

void BuildB(int a[], int b[], int n)
{
	assert(a);
	assert(b);
	assert(n>0);

	int* c1 = new int[n];
	int* c2 = new int[n];

	c1[0] = c2[0] = 1;
	for (int i = 1; i < n; i++)
		c1[i] = c1[i-1]*a[i-1];
	for (int i = 1; i < n; i++)
		c2[i] = c2[i-1]*a[n-i];

	for (int i = 0; i < n; i++)
		b[i] = c1[i]*c2[n-i-1];

	delete []c1;
	delete []c2;
}

void test()
{
	int a[3] = {1,2,3};
	int b[3];
	BuildB(a, b, 3);
	for (int i = 0; i < sizeof(b)/sizeof(int); i++)
	{
		cout<<b[i]<<endl;
	}
}