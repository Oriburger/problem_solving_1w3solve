#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetPartialMatch(const vector<int> &s)
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

bool kmpSearch(const vector<int> &h, const vector<int> &n)
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

	int n, k, m;
	vector<vector<int> > arr;

	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		cin>>m;

		vector<int> temp(m);
		for(int j=0; j<m; j++)
			cin>>temp[j];
		
		arr.push_back(temp);
	}

	for(int len = k; len <= arr[0].size(); len++)
	{
		for(int i=0; i<arr[0].size(); i++)
		{
			if(i+len > arr[0].size()) break;

			vector<int> temp1, temp2(len);
			int idx=len-1;
			for(int j=i; j<i+len; j++)
			{
				temp1.push_back(arr[0][j]);
				temp2[idx--]=arr[0][j];
			}

			bool flag = true;
			for(int j=1; j<n; j++)
			{
				if(!kmpSearch(arr[j], temp1)
					&& !kmpSearch(arr[j], temp2))
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				cout<<"YES"<<'\n';
				return 0;
			}
		}
	}
	cout<<"NO\n";

	return 0;
}
