//Write the code for a change vending machine. 100, 50, 20, 10, 2, 1
//Solution:
//Greedy algorithm is proper here. we should find a way to provide the change with least coins
void ChangMoney(int nMoney)
{
	
		int nDiv = nMoney/100;
		if (nDiv > 0)
			cout<<nDiv<<" for "<<100<<endl;
		nMoney -= nDiv*100;

		nDiv = nMoney/50;
		if (nDiv > 0)
			cout<<nDiv<<" for "<<50<<endl;
		nMoney -= nDiv*50;

		nDiv = nMoney/20;
		if (nDiv > 0)
			cout<<nDiv<<" for "<<20<<endl;
		nMoney -= nDiv*20;

		nDiv = nMoney/10;
		if (nDiv > 0)
			cout<<nDiv<<" for "<<10<<endl;
		nMoney -= nDiv*10;

		nDiv = nMoney/2;
		if (nDiv > 0)
			cout<<nDiv<<" for "<<2<<endl;
		nMoney -= nDiv*2;

		if (nMoney > 0)
			cout<<1<<" for "<<1<<endl;

	cout<<endl;
}