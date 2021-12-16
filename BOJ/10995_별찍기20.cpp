#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	cin>>n;

	for(int i=1; i<=n; i++)
	{	
		if(i%2==0) cout<<' ';
		for(int j=1; j<=2*n-1; j++)
		{
			if(j%2==1) cout<<'*';
			else cout<<' ';
		}
		cout<<'\n';
	}

	return 0;
}
