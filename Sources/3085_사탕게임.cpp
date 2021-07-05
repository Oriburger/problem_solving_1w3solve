#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, ans=0;
vector<vector<char> > board(51, vector<char>(51, ' '));

int GetAnswer(vector<int> pos)
{
	int ret = 0;

	for(int i=0; i<4; i++)
	{
		char cur_id[2]={' ', ' '}; //col, row
		int cur_cnt[2]={0, 0}; //col, row
		for(int j=0; j<n; j++)
		{
			for(int dir=0; dir<2; dir++)
			{
				const char curr = (!dir ? board[pos[i]][j]
										 : board[j][pos[i]]);
				if(cur_id[dir] != curr)
				{
					cur_id[dir] = curr;
					cur_cnt[dir] = 1;
				}
				else cur_cnt[dir]++;
			}

			ret = max(ret, max(cur_cnt[0], cur_cnt[1]));
		}
	}

	return ret;
}

int main()
{
	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			for(int i=0; i<4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if(board[ny][nx]==board[y][x]) continue;

				swap(board[y][x], board[ny][nx]);
				
				ans = max(ans, GetAnswer({y, x, ny, nx}));

				swap(board[y][x], board[ny][nx]);
			}

	cout<<ans<<'\n';

	return 0;
}
