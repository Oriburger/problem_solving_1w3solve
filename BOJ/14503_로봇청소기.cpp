#include <iostream>
#include <vector>
#include <algorithm>
#define LEFT 3
using namespace std;

struct Pos { int y; int x; };

const int dy[4] = {-1, 0, 1, 0}; //up, right, down, left
const int dx[4] = {0, 1, 0, -1};

int n, m, dir, cnt=0, ans=0; 
int board[51][51];
bool visited[51][51];
Pos st, curr, l, r, b, f;

bool IsInBoard(Pos p)
{
	if(p.y < 0 || p.x < 0 || p.y >= n || p.x >= m) 
		return false;
	return true;
}

bool IsWall(Pos p)
{
	if(board[p.y][p.x]) return true;
	return false;
}

bool CanClean(Pos p)
{
	if(!IsInBoard(p) || IsWall(p) || visited[p.y][p.x]) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>st.y>>st.x>>dir;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];

	curr = st;
	while(1)
	{
		if(!visited[curr.y][curr.x])
		{
			visited[curr.y][curr.x]=true;
			ans++;
		}

		b = {curr.y+dy[(dir+2)%4], curr.x+dx[(dir+2)%4]};
		l = {curr.y+dy[(dir+3)%4], curr.x+dx[(dir+3)%4]};

		if(cnt==4)
		{
			if(IsWall(b) || !IsInBoard(b))	break;
			curr = b; cnt=0;
			continue;
		}
		if(CanClean(l))
		{
			curr = l; cnt = 0;
			dir = (dir+LEFT)%4;
		}
		else
		{
			cnt++;
			dir = (dir+LEFT)%4;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
