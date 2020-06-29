#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{ int y; int x; };

//====================
const int INF = 2147000000;

int n, m, answer=INF;
int board[50][50];

vector<int> combi;
vector<Pos> home;
vector<Pos> chicken;
//====================

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
		else if(board[i][j]==2)
			chicken.push_back({i, j});
	}
	
	combi.resize(chicken.size(), 0);
	for(int i=0; i<m; i++)
		combi[i]=1;
	sort(combi.begin(), combi.end());
	
	do
	{
		int total=0;
		for(int h=0; h<home.size(); h++)
		{
			int dist=INF;
			for(int c=0; c<chicken.size(); c++)
			{
				if(combi[c]!=1) continue;
			
				dist=min(dist, GetDist(chicken[c], home[h]));
			}
			total+=dist;
		}
		answer = min(answer, total);
		
	}while(next_permutation(combi.begin(), combi.end()));
		
	cout<<answer<<'\n';
	
	return 0;
}
