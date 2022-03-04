#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

typedef pair<int, int> P;

int n, k, board[201][201];
int s, x, y, cnt=0;

queue<P> q, tmp;
vector<pair<int, P> > st_pos; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>board[i][j];
			if(board[i][j]>0)
			{
				st_pos.push_back({board[i][j], {i, j}});
				cnt = cnt + 1;
			}
		}	

	sort(st_pos.begin(), st_pos.end());
	for(int i=0; i<cnt; i++)
		q.push(st_pos[i].second);

	cin>>s>>y>>x;

	for(int i=0; i<s; i++)
	{
		while(!q.empty())
		{
			P curr = q.front();
			q.pop();

			for(int d=0; d<4; d++)
			{
				int ny = curr.first + dy[d];
				int nx = curr.second + dx[d];
				if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
				if(board[ny][nx]!=0) continue;
				
				board[ny][nx] = board[curr.first][curr.second];
				tmp.push({ny, nx});
			}
		}
		if(board[y-1][x-1] != 0) break;
		q = tmp;
	}	
	cout<<board[y-1][x-1]<<'\n';

	return 0;
}
