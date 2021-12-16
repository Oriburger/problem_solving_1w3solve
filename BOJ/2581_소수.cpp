#include <iostream>
#include <vector>
using namespace std;

int arr[10001];

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int m, n;
	int minVal=999999, sum=0;
	
	cin>>m>>n;
	
	arr[1]=0;
	for(int i=2; i<=n; i++)
		for(int j=i; j<=n; j+=i)
			arr[j]++;
	
	for(int i=m; i<=n; i++)
	{
		if(arr[i]==1)
		{
			minVal = min(minVal, i);
			sum+=i;
		}
	} 
	
	if(minVal == 999999)
		cout<<-1<<'\n';
	else
	{
		cout<<sum<<'\n';
		cout<<minVal<<'\n';
	}

	return 0;
}	
