#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull n, m, ans;
vector<ull> arr, back;
unordered_map<ull, int> front;

void DFS(int curr, ull sum, bool flag)
{
	if(sum > m) return;
	if(curr == (!flag ? n/2 : n))
	{
		if(!flag)
		{
			if(front.count(sum)==0) front[sum]=1;
			else front[sum]+=1;
		}
		else back.push_back(sum);
		return;
	}
	DFS(curr+1, sum, flag);
	DFS(curr+1, sum+arr[curr], flag);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	arr = vector<ull>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	DFS(0, 0, false);
	DFS(n/2, 0, true);

	sort(back.begin(), back.end());

	for(auto &p : front)
	{		
		auto q = upper_bound(back.begin(), back.end(), m-p.first);

		if(q != back.begin())
			ans += (q - back.begin()) * p.second; 
	}
	cout<<ans<<'\n';

	return 0;
}
