#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct Pos { int y; int x; };

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int h, w;
char board[100][100];
vector<Pos> exitArr, prisoner;

int BFS(Pos start)
{
	queue<pair<Pos, int> > q;
	bool visied[100][100]={false};
	int ret=0;
	
	q.push({start, 0});
	visited[start.y][start.x]=true;	
	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int ny = curr.first.y + dy[i];
			int nx = curr.first.x + dx[i];
			
			if(ny<0 || nx<0 || ny>=h || nx>=w) continue;
			if(visited[ny][nx]) continue;
			if(board[ny][nx]=='*') continue;
			
			visited[ny][nx] = true;
			if(board[ny][nx]=='$')
				q.push({{ny, nx}, curr.second+1});
			else
				q.push({{ny, nx}, curr.second});
		}
	}
	
	prisoner[i].y
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;
	
	while(t--)
	{
		int answer=2147000000;

		cin>>h>>w;
		
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				cin>>board[i][j];
				if(board[i][j]=='#' || board[i][j]=='.')
					if(i==0 || j==0 || i==h-1 || j==w-1)
						exitArr.push_back({i, j});
				if(board[i][j]=='$')
					prisoner.push_back({i, j});
			}
		}
		
		for(int i=0; i<exitArr.size(); i++)
		{
			answer = min(answer, BFS(exitArr[i]););
		}
		
		prisoner.clear();
		exitArr.clear();
	}
	
	return 0;
}	
