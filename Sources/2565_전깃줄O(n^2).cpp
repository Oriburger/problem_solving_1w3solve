#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
using namespace std;

typedef pair<int,int> P;

int n, len;
vector<P> s;
vector<int> cache;

int lis(int start)
{
	int& ret = cache[start];
	
	if(ret != -1) return ret;
	
	ret = 1;
	for(int next=start+1; next<=n; next++)
	{
		if(s[start].second < s[next].second)
			ret = max(ret, lis(next)+1);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	s.push_back({0,0});
	cache.assign(sizeof(int)*n, -1);
	
	for(int i=1; i<=n; i++)
	{
		int a, b;
		cin>>a>>b;
		s.push_back({a, b});
	}	
	sort(s.begin(), s.end());
	
	for(int i=1; i<=n; i++)
		len = max(len, lis(i));
	
	cout<<n-len<<'\n';
	
	return 0;
}
