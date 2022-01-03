#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
vector<int> arr;
vector<bool> check;

int GetNextNum(int st)
{
	for(int i=st; i<=n; i++)
		if(!check[i]) return i;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;

	while(t--)
	{
		cin>>n;

		ans = 0;
		arr = vector<int>(n);
		check = vector<bool>(n+1, false);
		for(int i=0; i<n; i++)
			cin>>arr[i];

		sort(arr.begin(), arr.end());

		int target = 1;
		for(const auto &k : arr)
		{
			if(k <= n && !check[k])
			{
				check[k] = true;
				continue;
			}

			target = GetNextNum(target);
			if(target == -1) break;
			else if(k >= (target*2+1)) 
			{
				check[target]=true;
				ans += 1;
			}
		}

		if(GetNextNum(target)!=-1) cout<<-1<<'\n';
		else cout<<ans<<'\n';
	}

	return 0;
}
