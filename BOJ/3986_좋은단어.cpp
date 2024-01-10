#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n, ans = 0;
vector<string> str;

bool isAnswer(string s)
{
	if(s.size() % 2 == 1) return false;

	stack<char> stk;
	for(int i=0; i<s.size(); i++)
	{
		if(!stk.empty() && stk.top() == s[i])
		{
			stk.pop();
			continue;
		}
		stk.push(s[i]);
	}
	return stk.size() == 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	str.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>str[i];
		ans += isAnswer(str[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}
