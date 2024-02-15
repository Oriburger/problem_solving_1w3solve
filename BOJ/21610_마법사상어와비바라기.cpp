#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos { int y; int x; };

int n, m;
int a[51][51];
bool check[51][51];
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<Pos> clouds;

void rain(int d, int s)
{
	for(auto &c : clouds)
	{
		c.y = (c.y + dy[d] * s - 1 + n*100) % n + 1; 
		c.x = (c.x + dx[d] * s - 1 + n*100) % n + 1;
		a[c.y][c.x] += 1;
		check[c.y][c.x] = true;
	}
}

void duplicate()
{
	for(auto &c : clouds)
	{
		for(int d=1; d<=7; d+=2)
		{
			int ny = c.y + dy[d];
			int nx = c.x + dx[d];
			
			if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
			a[c.y][c.x] += (a[ny][nx] > 0 ? 1 : 0);
		}
	}
}

void generate()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i][j] < 2 || check[i][j]) continue;
			clouds.push_back({i, j});
			a[i][j] -= 2;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	
	clouds = {{n, 1}, {n, 2}, {n-1, 1}, {n-1, 2}};
	for(int i=0; i<m; i++)
	{
		int d, s;
		cin>>d>>s;
		d--;
		
		//simulate cloud
		rain(d, s);
		duplicate();
		clouds.clear();
		
		//generate new clouds
		generate();
		memset(check, false, sizeof(check));
	}
	
	int sum = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum += a[i][j];
	cout<<sum<<'\n';
			
	return 0;
}
