//Transform an infix expression to a postfix expression

//Solution:
//Use two stacks to make this in one iteration of the incoming string.
//One stack store operant says A, other one store operator says B.
//When performing the parsing, we put operant in A, when an operator
//is met, we check whether the operator got higher priority than last
//operator(the operator at the top of the stack), if it is, we again
//push the operants and the operator, if less or equal, we generate a 
//segment of postfix expression by popping all the operator in stack B and
//push the result into stack A. Left brace is a kind of operator with the 
//highest priority, when a right operator is met, we calculate the postfix
//expression until a left brace is met. The program should detect the false syntax.
//Every operant here is a char other than specific operator.
//Supported operator + - * / ( )

//Braces and syntax error checking make the code much more tedious here!!!!!!!!
#include <string>
using namespace std;

bool PriorityHigher(const char c1, const char c2)
{
	int nLevel1 = 1;
	int nLevel2 = 1;

	if (c1 == '+' || c1 == '-')
		nLevel1 = 1;
	else if (c1 == '*' || c1 == '/')
		nLevel1 = 2;
	else if (c1 == '(')
		nLevel1 = 4;
	else
		throw "Unknown operator in PriorityHigher";

	if (c2 == '+' || c2 == '-')
		nLevel2 = 1;
	else if (c2 == '*' || c2 == '/')
		nLevel2 = 2;
	else if (c2 == '(')
		nLevel2 = 3;
	else
		throw "Unknown operator in PriorityHigher";

	return nLevel1 > nLevel2;
}

bool CalcCurrentPostFix(stack<string>& stkOprnt, stack<char>& stkOprtor, bool bRgtBrace, bool bFinalChk, string& strError)
{
	bool bLftBraceFound = false;
	while (!stkOprtor.empty())
	{
		char cOp = stkOprtor.top();

		if ('(' != cOp || bRgtBrace)
			stkOprtor.pop();

		if ('(' == cOp)
		{
			bLftBraceFound = true;
			if (bFinalChk)
			{
				strError = "Braces miss match";
				return false;
			}

			break;
		}

		if (stkOprnt.size() < 2)
		{
			strError = "Syntax error, operant miss match";
			return false;
		}

		// Push postfix segment
		string strRgtOprnt = stkOprnt.top();
		stkOprnt.pop();
		string strLftOprnt = stkOprnt.top();
		stkOprnt.pop();
		string strOprt;
		strOprt.assign(1, cOp);
		string strNewPostfix = strLftOprnt + strRgtOprnt + strOprt;
		stkOprnt.push(strNewPostfix);
	}

	if (bRgtBrace && !bLftBraceFound)
	{
		strError = "Braces miss match";
		return false;
	}

	return true;
}

string MakePostFix(const char* szInfix)
{
	stack<string> stkOperant;
	stack<char> stkOperator;

	const char* pIter = szInfix;
	string strError;
	while ('\0' != *pIter)
	{
		char c = *pIter;
		if ('+' == c || '-' == c || '*' == c || '/' == c || '(' == c)
		{
			if (!stkOperator.empty() && !PriorityHigher(c, stkOperator.top()))
			{
				if (!CalcCurrentPostFix(stkOperant, stkOperator, false, false, strError))
					return strError;
			}

			stkOperator.push(c);
		}else if (')' == c)
		{
			if (!CalcCurrentPostFix(stkOperant, stkOperator, true, false, strError))
				return strError;
		}
		else if (' ' != c && '\n' != c)
		{
			string strOprnt;
			strOprnt.assign(1, c);
			stkOperant.push(strOprnt);
		}

		pIter++;
	}

	if (!CalcCurrentPostFix(stkOperant, stkOperator, false, true, strError))
		return strError;
	
	if (stkOperant.size() > 1)
		return "Syntax error";

	if (!stkOperant.empty())
		return stkOperant.top();
	else 
		return string("");
}

void test()
{
	try
	{
		string strRes = MakePostFix("(c*(a+b))*d/(x-y)");
		cout<<strRes<<endl;
	}
	catch (const char* szError)
	{
		cout<<szError<<endl;
	}
}