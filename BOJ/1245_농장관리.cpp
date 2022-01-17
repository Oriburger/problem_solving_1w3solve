#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0}; //
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, board[100][70], ans;
bool visited[100][70];

bool IsPeak(const int y, const int x) //(y, x) 영역이 봉우리인지 여부 반환
{
	bool ret = true; //기본 반환값은 T

	queue<P> q; 
	q.push({y, x});
	visited[y][x] = true;
	
	while(!q.empty()) //BFS 시작
	{
		const int cy = q.front().first;
		const int cx = q.front().second;
		q.pop();

		for(int d=0; d<8; d++) //인접 8방향 탐색
		{
			const int ny = cy + dy[d];
			const int nx = cx + dx[d];

			if(ny<0 || nx<0 || ny>=n || nx>=m) continue; //배열 범위 벗어나면 넘어가기
			if(board[cy][cx] < board[ny][nx]) ret = false; //만약 다른 영역이 더 높다면? ret는 false
			if(board[cy][cx] != board[ny][nx]) continue; //해당 영역만 탐색한다
			if(visited[ny][nx]) continue; //중복 방문 방지

			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];

	for(int i=0; i<n; i++) //배열의 모든 영역을 탐색한다.
		for(int j=0; j<m; j++)
			if(!visited[i][j]) ans += IsPeak(i, j);

	cout<<ans<<'\n';

	return 0;
}
