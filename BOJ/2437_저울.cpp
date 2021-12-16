#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> w;

bool is_possible(int k)
{
	for(int i=n-1; i>=0; i--)
	{
		if(k - w[i] < 0) continue;
		k -= w[i];
	}
	return k==0;
}

int get_answer()
{
	int ret = 1;
	if(w[0]!=1) return ret;

	for(int i=0; i<n; i++)
	{
		ret += w[i];
		if(!is_possible(ret)) 
			break;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	w = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>w[i];
	sort(w.begin(), w.end());

	cout<<get_answer()<<'\n';

	return 0;
}
