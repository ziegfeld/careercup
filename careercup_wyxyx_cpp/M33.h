//How will you implement multiplication and division without using "*" or "/" operator?

unsigned int Multiply(unsigned a, unsigned b)
{
	int c = 0;
	while (b != 0)
	{
		if (b & 1 != 0)
			c += a;
		b = b >> 1;
		a = a << 1;
	}

	return c;
}

void test()
{
	cout<<Multiply(2,15)<<endl;
}