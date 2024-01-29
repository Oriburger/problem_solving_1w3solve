#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int n, ans; 
string str; 
set<string> myset;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	while(n--)
	{
		cin>>str; 
		
		if(str == "ENTER")
			myset.clear();
		else
		{
			if(myset.count(str) == 0)
			{
				myset.insert(str);
				ans += 1;
			}
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
