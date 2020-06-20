#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> P;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};
char board[12][6];
int visited[12][6];
int answer;
bool findFlag;

void ResetVisited()
{
	for(int i=0; i<12; i++)
	for(int j=0; j<6; j++)
		visited[i][j]=0;
}

void UpdateBoard()
{
	for(int i=0; i<6; i++)
	for(int j=0; j<11; j++)
	{
		//¾Æ·¡¿¡ ºóÄ­ÀÌ ÀÖ´Ù¸é Swap
		if(board[j][i]!='.' && board[j+1][i]=='.')  
		{
			char temp = board[j][i];
			board[j][i] = board[j+1][i];
			board[j+1][i] = temp;
			if(j!=0 && board[j-1][i]!='.') j-=2;
		}
	}
}

int GetPuyoCnt(int y, int x, int cnt, const char curColor)
{
	if(y<0 || x<0 || y>=12 || x>=6) return cnt;
	if(visited[y][x] || board[y][x] != curColor) return cnt;
	
	cnt++;
	visited[y][x]=cnt;
	
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		cnt = max(cnt, GetPuyoCnt(ny, nx, cnt, curColor));
	}
	return cnt;
}

void PopPuyo(int y, int x, const char curColor)
{
	if(y<0 || x<0 || y>=12 || x>=6) return;
	if(visited[y][x] || board[y][x] != curColor) return;
	
	visited[y][x]=true;
	board[y][x]='.';
	
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		PopPuyo(ny, nx, curColor);
	}
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<12; i++)
	for(int j=0; j<6; j++)
		cin>>board[i][j];

	while(1)
	{
		findFlag=false;
		for(int i=0; i<12; i++) //Must be edited
		for(int j=0; j<6; j++)
		{
			if(board[i][j]!='.')
			{
				int puyoCnt = GetPuyoCnt(i, j, 0, board[i][j]);
				ResetVisited();	
				if(puyoCnt>=4) 
				{
					findFlag = true;
					PopPuyo(i, j, board[i][j]);
					ResetVisited();
				}
			}
		}
		if(!findFlag) break;
		else
		{
			UpdateBoard();
			answer++;
		}
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
