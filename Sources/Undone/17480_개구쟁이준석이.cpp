#include <bits/stdc++.h>
using namespace std;

typedef unordered_set<string> uset;

string str; uset check;
int n, cnt[26], ans=0;

void Debug(string str)
{
	cout<<str<<'\n';
	cout<<str.substr(0, str.size()/2)<<" / "<<str.substr(str.size()/2)<<'\n';
	if(str.size()%2==1) cout<<str.substr(0, str.size()/2+1)<<" / "<<str.substr(str.size()/2+1)<<'\n';
}

void MakeString(string body, string ptA, string ptB)
{
	if(ptA.size()==1 || ptB.size()==1)
	{
		body = body + ptA + ptB;
		if(!check.count(body))
		{
			cout<<body<<'\n';
			ans++;
			check.insert(body);
		}
		return;
	}

	Debug(ptA);
	Debug(ptB);
	
	reverse(ptA.begin(), ptA.end());
	MakeString(body+ptA, ptB.substr(0, ptB.size()/2), ptB.substr(ptB.size()/2));
	if(ptB.size()%2==1) MakeString(body+ptA, ptB.substr(0, ptB.size()/2+1), ptB.substr(ptB.size()/2+1));
	reverse(ptA.begin(), ptA.end());

	reverse(ptB.begin(), ptB.end());
	MakeString(body+ptB, ptA.substr(0, ptA.size()/2), ptA.substr(ptA.size()/2));
	if(ptA.size()%2==1) MakeString(body+ptB, ptA.substr(0, ptA.size()/2+1), ptA.substr(ptA.size()/2+1));
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
		for(int j=0; j<str.size(); j++)
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

			cout<<"S : "<<s<<'\n';

			MakeString("", s.substr(0, s.size()/2), s.substr(s.size()/2));
			if(s.size()%2==1) MakeString("", s.substr(0, s.size()/2+1), s.substr(s.size()/2+1));
		}
	}

	cout<<ans<<'\n';

	return 0;	
}
