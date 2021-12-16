#include <iostream>
using namespace std;

int n, m;
int preSum[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int a; cin>>a;
			preSum[i+1][j+1] = preSum[i+1][j] + preSum[i][j+1]
							 - preSum[i][j] + a;
		}
	}

	for(int i=0; i<m; i++)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		cout<<preSum[c][d]-preSum[c][b-1]
				-preSum[a-1][d]+preSum[a-1][b-1]<<'\n';
	}

	return 0;
}
