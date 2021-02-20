#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const int INF = 2147000000;

struct Pos{ int y, x; };

int t, h, w, ans;
vector<char> board[103];
vector<Pos> prisoner_pos;
vector<int> sum[103];

void BFS(Pos start)
{
	deque<Pos> q;
	q.push_back(start);
	vector<int> cache[103];

	for(int i=0; i<h+2; i++)
		cache[i].resize(w+2, INF);

	cache[start.y][start.x] = 0;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop_front();

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			
			if(next.y < 0 || next.x < 0 
				|| next.y >= h+1 || next.x >= w+1) continue;
			if(board[next.y][next.x]=='*') continue;
			if(cache[next.y][next.x]!=INF) continue;

			cache[next.y][next.x] = cache[curr.y][curr.x];
			if(board[next.y][next.x]=='#')
			{
				board[next.y][next.x] = '.';
				cache[next.y][next.x] = cache[curr.y][curr.x] + 1;
				q.push_front(next);
			}
			else q.push_back(next);
		}
	}
	
	for(int i=0; i<h+2; i++)
	{
		for(int j=0; j<w+2; j++)
		{
			if(cache[i][j]==INF)
			{
				cout<<"@";
				continue; 
			}
			cout<<cache[i][j];
			sum[i][j]+=cache[i][j];
		}
		cout<<'\n';
	}
	cout<<"------\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>h>>w;

		ans=0;
		prisoner_pos.clear();
		for(int i=0; i<h+2; i++)
		{
			board[i].clear();
			sum[i].clear();
			board[i].resize(w+2, '.');
			sum[i].resize(w+2, INF);
		}
	
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
			{
				cin>>board[i][j];
				if(board[i][j]=='$')
					prisoner_pos.push_back({i, j});
			}

		prisoner_pos.push_back({0, 0});
		for(Pos &p : prisoner_pos)
			BFS({p.y, p.x});


		for(int i=0; i<=h+1; i++)
		{
			for(int j=0; j<=w+1; j++)
			{
			//	if(cache[i][j]==INF) cout<<"@";
			//	else cout<<cache[i][j];
				ans = min(ans, sum[i][j]);
			}
		}
		//cout<<"----\n";


		cout<<ans<<'\n';
		cout<<"===================\n";
	}

	return 0;
}
