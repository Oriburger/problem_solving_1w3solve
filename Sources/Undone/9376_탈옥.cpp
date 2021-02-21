#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct Pos{ int y, x; };

int t, h, w, ans;
int sum[103][103]; //BFS 결과값의 합
int cache[3][103][103]; //각 BFS 결과값
vector<char> board[103]; //맵
vector<Pos> prisoner; //BFS 시작점 저장 배열 (죄수 2명과 (0, 0))

void BFS(Pos start, const int idx)
{
	deque<Pos> q;
	q.push_back(start);

	cache[idx][start.y][start.x]=0;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop_front();

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			
			if(next.y < 0 || next.x < 0 
				|| next.y >= h+2 || next.x >= w+2) continue;
			if(board[next.y][next.x]=='*') continue;
			if(cache[idx][next.y][next.x]!=-1) continue;

			if(board[next.y][next.x]=='#')
			{
				cache[idx][next.y][next.x] = cache[idx][curr.y][curr.x] + 1;
				q.push_back(next);
			}
			else
			{
				cache[idx][next.y][next.x] = cache[idx][curr.y][curr.x];
				q.push_front(next);
			}
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
		cin>>h>>w;

		/*----Init----*/
		ans=2147000000;
		prisoner.clear();
		memset(cache, -1, sizeof(cache));
		memset(sum, 0, sizeof(sum));
		for(int i=0; i<h+2; i++)
		{
			board[i].clear();
			board[i].resize(w+2, '.');
		}

		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
			{
				cin>>board[i][j];
				if(board[i][j]=='$')
					prisoner.push_back({i, j});
			}

		/*----BFS----*/
		prisoner.push_back({0, 0});
		for(int i=0; i<3; i++)
			BFS({prisoner[i].y, prisoner[i].x}, i);

		/*----Answer----*/
		for(int i=0; i<h+2; i++)
		{
			for(int j=0; j<w+2; j++)
			{
				if(board[i][j]=='*') continue;
				for(int k=0; k<3; k++)
					sum[i][j]+=cache[k][i][j];
				if(board[i][j]=='#')
					sum[i][j]-=2;
				
				if(sum[i][j]<0) continue;

				ans = min(ans, sum[i][j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
