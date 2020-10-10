#include <iostream>
using namespace std;

const int MAX_N = 100001;
int n, s, arr[MAX_N];
int ans=MAX_N, st=0, fin=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>s;

	for(int i=0; i<n; i++)
		cin>>arr[i];

	int sum=arr[st];
	while(st<n)
	{
		if(sum>=s)
		{
			ans=min(ans, fin-st+1);
			cout<<"["<<st<<", "<<fin<<"]\n";
		}

		if(sum>=s || fin==n-1)
		{
			sum-=arr[st];
			st++;
		}
		else 
		{
			fin++;
			sum+=arr[fin];
		}
	}

	cout<<(ans == MAX_N ? 0 : ans)<<'\n';

	return 0;
}
