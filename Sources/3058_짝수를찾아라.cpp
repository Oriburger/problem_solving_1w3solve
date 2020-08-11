#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	while(t--)
	{
		int sum=0, minVal=2147000000;
		for(int i=0; i<7; i++)
		{
			int n; cin>>n;
			if(n%2==0)
			{
				sum+=n;
				minVal=min(n, minVal);
			}
		}
		
		cout<<sum<<" "<<minVal<<"\n";
	}
	
	return 0;
}
