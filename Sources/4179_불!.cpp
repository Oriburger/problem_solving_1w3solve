#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos { int y; int x; };

const int INF = 2147000000;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int r, c, answer=INF;
int playerMv[1001][1001], fireMv[1001][1001];
char board[1001][1001];
vector<Pos> fireStPos;
vector<Pos> exitPos;
Pos playerStPos;

void BFS(vector<Pos> start, const char obst)
{
	queue<Pos> q;
	for(Pos &p : start)
	{
		q.push(p);
		if(obst=='J')
			fireMv[p.y][p.x]=1;
		else if(obst=='F')
			playerMv[p.y][p.x]=1;
	}

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y+dy[i], curr.x+dx[i]};
			
			if(next.y<0 || next.y>=c || next.x<0 || next.x>=r)
				continue;
			if(board[next.y][next.x]=='#' 
				|| board[next.y][next.x]==obst)
				continue;

			//BFS의 대상이 F
			if(obst == 'J')
			{
				if(board[next.y][next.x]=='J')
					continue;
				if(fireMv[next.y][next.x] != 0)
					continue;
				else
					fireMv[next.y][next.x] = fireMv[curr.y][curr.x]+1;
				q.push(next);
			} 
				
			//BFS의 대상이 J
			if(obst == 'F') 
			{
				if(board[next.y][next.x]=='F')
					continue;
				if(playerMv[next.y][next.x] != 0)
					continue;
				else
					playerMv[next.y][next.x] = playerMv[curr.y][curr.x]+1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>r>>c;

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin>>board[i][j];
			if((i==0 || j==0 || i==c-1 || j==r-1
				) && (board[i][j]=='.' || board[i][j]=='J'))
				exitPos.push_back({i, j});
			if(board[i][j]=='J')
				playerStPos={i, j};
			else if(board[i][j]=='F')
				fireStPos.push_back({i, j});
		}
	}

	BFS({playerStPos}, 'F');
	BFS(fireStPos, 'J');

	for(const Pos &p : exitPos)
	{
		if(playerMv[p.y][p.x]==0) continue;
		else if(fireMv[p.y][p.x]==0 
			|| (fireMv[p.y][p.x] > playerMv[p.y][p.x]))
			answer = min(answer, playerMv[p.y][p.x]);
	}
	

	if(answer==INF)
		cout<<"IMPOSSIBLE\n";
	else cout<<answer<<'\n';

	return 0;
}
