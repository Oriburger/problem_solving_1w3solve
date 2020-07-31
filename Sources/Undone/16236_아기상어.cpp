#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 2147000000
using namespace std;

struct Pos{ int y; int x; };

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int n, board[21][21], answer=0;
Pos bsPos, fish; //아기 상어의 위치, 다음 먹을 물고기
int bsSize=2, bsCnt; //아기 상어의 크기, 먹은 물고기 마리 수

//전달받은 물고기의 위치들 중 우선순위가 제일 높은 것.
bool Comp(Pos &a, Pos &b)
{
	if(a.y > b.y) return false;

	if(a.x > b.x) return false;

	return true;
}

void Debug(int dist, Pos curr)
{
	cout<<"dist : "<<dist<<" / ";
	cout<<"size : "<<board[curr.y][curr.x]<<" / ";
	cout<<"pos : {"<<curr.y<<','<<curr.x<<"}\n";
}

//다음 먹을 물고기까지의 거리 반환
int BFS(Pos start) 
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

		//cout<<curr.y<<','<<curr.x<<'\n';
		
		if(dist < curDist+1) continue;

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};

			if(next.y<0 || next.x<0 || next.y>=n || next.x>=n) continue;
			if(visited[next.y][next.x]) continue;
			//next 칸의 물고기가 상어크기보다 크다면,
			if(board[next.y][next.x] > bsSize) continue;
			
			//아기상어가 먹을 수 있는 물고기라면,
			//ret list에 push한다.
			if(board[next.y][next.x] < bsSize && 
				board[next.y][next.x] >= 1 && board[next.y][next.x] <= 6)
			{
				if(dist > curDist+1) ret.clear();

				ret.push_back({next.y, next.x});
				dist = min(dist, curDist+1);
			}

			q.push({next, curDist+1});
			visited[next.y][next.x]=true;
		}
	}
	if(ret.size()==0) return -1;

	sort(ret.begin(), ret.end(), Comp);
	fish = ret[0];

	Debug(dist, ret[0]);

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>board[i][j];
			if(board[i][j]==9) bsPos = {i, j};
		}
	}

	while(1)
	{
		int dist = BFS(bsPos);

		//먹을 수 있는 물고기가 없다면
		if(dist == -1) break;

		board[bsPos.y][bsPos.x]=0;
		board[fish.y][fish.x]=0;
		bsPos = {fish.y, fish.x};
		bsCnt++;
		if(bsCnt==bsSize)
		{
			bsSize++;
			bsCnt=0;
		}
		answer+=dist;
	}

	cout<<answer<<'\n';

	return 0;
}
