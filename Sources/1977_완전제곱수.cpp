#include <iostream>
using namespace std;

int m, n, minVal=99999, sum=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>m>>n;

	for(int i=1; i*i<=n; i++)
	{
		if(i*i>=m)
		{
			minVal = min(minVal, i*i);
			sum+=i*i;
		}
	}

	if(sum==0) cout<<-1<<'\n';
	else cout<<sum<<'\n'<<minVal<<'\n';

	return 0;
}
