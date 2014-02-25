//I was asked how to select M numbers from N existing numbers randomly and fairly (N>M). Example, 
//assume that there are 10 numbers, you need to select 3 numbers from them randomly.

//Solution:
//Refer to F3.h

#include <ctime>
#include <iostream>
using namespace std;

void RandomGet(int a[], int n, int m)
{
	if (m > n) return;

	srand(unsigned int(time(0)));
	for (int i = 0; i < m; i++)
	{
		int rnd = rand();
		int index = rnd%n;
		int tmp = a[i];
		a[i] = a[index];
		a[index] = tmp;
	}

	for (int i = 0; i < m; i++)
	{
		cout<<a[i]<<endl;
	}
}

void test()
{
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	RandomGet(a, sizeof(a)/sizeof(int), 3);
}