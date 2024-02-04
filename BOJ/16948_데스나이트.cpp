#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[6] = {-2, -2, 0, 0, 2, 2};
const int dx[6] = {-1, 1, -2, 2, -1, 1};

struct pos{ int y; int x; };

int n;
pos p1, p2;
int board[200][200];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>p1.y>>p1.x>>p2.y>>p2.x;
	
	queue<pos> q;
	q.push(p1);
	board[p1.y][p1.x] = 1;
	
	while(!q.empty())
	{
		pos curr = q.front();
		q.pop();
		
		if(curr.y == p2.y && curr.x == p2.x) break;
		
		for(int d=0; d<6; d++)
		{
			pos next = {curr.y + dy[d], curr.x + dx[d]};
			
			if(next.y < 0 || next.x < 0 || next.y >= n || next.x >= n) continue;
			if(board[next.y][next.x] != 0) continue;
			
			board[next.y][next.x] = board[curr.y][curr.x] + 1;
			q.push(next);
		}
	}
	cout<<board[p2.y][p2.x]-1<<'\n';
	
	return 0;
}
