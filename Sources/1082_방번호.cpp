#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
vector<int> p;
string cache[10][51];

string get_max(string st1, string st2)
{
	if(st1.size()>1 && st1[0]=='0') return st2;
	else if(st2.size()>1 && st2[0]=='0') return st1;

	if(st1.size() == st2.size())
		for(int i=0; i<st1.size(); i++)
		{
			if(st1[i]==st2[i]) continue;
			if(st1[i]>st2[i])	return st1;
			else return st2;
		}

	if(st1.size() > st2.size()) return st1;
	return st2; 
}

string GetAnswer(int idx, int remain)
{
	if(idx >= n || remain < 0) return "";

	string& ret = cache[idx][remain];
	if(ret != "") return ret;

	string tmp, next;
	ret = GetAnswer(idx+1, remain);
	for(int i=1; ; i++)
	{
		if(remain - (p[idx]*i) < 0) break;
		tmp += to_string(idx);
		next = GetAnswer(idx+1, remain - p[idx]*i) + tmp;
		if(next != "") ret = get_max(ret, next);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	p = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>p[i];
	cin>>m;

	string ans;
	ans = GetAnswer(0, m);

	if(ans=="") ans = "0";
	cout<<ans<<'\n';

	return 0;
}
