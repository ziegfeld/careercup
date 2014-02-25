//Q: Give two parking locations P1 and P2, P1 and P2 both have n slots. n-1 cars with same IDs are parked in n-1 
//slots in both P1 and P2. Design an algorithm to let n-1 cars in P1 and P2 park in the same slots

//A: The man who propose the question should improve his/her English definitely. What the fuck!!! It took me half an hour
//to read this question. So the question may be there are n parking lots with their id ranging from 1 to n. So there are
//n-1 cars with there id corresponding the parking slot but in random order, we need to put drive the cars to right position.
//So, here is the answer, the empty slot implies the temporary variable we used to swap two numbers. We start from the beginning,
//if the car in first slot with id 3, we drive the car in the third slot to the empty slot and drive the car originally in
//the first slot to third slot, then we deal the same thing with the car which is swapped out in the empty slot until no swapping
// is needed, for example, the car in the second slot with id 4 and the car in the 4th slot with id 2. 
//So, the first round of swapping begins from the car in the first slot which incurs a serials of swapping.
//Then we start swapping from second sot, if the right car is in the right slot, we go for the third slot, and so on.
//Time complexity is O(n), and space O(1)

void DisplayParkingProblem(int n)
{
	assert(n>2);
	int* pSlot = new int[n];
	for (int i = 0; i < n; i++)
		pSlot[i] = i;

	srand(unsigned int(time(0)));
	for (int i = n; i > 0; i--)
	{
		int r = rand()%i;
		int nTmp = pSlot[i-1];
		pSlot[i-1] = pSlot[r];
		pSlot[r] = nTmp;
	}

	int nEmpty = rand()%n;
	pSlot[nEmpty] = -1;
	for (int i = 0; i < n; i++)
		cout<<pSlot[i]<<" ";
	cout<<endl;

	for (int i = 0; i < n; i++)
	{
		if (pSlot[i] == i || i == nEmpty)
			continue;

		int nIter = i;
		while (pSlot[nIter] != nIter)
		{
			if (pSlot[nIter] == nEmpty)
			{
				pSlot[nEmpty] = pSlot[nIter];
				nEmpty = nIter;
				break;
			}

			pSlot[nEmpty] = pSlot[pSlot[nIter]];
			pSlot[pSlot[nIter]] = pSlot[nIter];
			int nNewEmpty = nIter;
			nIter = nEmpty;
			nEmpty = nNewEmpty;
		}
	}

	pSlot[nEmpty] = -1;
	for (int i = 0; i < n; i++)
		cout<<pSlot[i]<<" ";
	cout<<endl;

	delete []pSlot;
}

void test()
{
	DisplayParkingProblem(10);
}