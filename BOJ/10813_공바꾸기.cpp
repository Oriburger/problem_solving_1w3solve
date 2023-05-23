#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[101];

int main()
{
	cin>>n>>m;

	for(int i=1; i<=n; i++) arr[i] = i; 
	for(int i=0; i<m; i++)
	{
		int a, b; cin>>a>>b;
		swap(arr[a], arr[b]);
	}
	for(int i=1; i<=n; i++) cout<<arr[i]<<' ';

	return 0;
}
