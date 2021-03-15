#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

struct Pos{ int y; int x; };

int h, w, ans;
Pos stPos;
string keySet;
char board[101][101];
bool visited[101][101];
vector<bool> hasKey;

bool BFS(Pos start)
{
	bool flag = false;
	queue<Pos> q;
	memset(visited, false, sizeof(visited));

	q.push(start);
	visited[start.y][start.x] = true;
	while(!q.empty())
	{	
		Pos curr = q.front();
		q.pop();

		//cout<<"curr : "<<curr.y<<' '<<curr.x<<'\n';

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			
			if(next.y<0 || next.x<0 || next.y>=h+2 || next.x>=w+2) continue;
			if(board[next.y][next.x] == '*') continue;
			if(visited[next.y][next.x]) continue;

			if(board[next.y][next.x]=='$')
			{
			//	cout<<"Found Document on - {"<<next.y<<", "<<next.x<<"} -\n";
				board[next.y][next.x]='.';
				ans++;
			}
			else if(board[next.y][next.x]<='Z' && board[next.y][next.x]>='A')
			{
				if(hasKey[board[next.y][next.x]-'A']) 
					board[next.y][next.x] = '.';
				else continue;
			}
			else if(board[next.y][next.x]<='z' && board[next.y][next.x]>='a')
			{
				hasKey[board[next.y][next.x]-'a'] = true;
				stPos = {next.y, next.x};
				board[next.y][next.x]='.';
				flag = true;
			}
			q.push(next);
			visited[next.y][next.x] = true;
		}
	}
	return flag;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		cin>>h>>w;

		ans=0;
		memset(board, 0, sizeof(board));
		hasKey.resize(26, false);
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
				cin>>board[i][j];

		cin>>keySet;
		if(keySet[0]!='0')
		{
			for(int i=0; i<keySet.size(); i++)
				hasKey[keySet[i]-'a']=true;
		}

		stPos = {0, 0};
		while(1)
		{
			//cout<<"--stPos : "<<stPos.y<<' '<<stPos.x<<"----[";
			//cout<<board[stPos.y][stPos.x]<<"]----\n";
			if(!BFS(stPos))
				break;
			//cout<<"-------------------------------\n";
		}
		cout<<ans<<'\n';

		hasKey.clear();
	}

	return 0;
}
