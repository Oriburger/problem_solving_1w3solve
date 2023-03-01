#include <bits/stdc++.h>
#define LEFT -1
#define RIGHT 1
using namespace std;

int h, w, top, topXpos, ans;
vector<int> blocks;

int getPoolCount(int y, int x, int dir, int prev = -1)
{
	if(x < 0 || x > w-1) return 0;
	bool hasBlock = blocks[x] >= y;
	if(hasBlock && prev != -1)	return getPoolCount(y, x + dir, dir, hasBlock ? x : prev) + (abs(prev-x)-1);
	return getPoolCount(y, x + dir, dir, hasBlock ? x : prev);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>h>>w; 

	blocks = vector<int>(w, 0);
	for(int i=0; i<w; i++)
	{
		cin>>blocks[i];
		if(top < blocks[i])
		{
			top = blocks[i];
			topXpos = i;
		}
	}

	while(top)
	{
		ans += getPoolCount(top, topXpos, 1);
		ans += getPoolCount(top, topXpos, -1);
		top -= 1;	
	}

	cout<<ans<<'\n';
	
	return 0;
}
