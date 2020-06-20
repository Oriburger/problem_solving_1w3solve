#include <iostream>
using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];
int answer=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	dp1[0]=1;
	dp2[n-1]=1;
	for(int i=1; i<n; i++)
	{
		dp1[i]=1;
		dp2[n-i-1]=1;
		for(int j=0; j<i; j++)
		{
			if(arr[i]>arr[j] && dp1[i] < dp1[j]+1)
				dp1[i]++;
			if(arr[n-i-1] > arr[n-j-1] && dp2[n-i-1] < dp2[n-j-1]+1)
				dp2[n-i-1]++;
		}
	} 
	
	for(int i=0; i<n; i++)
	{
		answer = max(dp1[i]+dp2[i]-1, answer);
	}
	cout<<answer<<'\n';
	
	return 0;
}
