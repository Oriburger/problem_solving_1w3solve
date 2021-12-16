#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Pos { int x; int y; };

int t, n;
vector<Pos> p;
vector<vector<int> > map;

int GetDist(Pos p1, Pos p2)
{
	return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		map.resize(n+2);
		for(int i=0; i<n+2; i++)
		{
			int ix, iy; //input
			cin>>ix>>iy;
			p.push_back({ix, iy});
			
			map[i].resize(n+2, 0);
		}
		
		for(int i=0; i<n+2; i++)
		for(int j=0; j<n+2; j++)
			if(GetDist(p[i], p[j]) <= 1000)
			{
				map[i][j] = 1;
				map[j][i] = 1;
			}
			
		for(int k=0; k<n+2; k++)
		for(int i=0; i<n+2; i++)
		for(int j=0; j<n+2; j++)
			if(map[i][k] && map[k][j])
			{
				map[i][j] = 1;
				map[j][i] = 1;
			}
		
		cout<< (map[0][n+1] ? "happy" : "sad")<<"\n";				
		
		map.clear();
		p.clear();
	}
	
	return 0;
}
