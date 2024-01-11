#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, ans, tmp;
bool isTag = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	getline(cin, str);
  
	for(char &c : str)
	{
		if(c == '<' || isTag)
		{
			if(c == '<')
			{
				reverse(tmp.begin(), tmp.end());
				ans += tmp;
				tmp.clear();
			}
			ans.push_back(c);
			isTag = true;	
			if(c == '>') isTag = false;
		}
		else
		{
			if(c == ' ')
			{
				reverse(tmp.begin(), tmp.end());
				ans += tmp;
				ans += c;
				tmp.clear();
			}
			else tmp += c;
		}
	}
	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	
	cout<<ans<<'\n';

	return 0;
}
