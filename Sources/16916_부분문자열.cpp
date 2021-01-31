#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetPartialMatch(const string &s)
{
	vector<int> pi(s.length(), 0);
	
	int begin = 1, matched=0;
	while(begin + matched < s.length())
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

bool kmpSearch(const string &h, const string &n)
{
	if(h.length() < n.length()) return false;

	vector<int> pi = GetPartialMatch(n);
	int begin = 0, matched = 0, cnt = 0;

	while(begin <= h.length() - n.length())
	{
		if(matched < n.length() && h[begin+matched] == n[matched])
		{
			matched++;
			if(matched == n.length())
				cnt++;
		}
		else
		{
			if(matched == 0) begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return cnt > 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, p;

	cin>>s>>p;

	cout<<kmpSearch(s, p)<<'\n';

	return 0;
}
