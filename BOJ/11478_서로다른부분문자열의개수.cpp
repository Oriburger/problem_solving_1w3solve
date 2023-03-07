#include <bits/stdc++.h>
using namespace std;

string s;
int ans = 0;
unordered_set<string> uset;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
  	cin>>s;

	for(int i=0; i<s.size(); i++)
	{
		for(int j=i; j<s.size(); j++)
		{
			string tmp = s.substr(i, j-i+1);
			if(uset.find(tmp) == uset.end())
			{
				ans += 1;
				uset.insert(tmp);
			}
		}
	}
	cout<<ans<<'\n';

  	return 0;
}
