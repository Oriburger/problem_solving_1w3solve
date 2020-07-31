#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 2147000000
using namespace std;

struct Pos{ int y; int x; };

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int n, board[21][21];
vector<Pos> fish;
Pos bsPos; //baby shark du dududududu
int bsSize=2; //아기 상어의 크기

//현재의 위치에서 가장 가까운 '먹을 수 있는' 물고기의 위치 리스트 반환
vector<Pos> BFS(Pos start) 
{
	vector<Pos> ret;
	int dist = INF;
	queue<pair<Pos, int> > q;
	bool visited[21][21]={false};

	visited[start.y][start.x]=true;
	q.push({start, 0});

	while(!q.empty())
	{
		Pos curr = q.front().first;
		int curDist = q.front().second;
		q.pop();

		cout<<curr.y<<','<<curr.x<<'\n';
		
		//아기상어가 먹을 수 있는 물고기라면,
		if(board[curr.y][curr.x] < bsSize
			&& board[curr.y][curr.x] >= 1 && board[curr.y][curr.x] <= 9)
		{
			ret.push_back({curr.y, curr.x});
			dist = curDist;

			cout<<dist<<'\n';
		}

		if(curDist <= dist)
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};

			if(next.y<0 || next.x<0 || next.y>=n || next.x>=n) continue;
			if(visited[next.y][next.x]) continue;

			q.push({next, curDist+1});
			visited[next.y][next.x]=true;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>board[i][j];
			if(board[i][j]==9) bsPos = {i, j};
			if(board[i][j]==1) fish.push_back({i, j});
		}
	}
	
	cout<<

	BFS(bsPos);

	return 0;
}
