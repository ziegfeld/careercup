//shuffle an array of size n such that each element has 1/n probability 
//to remain in its original spot. The best solution has O(n) complexity.

//Solution:
//Randomly choose a number and swap it with the last number
//Randomly choose a number for the rest numbers (n-1) and swap it with the second last number
//Do this untill only one number is left

// prove that probability of each number staying in the original position is one nth
// the probability for the last number to stay in original position is 1/n
// the probability for the second last number to stay in original position is (n-1/n)*(1/n-1) so on....

//Back ground knowledge:
//In a computer, shuffling is equivalent to generating a random permutation of the cards. 
//There are two basic algorithms for doing this, both popularized by Donald Knuth. 
//The first is simply to assign a random number to each card, and then to sort the cards in order of their random numbers. 
//This will generate a random permutation, unless two of the random numbers generated are the same. 
//This can be eliminated either by retrying these cases, 
//or reduced to an arbitrarily low probability by choosing a sufficiently wide range of random number choices.
//The second, generally known as the Knuth shuffle or Fisher-Yates shuffle, 
//is a linear-time algorithm (as opposed to the previous O(n log n) algorithm if using 
//efficient sorting such as mergesort or heapsort) 
//which involves moving through the pack from top to bottom, 
//swapping each card in turn with another card from a random position in 
//the part of the pack that has not yet been passed through (including itself). 
//Providing that the random numbers are unbiased, this will always generate a random permutation.

#include <stdlib.h>
void RandomShuffle(int a[], int n)
{
	srand(unsigned int(time(0)));
	for (int i = n-1; i >= 0; i--)
	{
		// Get random index
		int rnd = rand();
		int index = rnd%(i+1);
		// swap to last one
		int nTmp = a[index];
		a[index] = a[i];
		a[i] = nTmp;
	}
}

void test()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	RandomShuffle(a, sizeof(a)/sizeof(int));
	for (int i = 0; i , i < sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<endl;
	}
}