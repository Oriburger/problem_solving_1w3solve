#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct Pos{ int y; int x; };

const int INF = 2147000000;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int t, w, h;
int fire[1001][1001];
int player[1001][1001];
char board[1001][1001];
Pos playerPos;
vector<Pos> firePos, exitPos;

void FireBFS(Pos start)
{
	queue<Pos> q;
	q.push(start);
	fire[start.y][start.x] = 1;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y+dy[i], curr.x+dx[i]};

			if(next.y<0 || next.x<0 || next.y>=h || next.x>=w) continue;
			if(board[next.y][next.x]=='#' || board[next.y][next.x]=='@') continue;
			if(fire[next.y][next.x]!=0) continue;

			q.push(next);
			fire[next.y][next.x] = fire[curr.y][curr.x]+1;
		}
	}
}

void PlayerBFS(Pos start)
{
	queue<Pos> q;
	q.push(start);
	player[start.y][start.x] = 1;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y+dy[i], curr.x+dx[i]};

			if(next.y<0 || next.x<0 || next.y>=h || next.x>=w) continue;
			if(board[next.y][next.x]=='#' || board[next.y][next.x]=='*') continue;
			if(player[next.y][next.x]!=0) continue;

			q.push(next);
			player[next.y][next.x] = player[curr.y][curr.x]+1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>w>>h;
		cout<<"w : "<<w<<", h : "<<h<<'\n';
		
		/*for(int i=0; i<h; i++)
		{
			memset(fire[i], 0, sizeof(int)*w);
			memset(player[i], 0, sizeof(int)*w);
		}
*/
		for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			cin>>board[i][j];

			//if(board[i][j]=='@') playerPos={i, j};
			//else if(board[i][j]=='*') firePos.push_back({i, j});

			//if(i==0 || i==h-1 || j==0 || j==w-1 || board[i][j]=='.')
			//	exitPos.push_back({i, j});
		}
/*
		PlayerBFS(playerPos);
		for(const Pos &p : firePos) 
			FireBFS(p);
		
		//======Debug Code===============================
		cout<<"------------\n";
		for(int i=0; i<h; i++)
		{			
			for(int j=0; j<w; j++)
			{
				cout<<player[i][j];
			}
			cout<<'\n';
		}
		cout<<"------------\n";

		cout<<"------------\n";
		for(int i=0; i<h; i++)
		{			
			for(int j=0; j<w; j++)
			{
				cout<<fire[i][j];
			}
			cout<<'\n';
		}
		printf("-----------\n\n");
		//===============================================

		//Check exit
		int answer=INF;
		for(const Pos &p : exitPos)
			if(fire[p.y][p.x] > player[p.y][p.x])
				answer=min(answer, player[p.y][p.x]);

		if(answer==INF) printf("IMPOSSIBLE\n");
		else printf("%d\n", answer);
*/
		exitPos.clear();
		firePos.clear();
		w=h=0;
	}

	return 0;
}
