#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos{ int y; int x; };
struct Edge{ int cost; int y; int x; };
const int MAX_N = 51;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<Edge> edges;
Pos stPos;

void BFS(Pos start)
{
	int vID = 0; //정점의 번호
	queue<Edge> q;
	q.push({0, start.y, start.x});
	visited[start.y][start.x]=true;

	while(!q.empty())
	{
		Edge curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			Edge next = {curr.cost+1, curr.y+dy[i], curr.x+dx[i]};

			if(visited[next.y][next.x]) continue;
			if(board[next.y][next.x]=='1') continue;
			if(next.y<0 || next.x<0 || next.y>=n || next.x>=n) continue;
			if(board[next.y][next.x]=='K')
			{
				edges.push_back({next.cost, vID, vID+1});
				next.cost=0;
			}

			visited[next.y][next.x]=true;
			q.push(next);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		scanf("%c", &board[i][j]);
		if(board[i][j]=='S')
			stPos = {i, j};
	}

	BFS(stPos);

	return 0;
}
