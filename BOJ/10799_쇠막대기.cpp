#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string str;
vector<int> cnt;
int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>str;
	
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='(')
		{
			if(i!=str.size()-1 && str[i+1]==')')
			{
				for(auto &p : cnt)
					p+=1;
				i += 1;
			}
			else 
				cnt.push_back(0);
		}
		else
		{
			ans += (cnt.back()+1);
			cnt.pop_back();
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
