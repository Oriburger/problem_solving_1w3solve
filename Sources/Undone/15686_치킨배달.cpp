#include <iostream>
#include <vector>
using namespace std;

struct Pos{ int y; int x; };

const int INF = 2147000000;
int n, m, answer=0;
int board[50][50];
vector<Pos> home;

int GetDist(Pos p1, Pos p2)
{
	return abs(p1.y-p2.y) + abs(p1.x-p2.x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		cin>>board[i][j];
		if(board[i][j]==1)
			home.push_back({i,j});
	}
	
	for(int h=0; h<home.size(); h++)
	{
		int dist=INF;
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(board[i][j]==2)
				dist=min(dist, GetDist(home[h], {i, j}));
		
		answer += dist; 
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
