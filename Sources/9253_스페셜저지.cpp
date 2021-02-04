#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> GetPi(const string &s)
{
	vector<int> pi(s.size(), 0);

	int begin = 1, matched = 0;
	while(begin + matched < s.length())
	{
		if(s[begin + matched] == s[matched])
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
	vector<int>pi = GetPi(n);

	int begin=0, matched=0;
	while(begin <= h.size() - n.size())
	{
		if(matched < n.size() && h[begin+matched]==n[matched])
		{
			++matched;
			if(matched == n.size())
				return true;
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
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s1, s2, s3;

	cin>>s1>>s2>>s3;

	if(kmpSearch(s1, s3) && kmpSearch(s2, s3)) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}
