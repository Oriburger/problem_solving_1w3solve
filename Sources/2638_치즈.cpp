#include <iostream>
#include <queue>
#include <vector>
#define BLANK 0
#define CHEEZE 1
#define AIR 2
using namespace std;

struct Pos{ int y, x; };

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, m, answer=0, cheeze_cnt=0;
int board[100][100];

void Update(Pos start)
{
	queue<Pos> q;
	vector<Pos> melt_list;
	vector<vector<bool> > visited;
	vector<vector<int> > air_count;
	visited.assign(100, vector<bool>(100, false));
	air_count.assign(100, vector<int>(100, 0));

	q.push(start);
	visited[start.y][start.x]=true;
	board[start.y][start.x] = AIR;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			
			if(next.y < 0 || next.y >= n 
				|| next.x < 0 || next.x >= m) continue;
			if(board[next.y][next.x]==CHEEZE)
			{
				air_count[next.y][next.x]++;
				if(air_count[next.y][next.x] == 2) 
					melt_list.push_back(next);
				continue;
			}
			if(visited[next.y][next.x]) continue;
			
			board[next.y][next.x] = AIR;
			visited[next.y][next.x] = true;
			q.push(next);
		}
	}

	cheeze_cnt -= melt_list.size();
	for(auto &p : melt_list)
		board[p.y][p.x]=AIR;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin>>board[i][j];
			if(board[i][j]==1)
				cheeze_cnt++;
		}

	while(1)
	{
		if(cheeze_cnt==0) break;

		Update({0, 0});

		answer++;
	}

	cout<<answer<<'\n';

	return 0;
}
