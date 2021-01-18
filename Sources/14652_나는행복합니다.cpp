#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k, cnt=0;

	cin>>n>>m>>k;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(cnt==k)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			cnt++;
		}
	}
	
	return 0;
}
