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

	//바뀐칸의 좌표들의 가로&세로를 탐색
	for(int i=0; i<4; i++)
	{
		char cur_id[2]={' ', ' '}; //col, row
		int cur_cnt[2]={0, 0}; //col, row

		for(int j=0; j<n; j++)
		{
			//dir 0 : 세로 방향 탐색, 1 : 가로 방향 탐색
			for(int dir=0; dir<2; dir++)
			{
				//현재 좌표 사탕의 색상 (dir에 따라 다름)
				const char curr = (!dir ? board[pos[i]][j]
										 : board[j][pos[i]]);

				//연속이 끊겼다면?
				if(cur_id[dir] != curr)
				{
					cur_id[dir] = curr; //색상을 갱신
					cur_cnt[dir] = 1; //개수도 갱신
				}
				//연속이라면
				else cur_cnt[dir]++; //개수를 추가
			}
			//정답 갱신
			ret = max(ret, max(cur_cnt[0], cur_cnt[1]));
		}
	}

	return ret;
}

int main()
{
	cin>>n;

	//입력
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	//모든 좌표당 인접한 4칸과 교환을 시도 
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			for(int i=0; i<4; i++) //4개의 방향
			{
				int ny = y + dy[i]; //바꿀 y좌표
				int nx = x + dx[i]; //바꿀 x좌표

				//범위에 벗어난다면? 바꾸지 않는다.
				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				//두 칸이 동일한 색상이라면? 바꾸지 않는다
				if(board[ny][nx]==board[y][x]) continue;

				//두 칸을 바꾸고,
				swap(board[y][x], board[ny][nx]);
				//정답을 갱신한다
				ans = max(ans, GetAnswer({y, x, ny, nx}));
				//그리고 원래대로 다시 바꾼다.
				swap(board[y][x], board[ny][nx]);
			}

	cout<<ans<<'\n';

	return 0;
}
