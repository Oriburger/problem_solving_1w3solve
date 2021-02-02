#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetPartialMatch(const string &s)
{
	vector<int> pi(s.size(), 0);
	
	int begin = 1, matched=0;
	while(begin + matched < s.size())
	{
		if(s[begin+matched] == s[matched])
		{
			matched++;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if(matched==0) begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

int kmpSearch(const string &h, const string &n)
{
	if(h.size() < n.size()) return false;

	int begin, matched, cnt=0;
	begin = matched = 0;

	while(begin <= h.size() - n.size())
	{
		if(matched < n.size() && h[begin+matched]==n[matched])
		{
			matched++;
			if(matched==n.size()) cnt++;
		}
		else
		{
			if(matched==0) begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; int ans=0;
	cin>>s;

	vector<int> pi = GetPartialMatch(s);

	for(int i=1; i<=pi[s.size()-1]; i++)
	{
		int temp = kmpSearch(s, s.substr(0, i));
		if(temp < 3) continue;
		ans = max(ans, i);
	}

	if(ans == 0) cout<<-1<<'\n';
	else 
		cout<<s.substr(0, ans)<<'\n';

	return 0;
}
