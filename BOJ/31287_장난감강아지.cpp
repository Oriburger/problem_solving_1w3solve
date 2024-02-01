#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, y, x;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k>>s;
	
	y = x = 0;
	for(int i=0; i<min(k, 2000); i++)
	{
		for(auto &c : s)
		{
			if(c == 'U' || c == 'D')
				y += (c == 'U' ? 1 : -1);
			else 
				x += (c == 'R' ? 1 : -1);
			
			if(x == 0 && y == 0)
			{
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
