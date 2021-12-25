#include <bits/stdc++.h>
using namespace std;

int n, ans, total;
vector<int> val;
unordered_map<int, int> umap;

void DFS(int curr, int diff, int sum, bool flag)
{
	if(curr==(!flag ? n/2 : n))
	{
		if(diff < 0) return;
		if(!flag && umap.count(diff)==0) umap[diff]=sum;
		else if(flag && umap.count(diff)>0) ans = max(ans, sum+umap[diff]);
		return;
	}
	DFS(curr+1, diff, sum, flag);
	DFS(curr+1, diff+val[curr], sum+val[curr], flag);
	DFS(curr+1, diff-val[curr], sum+val[curr], flag);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;
		if(n==0) break;

		val = vector<int>(n);
		for(int i=0; i<n; i++)
		{
			cin>>val[i];
			total += val[i];
		}
		DFS(0, 0, 0, false);
		DFS(n/2, 0, 0, true);

		ans = total - ans;
		if(ans<0) ans = 0;
		
		cout<<ans<<'\n';

		total = ans = 0;
		val.clear();
		umap.clear();
	}	

	return 0;
}
