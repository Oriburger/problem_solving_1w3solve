#include <bits/stdc++.h>
using namespace std;

struct Pos { int y; int x; };
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int h, w, total, ans, cnt;
int board[101][101];
bool visited[101][101];
queue<Pos> q1, q2;

void BFS(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	q1.push({y, x});
	visited[y][x] = true;
	
	while(!q1.empty())
	{
		Pos curr = q1.front();
		q1.pop();
		
		for(int i=0; i<4; i++)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];
			
			if(ny<0 || nx<0 || ny>=h || nx>=w) continue; 
			if(visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			if(board[ny][nx]==1) q2.push({ny, nx});
			else q1.push({ny, nx});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>h>>w;
	
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			cin>>board[i][j];
			total += board[i][j];
		}
	
	while(1)
	{
		BFS(0, 0);
		if(q2.size() == 0) break;
		cnt = q2.size();
		ans += 1;
				
		while(!q2.empty())
		{
			Pos curr = q2.front();
			q2.pop(); 
			board[curr.y][curr.x] = 0;
		}
	}
	cout<<ans<<'\n'<<cnt<<'\n';
	
	return 0;
}
