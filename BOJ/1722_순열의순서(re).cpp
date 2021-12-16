#include <iostream>
using namespace std;

bool check[21];
int n, prob, arr[21], answer[21];
long long fac[21]={1}, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>prob;
	
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i;
	
	if(prob == 1)
	{
		cin>>k;
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(check[j]) continue;
				
				if(fac[n-i] < k)
					k-=fac[n-i];
				
				else
				{
					check[j]=true;
					answer[i]=j;
					break; 
				}
			}
		}
		
		for(int i=1; i<=n; i++)
			cout<<answer[i]<<' ';
		cout<<'\n';
	}

	else
	{
		for(int i=1; i<=n; i++)
			cin>>arr[i];
		
		for(int i=1; i<n; i++)
		{
			for(int j=1; j<arr[i]; j++)
			{
				if(check[j]) continue;
				
				k += fac[n-i];
			}
			check[arr[i]] = true;
		}
		
		cout<<k+1<<'\n';
	}
	
	
	return 0;	
}
