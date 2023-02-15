#include <iostream>
#include <stack>
#include <string>
using namespace std;

char st[3] = {'(', '{', '['};
char fin[3] = {')', '}', ']'};
string str; int ans = 0;

inline int getHeadIdx(const char& c)
{
	for(int i=0; i<3; i++) if(c == st[i]) return i;
	return -1;
}

int getScore(int idx)
{
	stack<char> stk;
	int score = 0;
	
	for(int i=0; i<idx; i++)
	{
		const char& c = str[i];
		if(c-'0' >= 0 && c-'0' <= 9) continue;
	
		if(getHeadIdx(c) != -1) stk.push(c);
		else stk.pop();		
	}
	while(!stk.empty())
	{
		score += (1+getHeadIdx(stk.top()));
		stk.pop();
	}
	return score;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>str;
	
	for(int i=0; i<str.length(); i++)
	{
		const char& c = str[i];
		if(c-'0' >= 0 && c-'0' <= 9)
			ans = max(ans, getScore(i));
	}
	cout<<ans<<'\n';
	
	return 0;
}
