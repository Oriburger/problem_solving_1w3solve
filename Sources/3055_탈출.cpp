#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Pos{ int y; int x; int val; };

const int INF=987654321;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int r, c, answer=INF;
int hedgehog[50][50];
int flood[50][50];
char board[50][50]; 
Pos st, fin;

queue<Pos> hedQ;
queue<Pos> floodQ;

void HedgeBFS()
{
	hedQ.push(st);
	hedgehog[st.y][st.x]=1;
	
	while(!hedQ.empty())
	{
		Pos curr = hedQ.front();
		hedQ.pop();
		
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i], curr.val+1};
			
			if(next.y<0 || next.x<0 || next.y>=r || next.x>=c) continue;
			if(hedgehog[next.y][next.x]!=0) continue;
			if(board[next.y][next.x]=='X') continue;
			if(board[next.y][next.x]=='*') continue;
			if(board[next.y][next.x]=='D') continue;
			
			hedQ.push(next);
			hedgehog[next.y][next.x]=next.val;
		}
	}
}

void FloodBFS()
{
	while(!floodQ.empty())
	{
		Pos curr = floodQ.front();
		floodQ.pop();
		
		for(int i=0; i<4; i++)
		{
			Pos next = {curr.y + dy[i], curr.x + dx[i], curr.val+1};
			
			if(next.y<0 || next.x<0 || next.y>=r || next.x>=c) continue;
			if(next.y == st.y && next.x == st.x) continue;
			if(flood[next.y][next.x]!=0) continue;
			if(board[next.y][next.x]=='D') continue;
			if(board[next.y][next.x]=='X') continue;
			
			floodQ.push(next);
			flood[next.y][next.x]=next.val;
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
	{
		cin>>board[i][j];
		if(board[i][j]=='S') st = {i, j, 1};
		else if(board[i][j]=='D') fin = {i, j};
		else if(board[i][j]=='*')
		{
			floodQ.push({i, j, 1});
			flood[i][j]=1;
		}
	}
	
	FloodBFS();
	HedgeBFS();
	
	int y, x;
	for(int i=0; i<4; i++)
	{
		y=fin.y+dy[i];
		x=fin.x+dx[i];
		
		if(y<0 || x<0 || y>=r || x>=c ) continue;
		if(hedgehog[y][x]==0) continue;
		
		if(flood[y][x]==0 || hedgehog[y][x] < flood[y][x]) 
			answer = min(answer, hedgehog[y][x]);
	}

	
	if(answer!=INF)
		cout<<answer<<"\n";
	else
		cout<<"KAKTUS\n";

	
	return 0;
}
