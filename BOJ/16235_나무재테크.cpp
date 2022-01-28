#include <bits/stdc++.h>
using namespace std;

const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
struct Tree{ int y; int x; int age; };

int n, m, k, a[10][10], board[10][10], tmp[10][10], ans;
deque<int> treeInfo[10][10];

inline bool IsValid(const int& y, const int& x)
{
	if(y<0 || x<0 || y>=n || x>=n) return false;
	return true;
}

void Spring()
{
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			if(treeInfo[y][x].size()>0)
			{
				bool eraseFlag = false;
				for(deque<int>::iterator tree = (treeInfo[y][x]).begin(); tree != (treeInfo[y][x]).end(); tree++)
				{
					if(board[y][x] >= *tree)
					{
						board[y][x] -= *tree;
						(*tree) += 1;
					} 
					else
					{
						tmp[y][x] += (*tree)/2;
						*tree = -1;
						eraseFlag = true;
					}
				}
				if(eraseFlag)
					treeInfo[y][x].erase(remove(treeInfo[y][x].begin(), treeInfo[y][x].end(), -1), treeInfo[y][x].end());
			}
}

void Summer()
{
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			board[y][x] += tmp[y][x];
}

void Autumn()
{
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			if(treeInfo[y][x].size()>0)
				for(deque<int>::iterator tree = (treeInfo[y][x]).begin(); tree != (treeInfo[y][x]).end(); tree++)
				{
					if((*tree) % 5 != 0) continue;
					for(int d=0; d<8; d++)
					{
						if(!IsValid(y+dy[d], x+dx[d])) continue;
						treeInfo[y+dy[d]][x+dx[d]].push_front(1);
					}
				}
}

void Winter()
{
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			board[y][x] += a[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>k;

	fill(&board[0][0], &board[9][9]+1, 5);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	
	for(int i=0; i<m; i++)
	{
		int y, x, z;
		cin>>y>>x>>z;
		treeInfo[y-1][x-1].push_back(z);
	}

	for(int year=0; year<k; year++)
	{
		memset(tmp, 0, sizeof(tmp));
		
		Spring();
		Summer();
		Autumn();
		Winter();
	}
	
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			ans += treeInfo[y][x].size();
			
	cout<<ans<<'\n';

	return 0;
}
