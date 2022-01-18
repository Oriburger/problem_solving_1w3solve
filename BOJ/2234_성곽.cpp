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
int board[50][50], board2[2501][2501]; //board2는 영역, 즉 '방'에 대한 그래프 정보
vector<vector<int> > areaID, visited;
vector<int> area = {0};

int BFS1(int y, int x, int id) //첫 번째 BFS, 각 칸에 영역의 id를 붙이고,
{                              //해당 영역의 넓이를 반환한다 
	int ret = 0;
	queue<P> q;
	
	q.push({y, x});
	areaID[y][x] = id;

	while(!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		ret += 1; //방문하는 칸의 개수가 곧 넓이
		q.pop();

		for(int d=0; d<4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];
			
			if(ny<0 || nx<0 || ny>=m || nx>=n) continue; //배열 범위 벗어나는지?
			if(areaID[ny][nx]) continue; //중복 방문 체크
			if((wall[d] & board[cy][cx]) != 0) continue; //해당 방향에 벽이 있다면 continue

			q.push({ny, nx});
			areaID[ny][nx] = id;
		}
	}
	return ret; 
}

void BFS2(int y, int x) //두 번째 BFS, 인접한 영역들을 간선으로 이어준다. (board2)
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
			if((wall[d] & board[cy][cx]) != 0) //벽으로 가로 막혀있는데,
			{
				if(areaID[cy][cx] != areaID[ny][nx]) //두 칸의 방이 다르다면? 
					board2[areaID[cy][cx]][areaID[ny][nx]] = true; //간선 추가
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
			if(!k && areaID[i][j]==0) //첫 번째 BFS
			{
				area.push_back(BFS1(i, j, ++roomCnt));
				maxAns1 = max(maxAns1, area.back());
			}
			else if(k && visited[i][j]==0) BFS2(i, j); //두 번째 BFS
		}
	
	maxAns2 = maxAns1; //방이 1개일 경우, 방의 최대 넓이가 3번째 답이 됨
	for(int i=1; i<=roomCnt; i++) //모든 방에 대한 
		for(int j=1; j<=roomCnt; j++) //쌍들을 순회하며
			if(board2[i][j]) //두 영역이 인접하다면
				maxAns2 = max(maxAns2, area[i] + ar ea[j]); //벽을 부숴서 얻을수 있는 값을 정답으로 갱신

	cout<<roomCnt<<'\n'<<maxAns1<<'\n'<<maxAns2<<'\n';

	return 0;
}
