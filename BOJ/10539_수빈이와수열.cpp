#include <iostream>
#include <vector>
using namespace std;

int n;
int a[100];
int b[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
		cin>>b[i];
	
	for(int i=0; i<n; i++)
	{
		a[i] = i==0 ? b[i]*(i+1) : b[i]*(i+1) - b[i-1] * (i);
	}
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<' ';
	
	return 0;
} 
