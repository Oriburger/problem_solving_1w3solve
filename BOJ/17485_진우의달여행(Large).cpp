#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
const int dx[3] = {-1, 0, 1};
int n, m, ans=INF, board[1001][1001];
int cache[1001][1001][3];

int Solve(int y, int x, int last)
{
	int &ret = cache[y][x][last];
	if(ret!=-1) return ret;
	if(y==n) return 0;

	ret = INF;
	for(int i=0; i<3; i++)
	{
		if(last==i) continue;
		if(x+dx[i]<0 || x+dx[i]>=m) continue;

		ret = min(ret, Solve(y+1, x+dx[i], i) + board[y][x]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];

	for(int i=0; i<m; i++)
		for(int j=0; j<3; j++)
			ans = min(ans, Solve(0, i, j));

	cout<<ans<<'\n';

	return 0;	
}
