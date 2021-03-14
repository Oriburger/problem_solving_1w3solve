#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct Pos{ int y; int x; };

int n, m, keyState = (1<<6);
int ans=0; bool flag = false;
char board[50][50];
Pos start;

int BFS()
{
	bool visited[50][50];
	queue<pair<Pos, int> > q;
	
	memset(visited, false, sizeof(visited));

	q.push({start, 0});
	visited[start.y][start.x]=true;
	board[start.y][start.x]='.';

	while(!q.empty())
	{
		Pos curr = q.front().first;
		int curCnt = q.front().second;
		q.pop();

	//	cout<<"curr : "<<curr.y<<' '<<curr.x<<'\n';

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};

			//cout<<" > next : "<<next.y<<' '<<next.x<<" --- ";

			if(next.y<0 || next.y>=n || next.x<0 || next.x>=m)
			{
			//	cout<<"Out of range\n";
				continue;
			}
			if(board[next.y][next.x]=='#' || visited[next.y][next.x])
			{
			//	cout<<"Wall or already visited\n";
				continue;
			}
			if((board[next.y][next.x]>='A' && board[next.y][next.x]<='F')
				&& !(keyState & (1<<(board[next.y][next.x]-'A'))))
			{
			//	cout<<"Key is not found!\n";
				continue;
			}

		//	cout<<"pushed, ";

			if(board[next.y][next.x]=='1')
			{
				flag = true;
			//	cout<<" escaped!\n";
				return curCnt+1;
			}
			else if(board[next.y][next.x]>='a' && board[next.y][next.x]<='f')
			{
				keyState |= (1<<(board[next.y][next.x]-'a'));
				start = {next.y, next.x};
			//	cout<<" found a key!\n";
				return curCnt+1;
			}

			q.push({next, curCnt+1});
			visited[next.y][next.x]=true;
		}
	}

	return 0;
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
		if(board[i][j]=='0')
			start = {i, j};
	}

	while(!flag)
	{
	//	cout<<"start at {";
	//	cout<<start.y<<' '<<start.x<<"} --"<<'\n';

		int temp = BFS();

		if(temp==0)
		{
			ans=-1;
			break;
		}

		ans += temp;
		//cout<<"-----------------\n\n";
	}

	cout<<ans<<'\n';

	return 0;
}
