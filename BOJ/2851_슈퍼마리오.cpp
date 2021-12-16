#include <iostream>
#include <cstdlib>
using namespace std;

int mushroom[10];
int ans=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<10; i++)
		cin>>mushroom[i];
	
	for(int i=0; i<10; i++)
	{
		int sum=0;
		for(int j=0; j<=i; j++)
			sum+=mushroom[j];
			
		if(abs(100-sum) < abs(100-ans)) ans=sum;
		else if(abs(100-sum) == abs(100-ans))
			ans = max(ans, sum);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
