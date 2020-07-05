#include <iostream>
#include <vector>
using namespace std;

struct Pos{int y; int x;};

bool Check[101][101];
int count=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<Pos> posLD(4);
	vector<Pos> posRU(4);

	for(int i=0; i<4; i++)
		cin>>posLD[i].x>>posLD[i].y>>posRU[i].x>>posRU[i].y;

	for(int i=1; i<100; i++)
	{
		for(int j=1; j<100; j++)
		{
			for(int k=0; k<4; k++)
			{
				if((posLD[k].y <= i && posRU[k].y >= i+1) 
						&& (posLD[k].x <= j && posRU[k].x >= j+1) )
				{
					count++;
					break;
				}
			}
		}
	}

	cout<<count<<'\n';

	return 0;
}
