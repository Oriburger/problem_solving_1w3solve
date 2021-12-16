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
	if(h.size() < n.size()) return false;

	int begin, matched;
	begin = matched = 0;

	vector<int> pi = GetPartialMatch(n);

	while(begin <= h.size() - n.size())
	{
		if(matched < n.size() && h[begin+matched]==n[matched])
		{
			matched++;
			if(matched==n.size()) return true;
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

	string s1, s2, temp;

	cin>>temp>>s2;
	for(int i=0; i<temp.size(); i++)
		if((temp[i]>='a' && temp[i]<='z')
		|| (temp[i]>='A' && temp[i]<='Z'))
			s1.push_back(temp[i]);

	cout<<kmpSearch(s1, s2)<<'\n';

	return 0;
}
