#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int n, m, cache[21][301];
int arr[21][301], path[21][301];
vector<int> ans;

int GetAnswer(int idx, int money)
{
	int& ret = cache[idx][money];
	if(ret != -1) return ret;
	if(money == 0 || idx == m) return ret = 0;
	
	ret = GetAnswer(idx+1, money);
	for(int next = money; next >= 1; next--)
	{
		int tmp = GetAnswer(idx+1, money-next)+arr[idx][next];
		if(tmp <= ret) continue;
		ret = max(ret, tmp);
		path[idx][money]=next;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
	{
		int idx; cin>>idx;
		for(int j=0; j<m; j++)
			cin>>arr[j][idx];
	}
	
	cout<<GetAnswer(0, n)<<'\n';
	
	int total = n;
	for(int i=0; i<m; i++)
	{
		ans.push_back(path[i][total]);
		total -= path[i][total];
	}
	
	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
