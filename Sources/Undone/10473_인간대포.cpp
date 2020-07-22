#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 2147000000
using namespace std;

typedef pair<int, double> P;

struct Pos{ double y; double x; };

double GetDist(Pos a, Pos b)
{
	return sqrt(pow(fabs(a.y-b.y), 2)+pow(fabs(a.x-b.x), 2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Pos st, dest;
	int n; vector<Pos> cannon;
	vector<vector<P> > adj;

	cin>>st.y>>st.x>>dest.y>>dest.x;
	
	cin>>n;

	cannon.resize(n);
	adj.resize(n);
	for(int i=0; i<n; i++)
		cin>>cannon[i].y>>cannon[i].x;
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			adj[i].push_back({j, GetDist(cannon[i], cannon[j])});
		}
	}

	priority_queue<Pos, vector<Pos>, greater<Pos> > pq;
	vector<double> dist;


	return 0;
}
