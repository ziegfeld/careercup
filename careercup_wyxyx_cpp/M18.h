//Convert an integer to a string

//Solution:
//This problem can be solved by recursion
//Write a function with an integer parameter.
//Call this function recursively within itself with the parameter passed divided by ten
//until the parameter is less than 10.
//So, when the recursion is recursing back, the function get the reminder of the parameter divided by ten
//, translate this integer to a character and write it down. Every time a character is wrote, move to the next byte. 
//So, the recursion itself write the characters of the number one by one until the integer is translated to a string.

char* _inner_to_string(int nPositive, char* p);
char* ToString(int n, char str[])
{
	char* p = str;
	if (n < 0) 
	{
		*p++ = '-';
		n = -n;
	}

	p = _inner_to_string(n, p);
	*p = '\0';
	
	return str;
}

char* _inner_to_string(int nPositive, char* p)
{
	assert(nPositive>=0);
	if (nPositive/10 != 0)
		p = _inner_to_string(nPositive/10, p);

	*p++ = '0' + (nPositive)%10;
	return p;
}

void test()
{
	char str[100];
	cout<<ToString(-1234, str)<<endl;
}