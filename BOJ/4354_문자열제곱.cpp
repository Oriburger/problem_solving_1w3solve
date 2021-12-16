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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; 
	vector<int> pi;

	while(1)
	{
		cin>>s;
		if(s==".") break;

		pi = GetPartialMatch(s);

		if(s.length() % (s.length() - pi[s.length()-1]) != 0)
			cout<<1<<'\n';
		else
			cout<<s.length() / (s.length() - pi[s.length()-1])<<'\n';
		
		pi.clear();
	}

	return 0;
}
