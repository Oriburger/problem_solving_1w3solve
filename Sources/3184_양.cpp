#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;

const int dy[4] = {0,0,1,-1};
const int dx[4] = {1,-1,0,0};

int r, c;
int wCnt, sCnt; //wolf cnt, sheep cnt;
int wSum, sSum; 
char board[251][251];
bool visited[251][251];

void BFS(int y, int x)
{
	queue<P> q;
	q.push({y, x});
	
	while(!q.empty())
	{
		P curr = q.front();
		
		if(board[curr.first][curr.second] == 'v') wCnt++;
		else if(board[curr.first][curr.second] == 'o') sCnt++;
		
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			P next = {curr.first + dy[i], curr.second + dx[i]};
			
			if(next.first < 0 || next.first >= r ||
				next.second < 0 || next.second >=c ||
				board[next.first][next.second] == '#') continue;
			
			if(visited[next.first][next.second]) continue;
			
			q.push(next);
			visited[next.first][next.second] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>r>>c;
	
	for(int i=0; i<r; i++)
	for(int j=0; j<c; j++)
		cin>>board[i][j];
	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(!visited[i][j])
			{
				BFS(i, j);
				
				if(wCnt < sCnt)
					sSum += sCnt;
				else
					wSum += wCnt;		
			}
			wCnt=0;
			sCnt=0;
		}
	}
	
	cout<<sSum<<' '<<wSum<<'\n';
	
	return 0;
}
