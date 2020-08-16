#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct Pos { int y; int x; };

const int dy[4]={1,-1,0,0};
const int dx[4]={0, 0, 1, -1};
const int INF = 2147000000;

int t, w, h;
char board[1001][1001];

vector<Pos> posArr;

int BFS(const vector<Pos>& start)
{
	queue<pair<Pos, char> > q;
	int visited[1001][1001]={0};
	int startCnt = 1;
	
	for(const Pos& p : start)
	{
		q.push({p, board[p.y][p.x]});
		visited[p.y][p.x]=1;
	}

	while(!q.empty())
	{
		Pos curr = q.front().first;
		char curType = q.front().second;
		int curCnt = visited[curr.y][curr.x];
		q.pop();
		
		if(curType=='@') startCnt--;
	  
	  if(curr.y == h-1 or curr.y == 0 
		  or curr.x == w-1 or curr.x == 0)
		{
			if(curType=='@') return curCnt;
			else if(startCnt==0) return INF;
		}
		
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y+dy[i], curr.x+dx[i]};
			
			if(next.y<0 or next.y>=h
			  or next.x<0 or next.x>=w)
			  continue;
			if(board[next.y][next.x]=='#')
			  continue;
			  
			if(board[curr.y][curr.x]!='@')
			if(visited[next.y][next.x]
			 <= curCnt+1 
			 and visited[next.y][next.x]!=0)
			  continue;
			
			if(curType=='@') startCnt++;
			q.push({next, curType});
			visited[next.y][next.x]=curCnt+1;
		}
	}
	
	return INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
  
  while(t--)
  {
  	cin>>w>>h;
  	
  	for(int i=0; i<h; i++)
  	{
    	for(int j=0; j<w; j++)
    	{
    	  cin>>board[i][j];
    	  if(board[i][j]=='@' 
    	   or board[i][j]=='*')
        posArr.push_back({i, j});
    	}
  	}
  	
    int answer = BFS(posArr);
  	
    if(answer!=INF)
      cout<<answer<<"\n";
    else 
      cout<<"IMPOSSIBLE\n";
      
    posArr.clear();
  }
	
	return 0;
}
