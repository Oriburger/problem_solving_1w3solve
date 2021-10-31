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
int answer[6]; 

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

int get_answer()
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
				if(bfs_flag)
				{
					//cout<<"Island Case\n";
					return 0;
				}
				BFS(y, x);
				bfs_flag = true;
			}

			for(int s=0; s<=1; s++)
			for(int d=0; d<4; d++)
			for(const vector<P> &p : correct)
			{
				bool find_flag = true;
				int pair_val = 0;
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

					if(ny<0 || nx<0 || ny>=6 || nx>=6) find_flag = false;
					if(!board[ny][nx]) find_flag = false;
					if(!find_flag) break;
					
					pair_val = board[ny][nx];
				}
				
				if(find_flag)
				{
					//cout<<board[y][x]<<"-"<<pair_val<<'\n';
					if(answer[board[y][x]] && answer[board[y][x]]!=pair_val) 
					{
						return 0;
					}
					
					answer[board[y][x]] = pair_val;
					if(board[y][x]==1) ret = pair_val;
				}
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			cin>>board[i][j];
	
	cout<<get_answer()<<'\n';

	return 0;
}
