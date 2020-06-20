#include <iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=2*n-1; i++)
	{
		if(i<=n)
		for(int j=1; j<=i; j++)
			cout<<'*';
		
		else if(i>n)
		for(int i=n-1; i>1; i--)
			cout<<'*';
		
		cout<<'\n';
	}
	
	return 0;
}
