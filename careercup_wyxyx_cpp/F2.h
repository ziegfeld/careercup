//Write a program to evaluate a simple mathematical expression like 4 + 2*a/b - 3

//Solution:
//A typical syntax parser problem, I think use the recursive decent down method solution is the most easy one

// Recursive decent down method (below is the syntax rules)
// f=e+f|e-f|e 
// e=n*e|n/e|n (n here stands for number, negtive number not surpport)

#define MUL  -1
#define DIV  -2
#define ADD  -3
#define SUB  -4
#define END  -5

int GetTokern(const char*& p)
{
	while (*p == ' ')
		p++;

	if (*p == '\0') 
		return END;

	if ('+' == *p)
	{
		p++;
		return ADD;
	}

	if ('-' == *p) 
	{
		p++;
		return SUB;
	}

	if ('*' == *p) 
	{
		p++;
		return MUL;
	}

	if ('/' == *p)
	{
		p++;
		return DIV;
	}

	if (*p < '0' || *p > '9')
		throw "Invalid character \n";

	int ret = atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;

	return ret;
}

float MulDiv(const char*& p);
float AddSub(const char*& p)
{
	float ret = MulDiv(p);
	int tok = GetTokern(p);

	const char* pOrg = p;
	if (tok == ADD)
		return ret+AddSub(p);

	if (tok == SUB)
		return ret-AddSub(p);

	if (tok == END)
		return ret;

	p = pOrg;
	return 0.0;
}

float MulDiv(const char*& p)
{
	int num = GetTokern(p);
	if (num < 0)
		throw "Get number error at MulDiv \n";
	
	const char* pOrg = p;
	int tok = GetTokern(p);
	if (tok == END)
		return num;

	if (tok == MUL)
		return num*MulDiv(p);

	if (tok == DIV)
		return num/MulDiv(p);

	p = pOrg;
	return num;
}

void test()
{
	float res = 0.0;
	try
	{
		char* str = " 1  +2*3/5-4";
		const char* p = str;
		res = AddSub(p);
		cout<<res<<endl;
	}
	catch(char* p)
	{
		cout<<p<<endl;
	}
}