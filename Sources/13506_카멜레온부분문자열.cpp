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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	int ans=0, temp;
	bool flag = false;

	cin>>s;

	vector<int> pi = GetPartialMatch(s);
	temp = pi[s.size()-1];

	while(temp)
	{		
		for(int i=1; i<s.size()-1; i++)
		{
			if(temp == pi[i])
			{
				cout<<s.substr(0, temp)<<'\n';
				flag = true;
				break;
			}
		}
		if(flag) break;
		temp = pi[temp-1];
	}

	if(!flag) cout<<-1<<'\n';

	return 0;
}
