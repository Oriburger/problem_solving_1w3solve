#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

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
	int n; vector<double> cannon;

	cin>>st.y>>st.x>>dest.y>>dest.x;
	
	cin>>n;

	cannon.resize(n);
	for(int i=0; i<n; i++)
		cin>>cannon[i];
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			
		}
	}

	priority_queue<Pos, vector<Pos>, greater<Pos> > pq;



	return 0;
}
