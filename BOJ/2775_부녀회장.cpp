#include <iostream>
using namespace std;

int t, k, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;

	while(t--)
	{
		int arr[15][15]={{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}, 0};
		
		cin>>k>>n;

		for(int i=1; i<=k; i++)
		{
			for(int j=1; j<=n; j++)
			{
				int sum=0;
				for(int k=1; k<=j; k++)
					sum += arr[i-1][k];
				arr[i][j] = sum;
			}
		}

		cout<<arr[k][n]<<'\n';
	}

	return 0;
}
