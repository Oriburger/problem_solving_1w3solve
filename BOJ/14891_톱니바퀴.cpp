#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int k, score;
vector<int> gear[4], top(4, 0);
vector<int> bIsTurned(4, 0);

inline int GetSideVal(int idx, int dir) 
{ 
	return gear[idx][(top[idx] + 8 + 2 * dir) % 8];
}

int main()
{
	for(int i=0; i<4; i++)
	{
		gear[i] = vector<int>(8);
		for(int j=0; j<8; j++)
			scanf("%1d", &gear[i][j]);
	}
	
	scanf("%d", &k);
	while(k--)
	{
		int idx, dir; 
		scanf("%d %d", &idx, &dir);
		
		idx-=1;
		bIsTurned[idx] = dir;
		
		for(int d=1; ; d*=-1)
		{
			const int fin = (d==1 ? 3 : 0);
			for(int i=idx; i!=fin; i+=d) //오른쪽 먼저
			{
				if(bIsTurned[i]==0) break;
				if(GetSideVal(i, d) != GetSideVal(i+d, -d))
					bIsTurned[i+d] = bIsTurned[i]*-1;
			}
			if(d==-1) break;
		}
		for(int i=0; i<4; i++)
		{
			if(bIsTurned[i]==0) continue;
			top[i] = (top[i] - bIsTurned[i] + 8) % 8;
		}
		bIsTurned = vector<int>(4, 0);
	}
	
	for(int i=0; i<4; i++)
	{
		if(gear[i][top[i]]==0) continue;
		score += (1<<i);
	}
	printf("%d\n", score);
	
	return 0;
}
