#include <iostream>
using namespace std;

bool check[10001];

int D(int n)
{
	int sum=n;
	
	while(n!=0)
	{
		sum = sum + n%10;
		n=n/10;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=1; i<=10000; i++)
	{
		int next = D(i);
		if(next<=10000)
			check[next]=true;
	}
	
	for(int i=1; i<=10000; i++)
		if(!check[i])
			cout<<i<<'\n';
	
	return 0;
}
