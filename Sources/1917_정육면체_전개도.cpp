#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const P dir[4] = {{1,1}, {1, -1}, {-1, 1}, {-1, -1}};
const vector<P> correct[4] = {{{0,1}, {1,1}, {1,2}}
							 ,{{0,1}, {0,2}}
							 ,{{1,0}, {1,1}, {1,2}, {2,2}}
							 ,{{1,0}, {1,1}, {1,2}, {1,3}, {2,3}}};

int board[6][6];
bool visited[6][6];

void BFS(int y, int x)
{
	queue<P> q;
	q.push({y, x});
	visited[y][x] = true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			P next = {curr.first + dy[i]
						, curr.second + dx[i]};
			
			if(next.first<0 || next.second<0 
				|| next.first>=6 || next.second>=6) continue;
			if(visited[next.first][next.second]) continue;

			visited[next.first][next.second] = true;
			q.push(next);
		}
	}
}

string get_answer()
{
	int ret = 0;
	bool bfs_flag = false;

	for(int y=0; y<6; y++)
	{
		for(int x=0; x<6; x++)
		{
			if(!board[y][x]) continue;
			if(!visited[y][x])
			{
				if(bfs_flag) return "no";
				BFS(y, x);
				bfs_flag = true;
			}

			P find_pos = {-1, -1};

			for(int s=0; s<=1; s++)
			for(int d=0; d<4; d++)
			for(const vector<P> &p : correct)
			{
				P temp_pos = {-1, -1};
				for(int i=0; i<p.size(); i++)
				{
					int ny, nx;
					if(!s)
					{
						ny = y + p[i].first * dir[d].first;
						nx = x + p[i].second * dir[d].second;
					}
					else
					{
						ny = y + p[i].second * dir[d].second;
						nx = x + p[i].first * dir[d].first;
					}

					if(ny<0 || nx<0 || ny>=6 || nx>=6) break;
					if(!board[ny][nx]) break;
					
					if(i == p.size()-1) temp_pos = {ny, nx};
				}
				
				if(temp_pos != P(-1, -1))
				{
					if(find_pos != P(-1, -1)
					&& find_pos != temp_pos) return "no";
					find_pos = temp_pos;
				}
			}
		}
	}
	return "yes";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;

	while(n--)
	{
		for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			cin>>board[i][j];
	
		cout<<get_answer()<<'\n';

		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
