//Given a function that returns a random number between 1 and 5, make it return a number between 1 to 7

//Solution:
//So you can transform this generator to a 0~1 generator, generate 0~1 three times you get a bit sequence
//from 0~7, just ignore 0 and try again

int rand1To5Generator()
{
	int rnd = rand();
	return rnd%5+1;
}

int BitGenerator()
{
	while (true)
	{
		int n = rand1To5Generator();
		if (n == 5) continue;

		if (n == 1 || n == 2) return 1;
		if (n == 3 || n == 4) return 0;

		throw "What the fuck?? \n";
	}

	throw "What the fuck?? \n";
	return 0; // never reach here
}

int rand1To7Generator()
{
	int nRet = 0;
	do 
	{
		int bit1 = BitGenerator();
		int bit2 = BitGenerator();
		int bit3 = BitGenerator();

		nRet = bit1;
		nRet += bit2 << 1;
		nRet += bit3 << 2;

		if (nRet == 0) continue;
		break;
	} 
	while (true);

	return nRet;
}

void test()
{

	srand(unsigned int(time(0)));
	int a[7] = {0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 7000; i++)
	{
		a[rand1To7Generator()-1]++;
	}

	for (int i = 0; i < 7; i++)
		cout<<i+1<<" : "<<a[i]<<" times"<<endl;
}