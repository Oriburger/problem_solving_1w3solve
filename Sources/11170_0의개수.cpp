#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m;

	cin>>t;

	while(t--)
	{
		int answer=0;

		cin>>n>>m;
		for(int i=n; i<=m; i++)
		{
			int temp = i, cnt=0;
			
			if(temp==0) cnt=1;
			else
			{
				while(1)
				{
					if(temp==0) break;
					if(temp%10==0) cnt++;
					temp/=10;
				}
			}
			
			answer+=cnt;
		}
		cout<<answer<<'\n';
	}

	return 0;
}
