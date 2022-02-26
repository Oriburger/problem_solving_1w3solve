#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, n;
vector<int> blocks;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	while(cin>>x)
	{
		cin>>n;
		
		x *= 10000000;
		blocks = vector<int>(n);
		for(int i=0; i<n; i++)
			cin>>blocks[i];
		
		sort(blocks.begin(), blocks.end());
		
		bool flag = false;
		for(int i=0; i<n-1; i++)
		{
			int val = *lower_bound(blocks.begin()+i+1, blocks.end(), x - blocks[i]);
			
			if(val + blocks[i] == x)
			{
				cout<<"yes "<<blocks[i]<<' '<<val<<'\n';
				flag = true; break;
			}
		}
		if(!flag) cout<<"danger\n";
	}
	
	return 0;
}
