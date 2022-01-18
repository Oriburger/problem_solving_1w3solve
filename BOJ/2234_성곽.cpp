#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
const int wall[4] = {2, 8, 1, 4};
 
typedef pair<int, int> P;

int n, m, roomCnt, maxAns1, maxAns2;
int board[50][50], board2[2501][2501];
vector<vector<int> > areaID, visited;
vector<int> area = {0};

int BFS1(int y, int x, int id)
{
	int ret = 0;
	queue<P> q;
	
	q.push({y, x});
	areaID[y][x] = id;

	while(!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		ret += 1;
		q.pop();

		for(int d=0; d<4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];
			
			if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
			if(areaID[ny][nx]) continue;
			if((wall[d] & board[cy][cx]) != 0) continue;

			q.push({ny, nx});
			areaID[ny][nx] = id;
		}
	}
	return ret; 
}

void BFS2(int y, int x)
{
	queue<P> q;
	q.push({y, x});
	visited[y][x] = true;

	while(!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for(int d=0; d<4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];
			
			if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
			if(visited[ny][nx]) continue;
			if((wall[d] & board[cy][cx]) != 0)
			{
				if(areaID[cy][cx] != areaID[ny][nx])
					board2[areaID[cy][cx]][areaID[ny][nx]] = true;
				continue;
			}

			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	areaID = visited = vector<vector<int> >(m, vector<int>(n, 0));

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	for(int k=0; k<2; k++)
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(!k && areaID[i][j]==0)
			{
				area.push_back(BFS1(i, j, ++roomCnt));
				maxAns1 = max(maxAns1, area.back());
			}
			else if(k && visited[i][j]==0) BFS2(i, j);
		}
	
	maxAns2 = maxAns1;
	for(int i=1; i<=roomCnt; i++)
		for(int j=1; j<=roomCnt; j++)
			if(board2[i][j])
				maxAns2 = max(maxAns2, area[i] + area[j]);

	cout<<roomCnt<<'\n'<<maxAns1<<'\n'<<maxAns2<<'\n';

	return 0;
}
