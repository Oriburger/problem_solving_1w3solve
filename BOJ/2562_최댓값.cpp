#include <iostream>
using namespace std;

int main()
{
	int n, ans=-1, ansIdx=0;
	
	for(int i=1; i<=9; i++)
	{
		cin>>n;
		
		if(ans<n)
		{
			ans=n;
			ansIdx=i;
		}
	}
	cout<<ans<<'\n'<<ansIdx<<'\n';
	
	return 0;
}
