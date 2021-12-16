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
char board[102][102];
bool visited[102][102];
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

		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i]};
			
			if(next.y<0 || next.x<0 || next.y>=h+2 || next.x>=w+2) continue; //범위 밖
			if(board[next.y][next.x] == '*') continue; //벽
			if(visited[next.y][next.x]) continue; //이미 방문함       -> continue

			if(board[next.y][next.x]=='$') //문서를 발견! 챙기자.
			{
				board[next.y][next.x]='.'; //빈 칸이 되었다.
				ans++; //ans 1 증가
			}
			else if(board[next.y][next.x]<='Z' && board[next.y][next.x]>='A') //문이다!
			{ 
				if(hasKey[board[next.y][next.x]-'A'])  //열쇠가 있나?
					board[next.y][next.x] = '.'; //있다면 그냥 열어버리자.
				else continue; //없네.. 돌아가자. 
			}
			else if(board[next.y][next.x]<='z' && board[next.y][next.x]>='a') //열쇠다!
			{
				hasKey[board[next.y][next.x]-'a'] = true; //체크체크.
				stPos = {next.y, next.x}; //다음 BFS의 시작지점
				board[next.y][next.x]='.'; //빈 칸이 되었다.
				flag = true; //다음 BFS가 가능하다.
			}
			q.push(next); //큐에 넣고, 방문 체크
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
		for(int i=1; i<=h; i++) //가장 자리에 빈 공간을 만듦.
			for(int j=1; j<=w; j++)
				cin>>board[i][j];

		cin>>keySet; 
		if(keySet[0]!='0')
		{
			for(int i=0; i<keySet.size(); i++)
				hasKey[keySet[i]-'a']=true;  //기존에 갖고 있는 열쇠 체크
		}

		stPos = {0, 0}; //최초 시작은 빌딩 밖
		while(1)
		{
			if(!BFS(stPos))
				break;
		}
		cout<<ans<<'\n';

		hasKey.clear();
		keySet.clear();
	}

	return 0;
}
