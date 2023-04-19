#include <bits/stdc++.h>
using namespace std;

struct pos{ int y; int x; };
int a, b; 
pos p[2];

pos getPos(const int& val)
{
	pos ret; 
	ret.y = val%4;
	ret.x = val/4;
	if(val%4==0)
	{
		ret.y = 4;
		ret.x = val/4-1;
	}
	return ret;
}

int main()
{
	cin>>a>>b; 

	p[0] = getPos(a);
	p[1] = getPos(b);

	cout<<abs(p[0].y-p[1].y) + abs(p[0].x-p[1].x)<<'\n';
	
	return 0;
}
