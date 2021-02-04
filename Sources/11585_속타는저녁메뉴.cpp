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

int kmpSearch(const string &h, const string &n)
{
	int cnt=0;
	vector<int>pi = GetPi(n);

	int begin=0, matched=0;
	while(begin <= h.size() - n.size())
	{
		if(matched < n.size() && h[begin+matched]==n[matched])
		{
			++matched;
			if(matched == n.size()) cnt++;
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

int GetGCD(int a, int b)
{
	if(a%b == 0) return b;

	return GetGCD(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int l, cnt=0, gcd=0;
	string h, n;

	cin>>l;

	for(int j=0; j<2; j++)
		for(int i=0; i<l; i++)
		{
			char c; cin>>c;
			if(j==0) h.push_back(c);
			else n.push_back(c);
		}
	if(h==n) cnt=-1;
	h = h+h;

	cnt += kmpSearch(h, n);
	gcd = GetGCD(l, cnt);

	cout<<cnt/gcd<<'/'<<l/gcd<<'\n';

	return 0;
}
