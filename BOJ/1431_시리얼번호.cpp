#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> arr;

int getSum(const string& a)
{
	int ret = 0;
	for(auto& c : a)
		if(c >= '1' && c <= '9') ret += (c-'0');
	return ret;
}

bool comp(const string& a, const string& b)
{
	if(a.size() != b.size()) return a.size() < b.size();
	else 
	{
	 	int sumA = getSum(a);
		int sumB = getSum(b);
		if(sumA + sumB > 0 && sumA != sumB) return getSum(a) < getSum(b);
	}
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		string tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), comp);

	for(auto& s : arr)
		cout<<s<<'\n';

	return 0;
}
