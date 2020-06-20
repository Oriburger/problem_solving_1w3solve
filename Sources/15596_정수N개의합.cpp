#include <iostream>
using namespace std;

long long sum(int *a, int n)
{
	long long ret=0;
	for(int i=0; i<n; i++)
		ret += a[i];
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, arr[3000001];
	
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	cout<<sum(arr, n)<<'\n';
		
	return 0;
}
