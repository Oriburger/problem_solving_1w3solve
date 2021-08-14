#include <bits/stdc++.h>
using namespace std;

typedef unordered_set<string> uset;

string str; uset check;
int n, cnt[26], ans=0;

string GetRevStr(string s, int a, int b)
{
	reverse(s.begin()+a, s.begin()+b+1);
	return s;
}

void MakeString(string curr, int a, int b)
{
	int mid = (a+b)/2, len = b-a+1;

	if(a >= b)
	{
		if(!check.count(curr))
		{
			check.insert(curr);
			ans++;
		}
		return;
	}

	for(int i=0; i<2; i++)
	{
		if(a <= mid-i)
			MakeString(GetRevStr(curr, a, mid-i), mid-i+1, b);
	
		if(mid-i+1 <= b)
			MakeString(GetRevStr(curr, mid-i+1, b), a, mid-i);

		if(len%2==0) i++;
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		char c; int k;
		cin>>c>>k;
		cnt[c-'a'] = k;
	}

	cin>>str;
	for(int i=0; i<str.size(); i++)
	{
		for(int j=0; (i+j)<=str.size(); j++)
		{
			string s = str.substr(i, j);
			vector<int> tmp(26, 0);
			for(auto &c : s)
				tmp[c-'a']++;

			bool flag = false;
			for(int k=0; k<26; k++)
				if(cnt[k]!=tmp[k])
					flag = true;
			
			if(flag) continue;

			MakeString(s, 0, j-1);
		}
	}

	cout<<ans<<'\n';

	return 0;	
}
