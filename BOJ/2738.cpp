#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100];
int b[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			int tmp; cin>>tmp;
			a[i][j] += tmp;
		}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
